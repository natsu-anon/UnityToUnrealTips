// Have a nice day!

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FireProjectileComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNITYTOUNREALTIPS_API UFireProjectileComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UFireProjectileComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(UIMin=0.f))
	float ProjectileSpeed;


public:	

	UFUNCTION(BlueprintCallable)
	void Fire(TSubclassOf<class ABasicProjectile> ProjectileClass, const FVector& Dir);
};
