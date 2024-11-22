// Copyright Epic Games, Inc. All Rights Reserved.

#include "ProtoPortalGameMode.h"
#include "ProtoPortalCharacter.h"
#include "UObject/ConstructorHelpers.h"

AProtoPortalGameMode::AProtoPortalGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
