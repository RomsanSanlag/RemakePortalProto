// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "APortalWall.generated.h"

UCLASS()
class PROTOPORTAL_API AAPortalWall : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAPortalWall();

	UPROPERTY(BlueprintReadOnly, EditInstanceOnly)
	float WallWidth = 100.f;
	
	UPROPERTY(BlueprintReadOnly, EditInstanceOnly)
	float WallHeight = 100.f;

	UFUNCTION(BlueprintCallable)
	void TryAddPortal(FVector PortalOrigin, bool PortalA);
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FVector ConstainPortalToWall(float PortalY, float PortalZ);
	float ClampPointToWall(float Point, float WallSize, float PortalRadius);
};
