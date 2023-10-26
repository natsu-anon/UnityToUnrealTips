// Have a nice day!


#include "BasicProjectile.h"

// Sets default values
ABasicProjectile::ABasicProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Lifetime = 3.f;
	Velocity = FVector::ZeroVector;
}

// Called when the game starts or when spawned
void ABasicProjectile::BeginPlay()
{
	Super::BeginPlay();
	Timer = Lifetime;
	
}

// Called every frame
void ABasicProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (Timer <= 0.f)
	{
		Destroy();
	}
	Timer -= DeltaTime;
	AddActorWorldOffset(Velocity * DeltaTime);

}

