// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "RocketPawn.generated.h"

UCLASS()
class BLACKANDWHITEROCKET_API ARocketPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ARocketPawn();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void LeftEnginePowerup(float Value);
	void RightEnginePowerup(float Value);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/*UFUNCTION()
	void PowerUpPressed();

	UFUNCTION()
	void PowerUpReleased();*/


protected:


	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Rocket")
	class UPaperSpriteComponent* PaperRocket;

	UPROPERTY(VisibleAnywhere, Category = "Rocket")
	class UPhysicsThrusterComponent* LeftEngine;
	
	UPROPERTY(VisibleAnywhere, Category = "Rocket")
	class UPhysicsThrusterComponent* RightEngine;

	UPROPERTY(EditDefaultsOnly, Category = "Rocket")
	float EnginePower = 100.f;

};
