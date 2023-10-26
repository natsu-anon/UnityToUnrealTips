// Have a nice day!


#include "FiringActorBlended.h"
#include "FireProjectileComponent.h"
#include "BasicProjectile.h"

// Sets default values
AFiringActorBlended::AFiringActorBlended()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ProjectileClass = ABasicProjectile::StaticClass();
	FirePeriod = 0.5f;
	FireComponent = CreateDefaultSubobject<UFireProjectileComponent>(TEXT("FireProjectileComponent"));
}

// Called when the game starts or when spawned
void AFiringActorBlended::BeginPlay()
{
	Super::BeginPlay();
	Timer = FirePeriod;

	
}

// Called every frame
void AFiringActorBlended::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Timer -= DeltaTime;
	if (Timer < 0.f)
	{
		Timer = FirePeriod;
		FireComponent->Fire(ProjectileClass, GetActorForwardVector());
	}
}

