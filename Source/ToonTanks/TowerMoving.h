// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tower.h"
#include "TowerMoving.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATowerMoving : public ATower
{
	GENERATED_BODY()

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	void Rotate(FVector LookAtTarget);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//add a patrol function here so that enemies aren't static
	void Patrol(float Offset);

	void GeneratePatrolOffset();
	
private:
	UPROPERTY(EditAnywhere, Category = "Movement")
	float speed;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float AcceptanceRadius = 400.f;

	UPROPERTY(EditAnywhere, Category = "Combat")
	float SightRange;

	FVector StartLocation;

	void PursuePlayer(float Offset);

	float CalculateOffsets();

	bool InSightRange();

	float XOffset;
	float PatrolOffset;

	FTimerHandle PatrolRateTimerHandler;

	UPROPERTY(EditAnywhere, Category = "Combat")
	float PatrolRate = 2.f;
};
