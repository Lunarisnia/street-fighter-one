// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "FightingGameMode.generated.h"

/**
 * 
 */
UCLASS()
class STREETFIGHTERONE_API AFightingGameMode : public AGameMode
{
	GENERATED_BODY()
public:
	AFightingGameMode();

	virtual void StartPlay() override;
};
