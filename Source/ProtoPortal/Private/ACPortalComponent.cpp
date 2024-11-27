// Fill out your copyright notice in the Description page of Project Settings.


#include "ACPortalComponent.h"

#include "APortalWall.h"
#include "CollisionDebugDrawingPublic.h"


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

void UACPortalComponent::SpawnPortal(FVector StartLocation, FVector Direction, bool PortalA)
{
	float MaxDistanceSpawnPortal = 1000.f;
	FVector EndLocation = StartLocation + Direction * MaxDistanceSpawnPortal;
	TArray<FHitResult> HitResults;
	
	DrawLineTraces(GetWorld(),StartLocation,EndLocation,HitResults,1);

	//for(FHitResult HitResult : HitResults)
	//{
	//	Cast<FHitResult, AAPortalWall>();
	//	if (HitResult == AAPortalWall)
	//	{
	//		
	//	}
	//}
}


