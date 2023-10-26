// Have a nice day!

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BasicProjectile.generated.h"

UCLASS()
class UNITYTOUNREALTIPS_API ABasicProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABasicProjectile();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(UImin=0.f))
	float Lifetime;

	FVector Velocity;

protected:

	float Timer;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
