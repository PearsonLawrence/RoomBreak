// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "RealityRoomGameMode.h"
#include "RealityRoomHUD.h"
#include "RealityRoomCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARealityRoomGameMode::ARealityRoomGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ARealityRoomHUD::StaticClass();
}
