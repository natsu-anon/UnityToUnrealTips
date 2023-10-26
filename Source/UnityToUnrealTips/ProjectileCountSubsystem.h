// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "ProjectileCountSubsystem.generated.h"

/**
 * See https://docs.unrealengine.com/5.2/en-US/API/Runtime/Engine/Subsystems/USubsystem/ 
 * https://docs.unrealengine.com/5.2/en-US/API/Runtime/Engine/Subsystems/UWorldSubsystem/ 
 * https://docs.unrealengine.com/5.2/en-US/API/Runtime/Engine/Subsystems/UTickableWorldSubsystem/ 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FProjectileCountNumber, int, Number);
UCLASS()
class UNITYTOUNREALTIPS_API UProjectileCountSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

	UPROPERTY(BlueprintAssignable)
	FProjectileCountNumber OnNewCount;

protected:

	int NumProjectiles;

public:

	virtual void Initialize(FSubsystemCollectionBase& Collections) override;
	
	UFUNCTION(BlueprintCallable)
	void AddNumProjectiles(const int Value);

	UFUNCTION(BlueprintCallable)
	const int GetNumProjectiles() const;
};
