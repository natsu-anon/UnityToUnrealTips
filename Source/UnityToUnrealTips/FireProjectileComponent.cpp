// Have a nice day!


#include "FireProjectileComponent.h"
#include "BasicProjectile.h"
#include "ProjectileCountSubsystem.h"

// Sets default values for this component's properties
UFireProjectileComponent::UFireProjectileComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	ProjectileSpeed = 800.f;
}

// Assume Dir is a normal vector
void UFireProjectileComponent::Fire(TSubclassOf<ABasicProjectile> ProjectileClass, const FVector& Dir)
{
	UWorld* World = GetWorld();
	if (ProjectileClass && World)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.Instigator = GetOwner()->GetInstigator();
		ABasicProjectile* Projectile = World->SpawnActor<ABasicProjectile>(ProjectileClass, GetOwner()->GetActorLocation(), FRotator::ZeroRotator, SpawnParams);
		if (Projectile)
		{
			Projectile->Velocity = ProjectileSpeed * Dir;
			GetWorld()->GetSubsystem<UProjectileCountSubsystem>()->AddNumProjectiles(1);
		}
	}
}

