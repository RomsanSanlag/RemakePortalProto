// Fill out your copyright notice in the Description page of Project Settings.


#include "ProtoPortal/Public/APortalWall.h"


// Sets default values
AAPortalWall::AAPortalWall()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AAPortalWall::BeginPlay()
{
	Super::BeginPlay();
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, "Begin play");
}

// Called every frame
void AAPortalWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

