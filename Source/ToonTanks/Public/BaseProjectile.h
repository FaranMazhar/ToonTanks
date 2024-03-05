// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseProjectile.generated.h"

class UParticleSystem;
class UParticleSystemComponent;
class USoundBase;

UCLASS()
class TOONTANKS_API ABaseProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	ABaseProjectile();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* ProjectileMesh;

	UPROPERTY(EditAnywhere)
	class UProjectileMovementComponent* ProjectileMovementComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float BaseDamage = 50.0f;

	UPROPERTY(VisibleAnywhere)
	UParticleSystemComponent* ProjectileTrailParticles;
	
	UPROPERTY(EditAnywhere)
	UParticleSystem* HitParticles;

	UPROPERTY(EditAnywhere)
	USoundBase* LaunchSound;
	UPROPERTY(EditAnywhere)
	USoundBase* HitSound;
};
