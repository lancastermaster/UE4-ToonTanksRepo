// Fill out your copyright notice in the Description page of Project Settings.


#include "ToonTanksAIController.h"
#include "Kismet/GameplayStatics.h"

void ToonTanksAIController::BeginPlay()
{
    Super::BeginPlay();
    APawn* PlayerPawn = UGamplayStatics::GetPlayerPawn(GetWorld(), 0);

    SetFocus(PlayerPawn);
}