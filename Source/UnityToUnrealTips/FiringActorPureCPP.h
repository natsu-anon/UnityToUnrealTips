// Have a nice day!

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FiringActorPureCPP.generated.h"

UCLASS()
class UNITYTOUNREALTIPS_API AFiringActorPureCPP : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFiringActorPureCPP();

	UPROPERTY(EditAnywhere)
	TSubclassOf<class ABasicProjectile> ProjectileClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(UIMin=0.f, UIMax=3.f))
	float FirePeriod;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(UIMin=0.f))
	float ProjectileSpeed;

protected:

	float Timer;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:

	void FireProjectile() const;

};
