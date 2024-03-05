// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

class UParticleSystem;
class USoundBase;
class UCameraShakeBase;

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	ABasePawn();

	virtual void HandleDestruction();

protected:
	void RotateTurret(const FVector& Target)const;

	void Fire();
	
	UPROPERTY(EditAnywhere, Category = "Components")
	class UCapsuleComponent* CapsuleComp;
	
	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* HullMesh;
	
	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* TurretMesh;
	
	UPROPERTY(EditAnywhere, Category = "Components")
	USceneComponent* ProjectileSpawnPoint;

	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	TSubclassOf<class ABaseProjectile> ProjectileClass;

	UPROPERTY(EditAnywhere)
	UParticleSystem* DeathParticles;

	UPROPERTY(EditAnywhere)
	USoundBase* DeathSound;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UCameraShakeBase> DeathCameraShakeClass;
};
