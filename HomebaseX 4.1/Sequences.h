#pragma once
#include "SDK.hpp"
#include "Globals.h"
using namespace SDK;

namespace Sequences {
	void MissileLaunchFarm() {
		Globals::GameController->MyHUD->bShowHUD = false;
		auto Func = UObject::FindObject<UFunction>("Function MissileLaunch_Cine.MissileLaunch_Cine_C.Start");

		UObject::FindObject("MissileLaunch_Cine_C MissileLaunch_Cine.MissileLaunch_Cine.PersistentLevel.MissileLaunch_Cine_C_1")->ProcessEvent(Func, nullptr);
	}

	// NOT WORKING. Have to find out why that is
	void BaseIntroFarm() {
		Globals::GameController->MyHUD->bShowHUD = false;
		auto Func = UObject::FindObject<UFunction>("Function Base_Intro_Cine.Base_Intro_Cine_C.Start");

		UObject::FindObject("Base_Intro_Cine_C Base_Intro_Cine.Base_Intro_Cine.PersistentLevel.Base_Intro_Cine_C_0")->ProcessEvent(Func, nullptr);
	}

	void RamirezIntroFarm() {
		// MissileLaunch_Stationary
		Globals::GameController->MyHUD->bShowHUD = false;
		auto Func = UObject::FindObject<UFunction>("Function Ramirez_Intro_Cine.Ramirez_Intro_Cine_C.Start");

		UObject::FindObject("Ramirez_Intro_Cine_C Ramirez_Intro_Cine.Ramirez_Intro_Cine.PersistentLevel.Ramirez_Intro_Cine_C_21")->ProcessEvent(Func, nullptr);
	}

	void RewardItemCards() {
		// Rewards_ItemCard_C Rewards_ItemCard.Default__Rewards_ItemCard_C


		UObject::FindObject("");
	}
}