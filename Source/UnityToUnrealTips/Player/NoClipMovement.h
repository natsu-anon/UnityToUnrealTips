// Have a nice day!

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "NoClipMovement.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNITYTOUNREALTIPS_API UNoClipMovement : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UNoClipMovement();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USceneComponent* UpdatedComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USceneComponent* BearingComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TopSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Acceleration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Friction;

protected:

	FVector Input;
	FVector Velocity;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void AddInput(const FVector& Value);

protected:

	const FVector ConsumeInput();

	void ApplyFriction(const float DeltaTime);

	const FVector Accelerate(const float DeltaTime, const FVector& Dir) const;
};
