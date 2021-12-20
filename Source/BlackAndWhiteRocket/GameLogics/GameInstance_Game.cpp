	// Fill out your copyright notice in the Description page of Project Settings.


#include "GameInstance_Game.h"

#include "../Huds/ButtonWidget.h"
#include "ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"

UGameInstance_Game::UGameInstance_Game(const FObjectInitializer & ObjectInitializer)
{
	ChangeLevel = false;
	static ConstructorHelpers::FClassFinder<UButtonWidget> HiddenButtonBP(TEXT("/Game/_Blueprint/HUD/GamePlay/WBP_Buttons"));
	
	HiddenButtons_Widget = HiddenButtonBP.Class;
}

void UGameInstance_Game::LoadHiddenButtonWidget_Updated()
{
	if (!ensure(HiddenButtons_Widget != nullptr)) return;

	UUserWidget* HiddenButtons = CreateWidget<UButtonWidget>(this, HiddenButtons_Widget);

	if (!ensure(HiddenButtons != nullptr)) return;

	HiddenButtons->AddToViewport();

	UE_LOG(LogTemp, Warning, TEXT("added to view port"))
}
