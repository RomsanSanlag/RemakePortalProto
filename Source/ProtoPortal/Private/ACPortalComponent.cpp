// Fill out your copyright notice in the Description page of Project Settings.


#include "ACPortalComponent.h"

#include "APortalWall.h"
#include "CollisionDebugDrawingPublic.h"
#include "KismetTraceUtils.h"
#include "Runtime/MovieSceneTracks/Private/MovieSceneTracksCustomAccessors.h"


// Sets default values for this component's properties
UACPortalComponent::UACPortalComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UACPortalComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UACPortalComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                       FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UACPortalComponent::SpawnPortal(FVector StartLocation, FVector EndLocation, bool PortalA)
{
	FHitResult* Hit = new FHitResult();

	GetWorld()->LineTraceSingleByChannel(*Hit, StartLocation, EndLocation, ECC_WorldStatic);
	bool bHit = false;
	FHitResult* HitDebug = new FHitResult();
	DrawDebugLineTraceSingle(GetWorld(),StartLocation, EndLocation,EDrawDebugTrace::Persistent, bHit, *HitDebug, FLinearColor::Blue, FLinearColor::Red, 5);
	
	
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Blue, Hit->GetComponent()->GetName());

	//AAPortalWall AAPortalWallActor = Cast<AAPortalWall>();
}


