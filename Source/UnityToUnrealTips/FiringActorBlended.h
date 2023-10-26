// Have a nice day!

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FiringActorBlended.generated.h"

UCLASS()
class UNITYTOUNREALTIPS_API AFiringActorBlended : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFiringActorBlended();

	UPROPERTY(EditAnywhere)
	TSubclassOf<class ABasicProjectile> ProjectileClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(UIMin=0.f, UIMax=3.f))
	float FirePeriod;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class UFireProjectileComponent* FireComponent;

protected:

	float Timer;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
