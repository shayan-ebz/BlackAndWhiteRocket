// Fill out your copyright notice in the Description page of Project Settings.


#include "RocketPawn.h"

#include "../Plugins/2D/Paper2D/Source/Paper2D/Classes/PaperSpriteComponent.h"
#include "PhysicsEngine/PhysicsThrusterComponent.h"
#include "Components/InputComponent.h"
#include "Engine/Engine.h"

// Sets default values
ARocketPawn::ARocketPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	PaperRocket = CreateDefaultSubobject<UPaperSpriteComponent>("PaperRocket");
	RootComponent = PaperRocket;

	LeftEngine = CreateDefaultSubobject<UPhysicsThrusterComponent>("LeftEngine");
	LeftEngine->SetupAttachment(RootComponent);

	RightEngine = CreateDefaultSubobject<UPhysicsThrusterComponent>("RightEngine");
	RightEngine->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ARocketPawn::BeginPlay()
{
	Super::BeginPlay();
	LeftEngine->Activate(true);
	RightEngine->Activate(true);
}

// Called to bind functionality to input
void ARocketPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	

	InputComponent->BindAxis("LeftPowerUp", this, &ARocketPawn::LeftEnginePowerup);
	InputComponent->BindAxis("RightPowerUp", this, &ARocketPawn::RightEnginePowerup);

	//InputComponent->BindAction("PowerUp", IE_Pressed, this, &ARocketPawn::PowerUpPressed);
	//InputComponent->BindAction("PowerUp", IE_Released, this, &ARocketPawn::PowerUpReleased);
}


void ARocketPawn::LeftEnginePowerup(float Value)
{
	LeftEngine->ThrustStrength = (Value * EnginePower);
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("ThrustStrength is %f"), test));
}

void ARocketPawn::RightEnginePowerup(float Value)
{
	RightEngine->ThrustStrength = (Value * EnginePower);
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("ThrustStrength is %f"), test));
}

