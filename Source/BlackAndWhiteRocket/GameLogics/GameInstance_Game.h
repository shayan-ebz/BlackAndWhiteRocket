// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "GameInstance_Game.generated.h"

/**
 * 
 */
UCLASS()
class BLACKANDWHITEROCKET_API UGameInstance_Game : public UGameInstance
{
	GENERATED_BODY()

public:

	UGameInstance_Game(const FObjectInitializer & ObjectInitializer);
	
public:
	UPROPERTY(BlueprintReadWrite, Category = "LevelChanger")
	bool ChangeLevel;

protected:

	UFUNCTION(BlueprintCallable, Category = "HiddenButton_Widget")
	void LoadHiddenButtonWidget_Updated();


protected: // variables

	TSubclassOf<class UButtonWidget> HiddenButtons_Widget = nullptr;

	UPROPERTY(BlueprintReadWrite, Category = "GlobalLevel")
	int32 GlobaLevel;

	UPROPERTY(BlueprintReadWrite, Category = "GlobalStar")
	int32 GlobalStar;

};
