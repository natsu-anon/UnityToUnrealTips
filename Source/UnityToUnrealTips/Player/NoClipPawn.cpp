// Have a nice day!


#include "NoClipPawn.h"
#include "Camera/CameraComponent.h"
#include "CameraDriver.h"
#include "NoClipMovement.h"

// Sets default values
ANoClipPawn::ANoClipPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	RootComponent = Camera;

	CameraDriver = CreateDefaultSubobject<UCameraDriver>(TEXT("CameraDriver"));
	Movement = CreateDefaultSubobject<UNoClipMovement>(TEXT("Movement"));

}

// Called to bind functionality to input
void ANoClipPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &ANoClipPawn::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ANoClipPawn::MoveRight);
	PlayerInputComponent->BindAxis("LookUp", this, &ANoClipPawn::LookUp);
	PlayerInputComponent->BindAxis("LookRight", this, &ANoClipPawn::LookRight);
}

void ANoClipPawn::MoveForward(float Value)
{
	Movement->AddInput(Value * FVector::ForwardVector);
}

void ANoClipPawn::MoveRight(float Value)
{
	Movement->AddInput(Value * FVector::RightVector);
}

void ANoClipPawn::LookUp(float Value)
{
	CameraDriver->AddPitch(Value);
}

void ANoClipPawn::LookRight(float Value)
{
	CameraDriver->AddYaw(Value);
}

