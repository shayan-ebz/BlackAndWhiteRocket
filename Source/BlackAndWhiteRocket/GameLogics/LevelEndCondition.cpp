	// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelEndCondition.h"
#include "GameInstance_Game.h"

#include "Components/BoxComponent.h"
#include "Engine.h"


// Sets default values
ALevelEndCondition::ALevelEndCondition()
{
	PrimaryActorTick.bCanEverTick = false;
	bHasLanded = false;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>("EndCondition");
	
}

// Called when the game starts or when spawned
void ALevelEndCondition::BeginPlay()
{
	Super::BeginPlay();
	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &ALevelEndCondition::OnOverlapBegin);
	BoxCollision->OnComponentEndOverlap.AddDynamic(this, &ALevelEndCondition::OnOverlapEnd);

}

void ALevelEndCondition::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// after 3 seconds player wins.
	/*
	*	a function to call when overlap Begins
	*	we need timer manager to keep track of time. after 3 secs win condition happens
	*	a function to be bp callable and show the timer bar for win condition
	*/
	UE_LOG(LogTemp, Warning, TEXT("overlap begins"))
	
	bHasLanded = true;	// landed successfully
	GetWorldTimerManager().SetTimer(WinHandle, this, &ALevelEndCondition::SetWinTimer, 1, true);
}

void ALevelEndCondition::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Warning, TEXT("overlap ends"))

	bHasLanded = false; // couldn't land so it takes off
	Timer = 0;
	GetWorldTimerManager().ClearTimer(WinHandle);
}

void ALevelEndCondition::SetWinTimer()
{
	++Timer;
	if (Timer == 3)
	{
		GetWorldTimerManager().ClearTimer(WinHandle);
		
		// load next level
		//call rocket game instance and say i am ready to change the level
		UGameInstance_Game* GI = Cast<UGameInstance_Game>(GetWorld()->GetGameInstance());
		if (!ensure(GI != nullptr)) return;

		//landing conformation and shooter char should come out
		GI->ChangeLevel = true;
		//GI->LevelNumber++;

	}
}

