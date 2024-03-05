// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()
public:
	ATank();
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	virtual void HandleDestruction() override;

	bool IsAlive()const;
	
	APlayerController* GetTankPlayerController()const;
protected:
	void Move(float Value);
	void Turn(float Value);
	void FireAction();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	APlayerController* TankPlayerController;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float MoveSpeed = 300.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float TurnSpeed = 50.f;
	
	UPROPERTY(EditAnywhere, Category = "Components")
	class USpringArmComponent* SpringArmComp;

	UPROPERTY(EditAnywhere, Category = "Components")
	class UCameraComponent* CameraComp;

	bool bIsAlive;
};
