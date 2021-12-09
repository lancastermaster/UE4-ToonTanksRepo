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

	//add a patrol function here so that enemies aren't static
	
private:
	UPROPERTY(EditAnywhere, Category = "Movement")
	float speed;

	UPROPERTY(EditAnywhere, Category = "Combat")
	float SightRange;

	void PursuePlayer(float Offset);

	float CalculateOffsets();

	bool InSightRange();

	float XOffset;
	float YawOffset;
};
