// Have a nice day!


#include "CountdownComponent.h"

// Sets default values for this component's properties
UCountdownComponent::UCountdownComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	bRepeat = true;
	CountdownTime = 0.5f;
}


// Called when the game starts
void UCountdownComponent::BeginPlay()
{
	Super::BeginPlay();

	bCountdown = true;
	Timer  = CountdownTime;
	
}


// Called every frame
void UCountdownComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (bCountdown)
	{
		Timer -= DeltaTime;
		if (Timer < 0.f)
		{
			OnFinish.Broadcast();
			if (bRepeat)
			{
				Timer = CountdownTime;
			}
			else
			{
				bCountdown = false;
			}
		}
	}
}

