// Have a nice day!


#include "FiringActorPureCPP.h"
#include "ProjectileCountSubsystem.h"
#include "BasicProjectile.h"

// Sets default values
AFiringActorPureCPP::AFiringActorPureCPP()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ProjectileClass = ABasicProjectile::StaticClass();
	ProjectileSpeed = 800.f;
	FirePeriod = 0.5f;
}

// Called when the game starts or when spawned
void AFiringActorPureCPP::BeginPlay()
{
	Super::BeginPlay();
	Timer = FirePeriod;
	
}

// Called every frame
void AFiringActorPureCPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Timer -= DeltaTime;
	if (Timer < 0.f)
	{
		FireProjectile();
		Timer = FirePeriod;
	}

}

void AFiringActorPureCPP::FireProjectile() const
{
	UWorld* World = GetWorld();
	if (ProjectileClass && World)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.Instigator = GetInstigator();
		ABasicProjectile* Projectile = World->SpawnActor<ABasicProjectile>(ProjectileClass, GetActorLocation(), FRotator::ZeroRotator, SpawnParams);
		if (Projectile)
		{
			Projectile->Velocity = ProjectileSpeed * GetActorForwardVector();
			GetWorld()->GetSubsystem<UProjectileCountSubsystem>()->AddNumProjectiles(1);
		}
	}
}

