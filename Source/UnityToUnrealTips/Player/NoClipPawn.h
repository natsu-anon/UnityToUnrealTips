// Have a nice day!

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "NoClipPawn.generated.h"

// This is kinda quick & dirty
UCLASS()
class UNITYTOUNREALTIPS_API ANoClipPawn : public APawn
{
	GENERATED_BODY()

public:
	ANoClipPawn();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UCameraDriver* CameraDriver;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UNoClipMovement* Movement;

protected:

	FVector Input;

public:	

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:

	void MoveForward(float Value);

	void MoveRight(float Value);

	void LookUp(float Value);

	void LookRight(float Value);
};
