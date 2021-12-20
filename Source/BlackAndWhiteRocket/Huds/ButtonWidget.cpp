// Fill out your copyright notice in the Description page of Project Settings.


#include "ButtonWidget.h"
#include "../GameLogics/RocketPawn.h"


#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/Engine.h"

bool UButtonWidget::Initialize()
{

	bool Success = Super::Initialize();
	if (!Success) return false;

	//call the rocket and use the left physics thruster
	Rocket = Cast<ARocketPawn>(UGameplayStatics::GetPlayerPawn(this, 0));

	if (!ensure(LeftButton != nullptr)) return false;
	if (!ensure(RightButton != nullptr)) return false;

	LeftButton->OnPressed.AddDynamic(this, &UButtonWidget::OnLeftButtonPressed);
	LeftButton->OnReleased.AddDynamic(this, &UButtonWidget::OnLeftButtonReleased);

	RightButton->OnPressed.AddDynamic(this, &UButtonWidget::OnRightButtonPressed);
	RightButton->OnReleased.AddDynamic(this, &UButtonWidget::OnRightButtonReleased);

	return true;
}

void UButtonWidget::OnLeftButtonPressed()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("LeftButton Pressed"));
	if (!ensure(Rocket != nullptr)) return;

	//call the rocket and Enable the left physics thruster
	Rocket->LeftEnginePowerup(1.f);
}

void UButtonWidget::OnLeftButtonReleased()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("LeftButton Released"));
	if (!ensure(Rocket != nullptr)) return;
	
	//call the rocket and Disable the left physics thruster
	Rocket->LeftEnginePowerup(0.f);
}

void UButtonWidget::OnRightButtonPressed()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("RightButton Pressed"));
	if (!ensure(Rocket != nullptr)) return;

	Rocket->RightEnginePowerup(1.f);
}

void UButtonWidget::OnRightButtonReleased()
{
	if (!ensure(Rocket != nullptr)) return;

	Rocket->RightEnginePowerup(0.f);
}
