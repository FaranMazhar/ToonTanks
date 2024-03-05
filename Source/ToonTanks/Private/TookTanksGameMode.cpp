// Fill out your copyright notice in the Description page of Project Settings.


#include "TookTanksGameMode.h"
#include "Tank.h"
#include "ToonTanksPlayerController.h"
#include "Tower.h"
#include "Kismet/GameplayStatics.h"

void ATookTanksGameMode::HandleGameStart()
{
	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
	ToonTanksPlayerController = Cast<AToonTanksPlayerController>(
		UGameplayStatics::GetPlayerController(this, 0));
	TargetTowers = GetTargetTowerCount();
	
	if(ToonTanksPlayerController)
	{
		StartGame();
		ToonTanksPlayerController->SetPlayerEnabledState(false);

		FTimerHandle PlayerEnableTimerHandle;
		FTimerDelegate PlayerEnableTimerDelegate = FTimerDelegate::CreateUObject(
			ToonTanksPlayerController,
			&AToonTanksPlayerController::SetPlayerEnabledState, true
			);

		GetWorldTimerManager().SetTimer(PlayerEnableTimerHandle, PlayerEnableTimerDelegate, StartDelay, false);
	}
}

void ATookTanksGameMode::ActorDied(AActor* DeadActor)
{
	if(DeadActor == Tank)
	{
		Tank->HandleDestruction();
		if(ToonTanksPlayerController)
		{
			ToonTanksPlayerController->SetPlayerEnabledState(false);
			GameOver(false);
		}
	}
	else if(ATower* DestroyedTower =  Cast<ATower>(DeadActor))
	{
		DestroyedTower->HandleDestruction();
		TargetTowers--;
		if(TargetTowers <= 0)
		{
			GameOver(true);
		}
	}
}

void ATookTanksGameMode::BeginPlay()
{
	Super::BeginPlay();

	HandleGameStart();
}

int32 ATookTanksGameMode::GetTargetTowerCount()
{
	TArray<AActor*> AllTowers;
	UGameplayStatics::GetAllActorsOfClass(this, ATower::StaticClass(), AllTowers);
	return AllTowers.Num();
}
