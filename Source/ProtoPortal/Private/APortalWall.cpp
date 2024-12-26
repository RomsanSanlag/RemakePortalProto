// Fill out your copyright notice in the Description page of Project Settings.


#include "ProtoPortal/Public/APortalWall.h"

#include <ThirdParty/Imath/Deploy/Imath-3.1.3/include/Imath/ImathFun.h>

#include "Util/ColorConstants.h"


// Sets default values
AAPortalWall::AAPortalWall()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AAPortalWall::TryAddPortal(FVector PortalOrigin, bool PortalA)
{
	//get relative position from world position
	FVector RelativePortalOrigin = GetTransform().InverseTransformPosition(PortalOrigin);

	FVector NewRelativePortalOrigin = ConstainPortalToWall(RelativePortalOrigin.Y, RelativePortalOrigin.Z);
	RelativePortalOrigin.Y = NewRelativePortalOrigin.Y;
	RelativePortalOrigin.Z = NewRelativePortalOrigin.Z;

	DrawDebugSphere(GetWorld(),GetTransform().TransformPosition(RelativePortalOrigin),20.f,12,UE::Geometry::LinearColors::White3b(),false,3,0,2);
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

FVector AAPortalWall::ConstainPortalToWall(float PortalY, float PortalZ)
{
	float ClampedY = ClampPointToWall(PortalY,WallWidth,180/2);
	float ClampedZ = ClampPointToWall(PortalZ,WallHeight,249/2);

	return FVector(0,ClampedY,ClampedZ);
}

float AAPortalWall::ClampPointToWall(float Point, float WallSize, float PortalRadius)
{
	float TempValueToReturn = ((WallSize /= 2) - PortalRadius) - abs(Point);

	float Offset = std::ranges::clamp(TempValueToReturn, -99999999999999.f, 1.f);

	if (Point < 0)
	{
		Offset *= 1;
	}
	else
	{
		Offset *= -1;
	}
	
	return Point - Offset;
}

