// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ButtonWidget.generated.h"

/**
 * 
 */
UCLASS()
class BLACKANDWHITEROCKET_API UButtonWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:

	UPROPERTY(meta = (BindWidget))
	class UButton* LeftButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* RightButton;

protected:

	virtual bool Initialize() override;

	UFUNCTION()
	void OnLeftButtonPressed();

	UFUNCTION()
	void OnLeftButtonReleased();

	UFUNCTION()
	void OnRightButtonPressed();

	UFUNCTION()
	void OnRightButtonReleased();

private:

	class ARocketPawn* Rocket;
};
