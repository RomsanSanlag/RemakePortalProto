// Fill out your copyright notice in the Description page of Project Settings.


#include "PortalFonctionLibrary.h"

#include "Engine/TextureRenderTarget2D.h"

void UPortalFonctionLibrary::ResizeRenderTarget(UTextureRenderTarget2D* renderTarget, float sizeX, float sizeY)
{
	if (renderTarget == nullptr)
	{
		return;
	}
	renderTarget->ResizeTarget(sizeX, sizeY);
}
