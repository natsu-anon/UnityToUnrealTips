// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileCountSubsystem.h"

void UProjectileCountSubsystem::Initialize(FSubsystemCollectionBase& Collections)
{
	Super::Initialize(Collections);
	NumProjectiles = 0;
}

void UProjectileCountSubsystem::AddNumProjectiles(const int Value)
{
	NumProjectiles += Value;
	OnNewCount.Broadcast(NumProjectiles);
}

const int UProjectileCountSubsystem::GetNumProjectiles() const
{
	return NumProjectiles;
}
