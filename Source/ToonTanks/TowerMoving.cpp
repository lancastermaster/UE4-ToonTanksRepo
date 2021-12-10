// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerMoving.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"
#include "Math/UnrealMathUtility.h"
#include "TimerManager.h"
#include "GameFramework/FloatingPawnMovement.h"

//add a patrol function here so that enemies aren't static

void ATowerMoving::BeginPlay()
{
    Super::BeginPlay();

    StartLocation = GetActorLocation();
    //GetWorldTimerManager().SetTimer(PatrolRateTimerHandler, this, &ATowerMoving::GeneratePatrolOffset, PatrolRate, true);
}

void ATowerMoving::Tick(float DeltaTime)
{
    
}

void ATowerMoving::RotateBase(FVector LookAtTarget)
{
	FVector ToTarget = LookAtTarget - BaseMesh->GetComponentLocation();
	FRotator LookAtRotation = FRotator(0.f, ToTarget.Rotation().Yaw, 0.f);
    BaseMesh->SetWorldRotation(LookAtRotation);
}

/*float ATowerMoving::CalculateOffsets()
{
    FVector EndLocation = Tank->GetActorLocation() - GetActorLocation();

    XOffset = FMath::Clamp(EndLocation.X, -1.f, 1.f);
    return XOffset;
}

void ATowerMoving::GeneratePatrolOffset()
{
    PatrolOffset = float(FMath::RandRange(-1,1));
}

void ATowerMoving::PursuePlayer(float Offset)
{
    FVector DeltaLocation = FVector::ZeroVector;

    DeltaLocation.X = Offset * Speed * UGameplayStatics::GetWorldDeltaSeconds(this);

    AddActorLocalOffset(DeltaLocation, true);
}

void ATowerMoving::Patrol(float Offset)
{
    FVector DeltaLocation = FVector::ZeroVector;

    DeltaLocation.X = Offset * Speed * UGameplayStatics::GetWorldDeltaSeconds(this);

    AddActorLocalOffset(DeltaLocation, true);
}*/

bool ATowerMoving::InSightRange()
{
    if(Tank)
    {
        float Distance = FVector::Dist(GetActorLocation(), Tank->GetActorLocation());

        if(Distance <= SightRange)
        {
            return true;
        }
    }
    return false;
}