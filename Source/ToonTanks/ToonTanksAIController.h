// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ToonTanksAIController.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API AToonTanksAIController : public AAIController
{
	GENERATED_BODY()
	
	
public:
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

private:
	class APawn* PlayerPawn;
	class ATowerMoving* EnemyTank;
};
