#pragma once
#include "Globals.h"
#include "SDK.hpp"
#include <vector>

using namespace SDK;

namespace Abilities {
	inline int32_t GrantAbilityOffset = 0x05394C0;
	std::vector<std::pair<FGameplayAbilitySpecHandle, UGameplayAbility*>> Specs;
	std::vector<std::pair<FActiveGameplayEffectHandle, UGameplayEffect*>> Effects;

	void GrantAbility(UGameplayAbility* AbilityClass) {
		FGameplayAbilitySpec Spec = FGameplayAbilitySpec{};
		FGameplayAbilitySpecHandle Handle{};
		Handle.Handle = rand();

		Spec.Handle = Handle;
		Spec.Ability = UObject::FindObjectFast<UGameplayAbility>("Default__" + AbilityClass->GetName());
		Spec.Level = 1;
		Spec.MostRecentArrayReplicationKey = Spec.ReplicationID = Spec.ReplicationKey = Spec.InputID = -1;
		static auto GiveAbility = reinterpret_cast<FGameplayAbilitySpecHandle(*)(UAbilitySystemComponent*, const FGameplayAbilitySpecHandle*, FGameplayAbilitySpec)>(uintptr_t(GetModuleHandle(0)) + GrantAbilityOffset);
		Specs.push_back(std::make_pair(GiveAbility(Globals::Character->AbilitySystemComponent, &Handle, Spec), AbilityClass));
	}

	void GrantEverything() {
		UFortAbilitySet* GAS = UObject::FindObject<UFortAbilitySet>("FortAbilitySet GAS_DefaultPlayer.GAS_DefaultPlayer");

		for (int i = 0; i < GAS->GameplayAbilities.Num(); i++) {

			auto GAB = GAS->GameplayAbilities[i];

			if (GAB) {
				GrantAbility(GAB);
			}
		}
	}
}