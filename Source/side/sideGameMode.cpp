// Copyright Epic Games, Inc. All Rights Reserved.

#include "sideGameMode.h"
#include "sideCharacter.h"
#include "UObject/ConstructorHelpers.h"

AsideGameMode::AsideGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
