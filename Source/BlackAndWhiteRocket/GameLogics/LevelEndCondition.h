// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LevelEndCondition.generated.h"

UCLASS()
class BLACKANDWHITEROCKET_API ALevelEndCondition : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALevelEndCondition();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	void SetWinTimer();

protected:

	UPROPERTY(VisibleAnywhere, Category = "Collison")
	class UBoxComponent* BoxCollision;

	UPROPERTY(BlueprintReadOnly, Category = "WinCondition")
	bool bHasLanded;

	UPROPERTY(BlueprintReadOnly, Category = "WinCondition")
	float Timer = 0; 

	FTimerHandle WinHandle;
};
