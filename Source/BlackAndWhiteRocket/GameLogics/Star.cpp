// Fill out your copyright notice in the Description page of Project Settings.


#include "Star.h"
#include "../Plugins/2D/Paper2D/Source/Paper2D/Classes/PaperSpriteComponent.h"

// Sets default values
AStar::AStar()
{
	PrimaryActorTick.bCanEverTick = false;

	StarSprite = CreateDefaultSubobject<UPaperSpriteComponent>("PaperRocket");


}

// Called when the game starts or when spawned
void AStar::BeginPlay()
{
	Super::BeginPlay();
	StarSprite->OnComponentBeginOverlap.AddDynamic(this, &AStar::OnOverlapBegin);

}

void AStar::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// 

	this->Destroy();
}
