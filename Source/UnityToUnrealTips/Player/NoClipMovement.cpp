// Have a nice day!


#include "NoClipMovement.h"

// Sets default values for this component's properties
UNoClipMovement::UNoClipMovement()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	TopSpeed = 500.f;
	Acceleration = 1800.f;
	Friction = 1200.f;
}

// Called every frame
void UNoClipMovement::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	const FVector TickInput = ConsumeInput();
	if (!UpdatedComponent)
	{
		return;
	}
	const FVector Pos0 = UpdatedComponent->GetComponentLocation();
	ApplyFriction(DeltaTime);
	UpdatedComponent->AddWorldOffset(Accelerate(DeltaTime, TickInput));
	Velocity = (UpdatedComponent->GetComponentLocation() - Pos0) / DeltaTime;
}

void UNoClipMovement::AddInput(const FVector& Value)
{
	Input += Value;
}

const FVector UNoClipMovement::ConsumeInput()
{
	const FVector Res =  BearingComponent ? BearingComponent->GetComponentQuat() * Input : Input;
	Input = FVector::ZeroVector;
	return Res;
}

void UNoClipMovement::ApplyFriction(const float DeltaTime)
{
	const float Speed = Velocity.Size();
	if (FMath::IsNearlyZero(Speed))
	{
		return;
	}
	const float Decceleration = DeltaTime * Friction;
	Velocity = FMath::Max(Speed - Decceleration, 0.f) * Velocity.GetSafeNormal();
}

const FVector UNoClipMovement::Accelerate(const float DeltaTime, const FVector& Dir) const
{
	FVector Res = Acceleration * Dir + Velocity;
	if (Res.SizeSquared() > TopSpeed * TopSpeed)
	{
		Res = TopSpeed * Dir.GetSafeNormal();
	}
	return DeltaTime * Res;
}

