// Fill out your copyright notice in the Description page of Project Settings.


#include "Fighter.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Logging/StructuredLog.h"

// Sets default values
AFighter::AFighter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void AFighter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AFighter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AFighter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	const APlayerController* PlayerController = static_cast<APlayerController*>(GetController());
	const ULocalPlayer* LocalPlayer = PlayerController->GetLocalPlayer();

	UEnhancedInputLocalPlayerSubsystem* LocalSubsystem = LocalPlayer->GetSubsystem<
		UEnhancedInputLocalPlayerSubsystem>();

	LocalSubsystem->ClearAllMappings();
	LocalSubsystem->AddMappingContext(MovementMappingContext, 1);
	// LocalSubsystem->AddMappingContext(AttackMappingContext, 1);

	UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	Input->BindAction(MovementInputAction, ETriggerEvent::Triggered, this, &AFighter::StartMovement);
	Input->BindAction(AttackInputAction, ETriggerEvent::Triggered, this, &AFighter::StartAttack);
}

void AFighter::StartMovement(const FInputActionValue& Value)
{
	const FVector2D MovementAxis = Value.Get<FVector2D>();
	
	FString ValueString = MovementAxis.ToString();
	// This then will always trigger if the player were holding W button, we only want this to trigger once
	// So probably the best course of action is set the jump action to pressed
	// Actually this is good
	if (MovementAxis.X > 0.0f)
	{
		Jump();
	}
	
	if (MovementAxis.Y > 0.0f || MovementAxis.Y < 0.0f)
	{
		AddMovementInput(FVector::RightVector, MovementAxis.Y);
	}
	// UE_LOG(LogTemp, Log, TEXT("Moving: %s"), *ValueString);
}

void AFighter::StartAttack(const FInputActionInstance &Instance)
{
	UE_LOGFMT(LogTemp, Log, "Attacking");
}
