// Have a nice day!

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CountdownComponent.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCountdownDelegate);
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNITYTOUNREALTIPS_API UCountdownComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCountdownComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bRepeat;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(UIMin=0.f))
	float CountdownTime;

	UPROPERTY(BlueprintAssignable)
	FCountdownDelegate OnFinish;

protected:

	float Timer;
	bool bCountdown;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
