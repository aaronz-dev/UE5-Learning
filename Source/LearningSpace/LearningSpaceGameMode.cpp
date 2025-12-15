// Copyright Epic Games, Inc. All Rights Reserved.

#include "LearningSpaceGameMode.h"
#include "LearningSpaceCharacter.h"
#include "UObject/ConstructorHelpers.h"

ALearningSpaceGameMode::ALearningSpaceGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
