// Have a nice day!


#include "CameraDriver.h"

// Sets default values for this component's properties
UCameraDriver::UCameraDriver()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	TickScale = 50.f;
	PitchRange =89.f;
}



// Called every frame
void UCameraDriver::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	const FRotator TickInput = DeltaTime * TickScale * ConsumeInput();
	if (!UpdatedComponent)
	{
		return;
	}
	FRotator NewRotation  = UpdatedComponent->GetRelativeRotation() + TickInput;
	NewRotation.Pitch = FMath::ClampAngle(NewRotation.Pitch, -PitchRange, PitchRange);
	NewRotation.Roll = 0.f;
	UpdatedComponent->SetRelativeRotation(NewRotation);
}

void UCameraDriver::AddPitch(const float Value)
{
	Input.Pitch += Value;
}

void UCameraDriver::AddYaw(const float Value)
{
	Input.Yaw += Value;
}

const FRotator UCameraDriver::ConsumeInput()
{
	const FRotator Res = Input;
	Input = FRotator::ZeroRotator;
	return Res;
}

