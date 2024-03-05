// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"

#include "Tank.h"
#include "Kismet/GameplayStatics.h"

void ATower::BeginPlay()
{
	Super::BeginPlay();
	PlayerTank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
	GetWorldTimerManager().SetTimer(FireTimerHandle, this, &ATower::CanFire, FireRate, true);
}

bool ATower::IsPlayerInRange()const 
{
	if(PlayerTank)
	{
		float Distance = FVector::Dist(GetActorLocation(), PlayerTank->GetActorLocation());
		if(Distance <= FireRange)
		{
			return true;
		}
	}
	return false;
}

void ATower::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if(IsPlayerInRange())
	{
		RotateTurret(PlayerTank->GetActorLocation());
	}
}

void ATower::HandleDestruction()
{
	Super::HandleDestruction();
	Destroy();
}

void ATower::CanFire()
{
	if(!PlayerTank)
	{
		return;
	}
	if(IsPlayerInRange() && PlayerTank->IsAlive())
	{
		Fire();
	}
}
