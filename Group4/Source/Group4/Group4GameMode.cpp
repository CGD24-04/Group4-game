// Copyright Epic Games, Inc. All Rights Reserved.

#include "Group4GameMode.h"
#include "UObject/ConstructorHelpers.h"

AGroup4GameMode::AGroup4GameMode()
{
	// set default pawn class to ou()Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_Player"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
