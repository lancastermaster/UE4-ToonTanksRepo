// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerMoving.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"
#include "Math/UnrealMathUtility.h"
#include "TimerManager.h"

//add a patrol function here so that enemies aren't static

void ATowerMoving::BeginPlay()
{
    Super::BeginPlay();

    StartLocation = GetActorLocation();
    GetWorldTimerManager().SetTimer(PatrolRateTimerHandler, this, &ATowerMoving::GeneratePatrolOffset, PatrolRate, true);
}

void ATowerMoving::Tick(float DeltaTime)
{
    if(Tank == nullptr)return;

    float Distance = FVector::Dist(GetActorLocation(), Tank->GetActorLocation());
    float DistanceFromPost = FVector::Dist(GetActorLocation(), StartLocation);

    if(InSightRange()&& Distance >= AcceptanceRadius)
    {
        Rotate(Tank->GetActorLocation());
        PursuePlayer(-CalculateOffsets());
    }

    if(InSightRange()&& Distance < AcceptanceRadius)
    {
        Rotate(Tank->GetActorLocation());
        PursuePlayer(CalculateOffsets());
    }

    if(!InSightRange())
    {
            Patrol(PatrolOffset);
    }
}

void ATowerMoving::Rotate(FVector LookAtTarget)
{
    FVector ToTarget = LookAtTarget - GetActorLocation();
	FRotator LookAtRotation = FRotator(0.f, ToTarget.Rotation().Yaw, 0.f);

    this->SetActorRotation(LookAtRotation);
}

float ATowerMoving::CalculateOffsets()
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

    DeltaLocation.X = Offset * speed * UGameplayStatics::GetWorldDeltaSeconds(this);

    AddActorLocalOffset(DeltaLocation, true);
}

void ATowerMoving::Patrol(float Offset)
{
    FVector DeltaLocation = FVector::ZeroVector;

    DeltaLocation.X = Offset * speed * UGameplayStatics::GetWorldDeltaSeconds(this);

    AddActorLocalOffset(DeltaLocation, true);
}

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