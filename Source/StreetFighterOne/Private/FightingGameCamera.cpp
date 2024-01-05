// Fill out your copyright notice in the Description page of Project Settings.


#include "FightingGameCamera.h"

#include "Logging/StructuredLog.h"

AFightingGameCamera::AFightingGameCamera()
{
	SetActorLocation(FVector(-220.0f, 0.0f, 310.0f));
	UE_LOGFMT(LogTemp, Log, "Camera Initiated");
}
