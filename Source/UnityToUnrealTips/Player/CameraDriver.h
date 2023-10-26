// Have a nice day!

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CameraDriver.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNITYTOUNREALTIPS_API UCameraDriver : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCameraDriver();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USceneComponent* UpdatedComponent;

	UPROPERTY(EditAnywhere, meta=(UIMin=0.f))
	float TickScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(UIMin=0.f, UIMax=89.9f))
	float PitchRange;

protected:

	FRotator Input;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void AddPitch(const float Value);

	void AddYaw(const float Value);

protected:

	const FRotator ConsumeInput();
};
