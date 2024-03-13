// Copyright Epic Games, Inc. All Rights Reserved.

#include "Group4GameMode.h"
#include "Group4Character.h"
#include "UObject/ConstructorHelpers.h"

AGroup4GameMode::AGroup4GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
