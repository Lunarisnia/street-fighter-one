// Fill out your copyright notice in the Description page of Project Settings.


#include "FightingGameMode.h"

#include "FightingGameCamera.h"
#include "Logging/StructuredLog.h"

AFightingGameMode::AFightingGameMode()
{
	PrimaryActorTick.bCanEverTick = false;
	
	UE_LOGFMT(LogTemp, Log, "GameMode Initiated.");
}

void AFightingGameMode::StartPlay()
{
	Super::StartPlay();
	if (UWorld* World = GetWorld())
	{
		AFightingGameCamera* FightingGameCamera = World->SpawnActor<AFightingGameCamera>();
		World->GetFirstPlayerController()->SetViewTarget(FightingGameCamera);
	} else
	{
		UE_LOGFMT(LogTemp, Error, "Failed to GetWorld");
	}
	
	UE_LOGFMT(LogTemp, Log, "StartPlay Called");
}
