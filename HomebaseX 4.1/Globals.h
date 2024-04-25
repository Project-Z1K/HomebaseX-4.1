#pragma once
#include "SDK.hpp"

using namespace SDK;

namespace Globals {
	UFortEngine* Engine;
	UWorld* World;

	AFortPlayerController* GameController;

	APlayerController* LocalController;

	UGameplayAbility* EmoteAbility;

	APlayerPawn_Generic_C* Character;
	//APlayerPawn_Athena_C* BRCharacter;
	AFortGameStateZone* GameState;

	AFortQuickBars* Quickbars;
	UGameplayStatics* GameplayStatics;
	UKismetStringLibrary* KismetString;

	UObject* (*CreateDefaultObject)(UClass*); // I probably won't need this but if I do i'll have it
	void* (*ProcessEvent)(UObject*, UFunction*, void*);

	static std::string map = "";

	static auto BaseTransform = FTransform{};
}