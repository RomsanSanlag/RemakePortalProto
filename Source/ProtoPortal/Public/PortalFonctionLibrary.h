// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PortalFonctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class PROTOPORTAL_API UPortalFonctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "PortalFonctionLibrary")
	static void ResizeRenderTarget(UTextureRenderTarget2D* renderTarget, float sizeX, float sizeY);
};
