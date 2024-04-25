#pragma once
#include <Windows.h>
#include "SDK.hpp"
#include "Globals.h"
#include <fstream>
#include <format>
#include <vector>
#include <string>
using namespace SDK;

namespace Helpers {

	std::vector<std::string> NonRPCFuncs = {
		"ReceiveTick"
	};

	bool IsRPCFunc(std::string FuncName) // nax
	{
		for (auto Func : NonRPCFuncs)
		{
			if (Func == FuncName)
				return false;
		}

		return true;
	}

	bool IsNull(void* In) //not sure if this actually works || nax
	{
		if (In == nullptr)
			return true;

		return false;
	}

	void DumpObjs() {
		std::ofstream Objects("Objects.log");

		for (int i = 0; i < UObject::GObjects->Num(); i++) {
			auto Obj = UObject::GObjects->GetByIndex(i);
			if (Obj) {
				Objects << std::format("{} {}\n", i, Obj->GetFullName());
			}
		}
	}

	UKismetSystemLibrary* Instance;

	UKismetSystemLibrary* GetSystemLibrary()
	{
		if (IsNull(Instance))
			Instance = UObject::FindObjectFast<UKismetSystemLibrary>("Default__KismetSystemLibrary");

		return Instance;
	}

	void ShowHud() {
		Globals::GameController->MyHUD->bShowHUD = true;
	}

	void PrintTextCanvas() // kinda like a watermark. (just a test) || nax
	{
		auto HUD = Globals::GameController->MyHUD;
		if (!IsNull(HUD))
		{
			auto Canvas = HUD->Canvas;
			if (!IsNull(Canvas))
			{
				Canvas->K2_DrawText(UObject::FindObject<UFont>("Font Burbank.Burbank"), L"HomebaseX", { 10, 10 }, { 1,0,0,0 }, 0.0f, { 0,0,0,0 }, { 0,0 }, false, false, false, { 0,0,0,0 });
			}
		}
	}

	// For sequences
	void streammapEverything() {
		if (Globals::map == "Zone_Outpost_Stonewood") {
			// maybe force load sequences, probably won't work but worth a shot
			//Helpers::GetKismetSystem()->ExecuteConsoleCommand(Globals::World, L"streammap /Game/Maps/Zones/Outpost/Outpost_BeeHusk_Intro_Cine", nullptr);
		}
	}

	bool AreGuidsEqual(FGuid guidA, FGuid guidB) {
		if (guidA.A == guidB.A && guidA.B == guidB.B && guidA.C == guidB.C && guidA.D == guidB.D)
			return true;
		else
			return false;
	}

	template<typename T = AActor>
	T* SpawnActor(UClass* Class = nullptr, FVector Location = {}, FRotator Rotation = {})
	{
		if (IsNull(Class))
			Class = T::StaticClass();

		FQuat Quat;
		FTransform Transform;
		Quat.W = 0;
		Quat.X = Rotation.Pitch;
		Quat.Y = Rotation.Roll;
		Quat.Z = Rotation.Yaw;
		Transform.Rotation = Quat;
		Transform.Scale3D = FVector{ 1,1,1 };
		Transform.Translation = Location;

		auto GS = Globals::GameplayStatics;
		auto Actor = GS->BeginDeferredActorSpawnFromClass(Globals::World, Class, Transform, ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn, nullptr);
		GS->FinishSpawningActor(Actor, Transform);
		return static_cast<T*>(Actor);
	}

	AHuskPawn_C* SpawnHusk(FVector Location)
	{
		auto Husk = SpawnActor<AHuskPawn_C>(nullptr, Location);
		if (Husk)
		{
			// Husk->ExecuteUbergraph(0); //Don't think it does anything

			Husk->AIDifficultyLevel = 1.0f;
			Husk->AIType = EFortressAIType::FAT_Encounter;
			Husk->AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
			Husk->Controller = SpawnActor<AAIController>(Husk->AIControllerClass.Get(), Location);
			Husk->SetCurrentAimTarget(Globals::Character);
			if (Husk->CurrentAimTarget != Globals::Character)
				Husk->CurrentAimTarget = Globals::Character;

			//honestly have no idea what im doing tbh
		}
	}

	bool replace(std::string& str, const std::string& from, const std::string& to) { //Shouldn't be here, should make a utils file.
		size_t start_pos = str.find(from);
		if (start_pos == std::string::npos)
			return false;
		str.replace(start_pos, from.length(), to);
		return true;
	}

	ABuildingSMActor* SpawnBuildActor(UClass* BuildClass, FVector Location, FRotator Rotation)
	{
		FQuat Quat;
		FTransform Transform;

		auto DEG_TO_RAD = 3.14159 / 180;
		auto DIVIDE_BY_2 = DEG_TO_RAD / 2;

		auto SP = sin(Rotation.Pitch * DIVIDE_BY_2);
		auto CP = cos(Rotation.Pitch * DIVIDE_BY_2);

		auto SY = sin(Rotation.Yaw * DIVIDE_BY_2);
		auto CY = cos(Rotation.Yaw * DIVIDE_BY_2);

		auto SR = sin(Rotation.Roll * DIVIDE_BY_2);
		auto CR = cos(Rotation.Roll * DIVIDE_BY_2);

		Quat.X = CR * SP * SY - SR * CP * CY;
		Quat.Y = -CR * SP * CY - SR * CP * SY;
		Quat.Z = CR * CP * SY - SR * SP * CY;
		Quat.W = CR * CP * CY + SR * SP * SY;

		Transform.Rotation = Quat;
		Transform.Scale3D = FVector{ 1,1,1 };
		Transform.Translation = Location;

		auto Actor = Globals::GameplayStatics->BeginSpawningActorFromClass(Globals::World, BuildClass, Transform, false, nullptr);
		Globals::GameplayStatics->FinishSpawningActor(Actor, Transform);
		return static_cast<ABuildingSMActor*>(Actor);
	}
}