// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tower.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATower : public ABasePawn
{
	GENERATED_BODY()	
public:
	virtual void BeginPlay() override;
	bool IsPlayerInRange()const;
	virtual void Tick(float DeltaSeconds) override;

	virtual void HandleDestruction() override;
protected:

	void CanFire();

	UPROPERTY()
	class ATank* PlayerTank;
	
	UPROPERTY(EditDefaultsOnly)
	float FireRange = 1000.f;

	FTimerHandle FireTimerHandle;
	float FireRate = 2.f;
};
