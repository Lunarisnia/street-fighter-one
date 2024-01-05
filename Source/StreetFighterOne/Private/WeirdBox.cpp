// Fill out your copyright notice in the Description page of Project Settings.


#include "WeirdBox.h"

#include "Logging/StructuredLog.h"

// Sets default values
AWeirdBox::AWeirdBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	WeirdBoxComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeirdBoxComponent"));
	WeirdBoxComponent->SetSimulatePhysics(true);

	SetRootComponent(WeirdBoxComponent);
}

// Called when the game starts or when spawned
void AWeirdBox::BeginPlay()
{
	Super::BeginPlay();
	UE_LOGFMT(LogTemp, Log, "Hello, World");
}

// Called every frame
void AWeirdBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

