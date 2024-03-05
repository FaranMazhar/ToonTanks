// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TookTanksGameMode.generated.h"

class AToonTanksPlayerController;
class ATank;
/**
 * 
 */
UCLASS()
class TOONTANKS_API ATookTanksGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	void HandleGameStart();
	void ActorDied(AActor* DeadActor);

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent)
	void StartGame();
	UFUNCTION(BlueprintImplementableEvent)
	void GameOver(bool bWonGame);

	int32 GetTargetTowerCount();
	
	UPROPERTY()
	ATank* Tank;
	
	UPROPERTY()
	AToonTanksPlayerController* ToonTanksPlayerController;
	
	UPROPERTY(EditAnywhere)
	float StartDelay = 4.0f;

	UPROPERTY()
	int32 TargetTowers;

};
