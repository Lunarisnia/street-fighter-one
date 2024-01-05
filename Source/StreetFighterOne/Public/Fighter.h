// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Fighter.generated.h"

struct FInputActionValue;
class UInputAction;
class UInputMappingContext;
struct FInputActionInstance;

UCLASS()
class STREETFIGHTERONE_API AFighter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFighter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere)
	UInputMappingContext* MovementMappingContext;

	UPROPERTY(EditAnywhere)
	UInputAction* MovementInputAction;

	UPROPERTY(EditAnywhere)
	UInputAction* AttackInputAction;

	void StartMovement(const FInputActionValue& Value);
	void StartAttack(const FInputActionInstance& Instance);
};
