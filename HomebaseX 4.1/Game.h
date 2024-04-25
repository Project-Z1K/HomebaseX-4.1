#pragma once
#include "SDK.hpp"
#include "Globals.h"
#include "Inventory.h"
#include "Abilities.h"
#include "Helpers.h"
#include "Sequences.h"
#include <format>
using namespace SDK;

namespace Game {
	static bool isPEHooked = false;
	static bool inGame = false;
	static bool wantsToLoad = false;
	static bool hasLoaded = false;


	static bool logRPC = false;


	static void* FNHook(UObject* Object, UFunction* Function, void* Params) {

		if (Object && Function)
		{
			// tell everyone that it's online and ready to go!
			if (!isPEHooked) {
				isPEHooked = true;
				printf("[HomebaseX] ProcessEvent has been successfully hooked! You may now go in-game\n");
			}

			auto FuncName = Function->GetName();

			// log RPC (for debugging) *and will for sure TANK your fps*
			// if Helpers::IsRPCFunc causes your pc to go boom, remove it. || nax
			if (logRPC && Helpers::IsRPCFunc(FuncName)) {
				std::cout << "RPC Called: " << FuncName << "\n";
			}

			// STW Start button
			if (FuncName == "BndEvt__StartButton_K2Node_ComponentBoundEvent_0_CommonButtonClicked__DelegateSignature" && !wantsToLoad) {
				wantsToLoad = true;
				// Zone_Onboarding_FarmsteadFort
					// Zone_Outpost_Stonewood
					// Zone_Outpost_TwinePeaks
					// Zone_Outpost_CannyValley
					// Zone_Survival_Diners
					// Zone_Survival_ThunderRoute99
					// Zone_Temperate_Grassland
					// Zone_Outpost_Plankerton_AD
					// Outpost_FlingerIntro_Cine (SEQ)
					// Zone_Temperate_Industrial
					// Zone_Onboarding_Forest_a
					// Zone_Onboarding_Suburban_a
					// Zone_Temperate_Urban_Blockbuster (Blockbuster 2018)
					// Zone_Arid_Stormquest_Desert (StormQuest)
				Globals::map = "Zone_Onboarding_FarmsteadFort";
				Globals::LocalController->SwitchLevel(L"Zone_Onboarding_FarmsteadFort");
			}

			if (FuncName == "ReadyToStartMatch" && wantsToLoad) {
				if (!hasLoaded) {
					hasLoaded = true;
					Globals::World = Globals::Engine->GameViewport->World;
					auto GameMode = reinterpret_cast<AFortGameMode*>(Object);
					auto GameState = (AFortGameStateZone*)GameMode->GameState;
					auto Controller = reinterpret_cast<AFortPlayerController*>(Globals::Engine->GameInstance->LocalPlayers[0]->PlayerController);
					auto PlayerState = (AFortPlayerStateZone*)Controller->PlayerState;

					Globals::GameController = Controller;

					Globals::GameState = GameState;

					Globals::GameState->MissionManager = reinterpret_cast<AFortMissionManager*>(Globals::GameplayStatics->SpawnObject(AFortMissionManager::StaticClass(), Globals::GameState));

					AFortObjectiveBase* ObjectiveTest = reinterpret_cast<AFortObjectiveBase*>(Globals::GameplayStatics->SpawnObject(AFortObjectiveBase::StaticClass(), nullptr));

					// TEST:
					// FortBadgeItemDefinition MissionBadge_Survivor_Silver_T20.MissionBadge_Survivor_Silver_T20 (ObjectiveRewardBadge)
					// (ObjectiveStatus) (EFortObjectiveStatus)
					// (ObjectiveAnalyticsName)
					// (MissionRequirement) (EFortObjectiveRequirement)
					// (VisibilityOverride) (EFortMissionVisibilityOverride)
					// (ObjectiveAudiblity) (EFortMissionAudibility)

					/*

					void OnRep_ObjectiveVisibilityOverride();
		void OnRep_ObjectiveStatus();
		void OnRep_bIsObjectiveVisible();


					ObjectiveTest->ObjectiveRewardBadge = UObject::FindObject<UFortBadgeItemDefinition>("FortBadgeItemDefinition MissionBadge_Survivor_Silver_T20.MissionBadge_Survivor_Silver_T20");
					ObjectiveTest->ObjectiveStatus = EFortObjectiveStatus::InProgress;
					ObjectiveTest->OnRep_ObjectiveStatus();
					ObjectiveTest->ObjectiveAnalyticsName = L"HomebaseX Debug";
					ObjectiveTest->MissionRequirement = EFortObjectiveRequirement::Required;
					ObjectiveTest->VisibilityOverride = EFortMissionVisibilityOverride::Visible;
					ObjectiveTest->OnRep_ObjectiveVisibilityOverride();
					ObjectiveTest->bIsObjectiveVisible = true;
					ObjectiveTest->OnRep_bIsObjectiveVisible();
					ObjectiveTest->ObjectiveAudiblity = EFortMissionAudibility::UseVisibility;

					Globals::GameController->ServerTriggerGenericObjectiveEvent(ObjectiveTest);

					ObjectiveTest->StartPlayingObjective(); // idk if this works but we gonna see
					ObjectiveTest->SetUIVisibilityOverride(EFortMissionVisibilityOverride::Visible);
					ObjectiveTest->SetUiVisibility(true);

					*/


					auto HandlerName = Globals::GameState->MissionManager->GetName();

					std::cout << ("[HomebaseX Definition] MissionManager Name: ") << HandlerName << "\n\n";

					// Unnessacary
					//auto CheatManager = reinterpret_cast<UFortCheatManager*>(Globals::GameplayStatics->SpawnObject(UFortCheatManager::StaticClass(), Globals::GameController));

					//if (CheatManager)
						//Controller->CheatManager = CheatManager;

					FTransform SpawnPos = Globals::BaseTransform;

					auto PlayerStarts = GameMode->K2_FindPlayerStart(Globals::GameController, L"");

					FVector SpawnLoc = PlayerStarts->K2_GetActorLocation();

					if (Globals::map == "Zone_Outpost_Stonewood" ||
						Globals::map == "Zone_Outpost_TwinePeaks" ||
						Globals::map == "Zone_Outpost_CannyValley" ||
						Globals::map == "Zone_Survival_Diners" ||
						Globals::map == "Zone_Survival_ThunderRoute99" ||
						Globals::map == "Zone_Temperate_Grassland" ||
						Globals::map == "Zone_Outpost_Plankerton_AD" ||
						Globals::map == "Outpost_FlingerIntro_Cine" ||
						Globals::map == "Zone_Temperate_Industrial" ||
						Globals::map == "Zone_Onboarding_Forest_a" ||
						Globals::map == "Zone_Onboarding_Suburban_a" ||
						Globals::map == "Zone_Temperate_Urban_Blockbuster" ||
						Globals::map == "Zone_Arid_Stormquest_Desert") {
						SpawnPos.Translation = { 0, 0, 5500 };
					}
					else {
						SpawnPos.Translation = SpawnLoc;
					}

					auto Pawn = Helpers::SpawnActor<APlayerPawn_Generic_C>(nullptr, SpawnPos.Translation);

					Helpers::streammapEverything(); // Streammap shit for sequences

					Globals::Character = Pawn;

					Globals::GameController->Possess(Globals::Character);

					Globals::GameController->OverriddenBackpackSize = 10000;
					Globals::GameController->bInfiniteAmmo = true;
					Globals::GameController->bCraftFree = true;

					Inventory::SetupInventory();
					Inventory::GiveMaterials(); // give all material (soon have to make this based on portion of Mission)

					Helpers::PrintTextCanvas(); //funny || nax

					Globals::GameController->bCraftFree = true;
					//reinterpret_cast<UFortCheatManager*>(Globals::GameController->CheatManager)->CraftFree();

					Globals::GameController->CheatManager->God();
					Globals::GameController->ServerSetClientHasFinishedLoading(true);
					Globals::GameController->bHasServerFinishedLoading = true;
					Globals::GameController->OnRep_bHasServerFinishedLoading();

					Globals::GameController->ServerReadyToStartMatch(); //magical Loading screen drop

					PlayerState->bIsGameSessionOwner = true;
					PlayerState->OnRep_SessionOwner();
					PlayerState->OnRep_CharacterParts();
					Globals::Character->OnCharacterPartsReinitialized();

					GameMode->StartMatch();
					GameMode->StartPlay();

					inGame = true;
				}
			}

			if (FuncName == "ServerLoadingScreenDropped") {
				if (inGame) {
					Abilities::GrantEverything();

					FString MMID = L"HomebaseX Epic"; // Matchmaking Session Id (do not change)
					FString Difficulty = L"HARD";
					//Globals::GameController->MyPlayerInfo->AccountProfile->ModifyMission(MMID, Difficulty, nullptr); //(Don't use this rn)


					// (DO NOT UNCOMMENT, NOT WORKING)
					//FFortQuestObjectiveCompletion Objective = FFortQuestObjectiveCompletion{};
					//FDedicatedServerUrlContext UrlContext = FDedicatedServerUrlContext{};

					//TArray<FFortQuestObjectiveCompletion> Objectives = TArray<FFortQuestObjectiveCompletion>();

					//Objective.StatName = L"Help my step sister get out of the washing machine";
					//Objective.Count = 1;

					//Objectives.Add(Objective);

					//Globals::GameController->MyPlayerInfo->AccountProfile->StartPrimaryMission(Objectives, MMID, L"TestRun", &UrlContext);
				}
			}

			if (FuncName == "ServerPlayEmoteItem" || FuncName == "ServerEmote") {
				AFortPlayerControllerAthena* PlayerController = (AFortPlayerControllerAthena*)Object;
				AFortPlayerPawnAthena* Pawn = (AFortPlayerPawnAthena*)Globals::GameController->Pawn;
				Params::AFortPlayerController_ServerPlayEmoteItem_Params* CurrentParams = (Params::AFortPlayerController_ServerPlayEmoteItem_Params*)Params;

				auto emote = CurrentParams->EmoteAsset;
			}

			if (FuncName == "ServerExecuteInventoryItem") {
				// AFortPlayerController_ServerExecuteInventoryItem_Params*
				FGuid GUID = reinterpret_cast<Params::AFortPlayerController_ServerExecuteInventoryItem_Params*>(Params)->ItemGuid;

				Inventory::EquipInventoryItem(GUID);

				auto Weap = reinterpret_cast<APlayerPawn_Generic_C*>(Globals::GameController->Pawn)->CurrentWeapon; // ignore warning

				// Credits to Milxnor & GD
				if (Weap && Weap->Class && Weap->IsA(AFortWeap_BuildingTool::StaticClass())) {
					AFortWeap_BuildingTool* BuildingTool = reinterpret_cast<AFortWeap_BuildingTool*>(Weap);
					if (Weap->WeaponData) {
						auto DefaultMD = BuildingTool->DefaultMetadata;
						BuildingTool->DefaultMetadata = reinterpret_cast<UFortBuildingItemDefinition*>(Weap->WeaponData)->BuildingMetaData.Get();
						BuildingTool->OnRep_DefaultMetadata(DefaultMD);
					}
				}
			}

			if (FuncName == "ServerCraftSchematic")
			{
				auto Parameters = (Params::AFortPlayerController_ServerCraftSchematic_Params*)Params;
				if (Parameters)
				{
					auto ItemId = Parameters->ItemId.ToString();
					std::cout << "[HomebaseX] : Crafted: " << ItemId << std::endl;

					Helpers::replace(ItemId, "Schematic:SID", "WID"); //should just be the ID 

					std::cout << "[HomebaseX] : WID Item: " << ItemId << std::endl;
					auto name = std::format("FortWeaponRangedItemDefinition {}.{}", ItemId.c_str(), ItemId.c_str());

					UFortItemDefinition* ItemDef = nullptr;
					ItemDef = UObject::FindObject<UFortItemDefinition>(ItemId);

					if(Helpers::IsNull(ItemDef))
						UFortItemDefinition* ItemDef = UObject::FindObject<UFortItemDefinition>(name);

					if (ItemDef)
					{
						Inventory::HandleNewItem(ItemDef, Inventory::GetOpenSlot());
					}
				}
			}

			if (FuncName == "CreateOrUpgradeOutpostItem")
			{
				auto Parameters = (Params::UFortMcpProfileMetadata_CreateOrUpgradeOutpostItem_Params*)Params;
				if (Parameters)
				{
					auto TemplateId = Parameters->TemplateId.ToString();
					std::cout << "[HomebaseX] Template Id: " << TemplateId << std::endl;
				}
			}

			if (FuncName == "UpgradeItem")
			{
				auto Parameters = (Params::UFortMcpProfileCampaign_UpgradeItem_Params*)Params;
				if (Parameters)
				{
					auto TargetItemId = Parameters->TargetItemId.ToString();
					std::cout << "[HomebaseX] Target ItemId: " << TargetItemId << std::endl;
				}
			}


			if (FuncName == "UpgradeBuilding")
			{
				auto Parameters = (Params::AFortPlayerControllerOutpost_UpgradeBuilding_Params*)Params;
				if (Parameters)
				{
					auto OutpostBuilding = Parameters->OutpostBuilding;
					std::cout << "[HomebaseX] UpgradeBuilding: Outpost Building: " << (int)OutpostBuilding << std::endl;
					std::cout << "[HomebaseX] Outpost Building Output:\nStormShield: 0\nCraftingTable: 1\nFabricator: 2\nHarvestingOptimizer: 3\nStorageVault: 4\nPOST: 5\nMAX: 6, ";
				}
			}

			if (FuncName == "UpgradeBuildingByDefinition")
			{
				auto Parameters = (Params::AFortPlayerControllerOutpost_UpgradeBuildingByDefinition_Params*)Params;
				if (Parameters)
				{
					auto OutpostBuilding = Parameters->OutpostBuilding;
					std::cout << "[HomebaseX] UpgradeBuildingByDefinition: Outpost Building: " << OutpostBuilding->GetName() << std::endl;
				}
			}


			if (FuncName == "ServerUpgradeBuildingActor")//Upgrade Building Func || if not needed just remove.
			{
				auto Parameters = (Params::AFortPlayerController_ServerUpgradeBuildingActor_Params*)Params;
				if (Parameters)
				{
					auto BuildingActorToUpgrade = (ABuildingSMActor*)Parameters->BuildingActorToUpgrade;
					auto NewUpgradeLevel = Parameters->NewUpgradeLevel;
					
					std::cout << "[HomebaseX] Building Actor To Upgrade: " << BuildingActorToUpgrade->GetName() << std::endl;
					std::cout << "[HomebaseX] New Upgrade Level: " << NewUpgradeLevel << std::endl;
				}
			}

			if (FuncName == "ServerCreateBuildingActor") { // this should work || nax
				auto params = (Params::AFortPlayerController_ServerCreateBuildingActor_Params*)Params;
				auto BuildClass = params->BuildingClassData.BuildingClass.Get();
				auto Loc = params->BuildLoc;
				auto Rot = params->BuildRot;
				std::cout << "[HomebaseX] Build Class: " << BuildClass->GetName() << std::endl;
				ABuildingSMActor* BuildingActor = Helpers::SpawnBuildActor(BuildClass, Loc, Rot);
				if (BuildingActor)
				{
					BuildingActor->BuildingPlacementType = EPlacementType::Grid;
					BuildingActor->DynamicBuildingPlacementType = EDynamicBuildingPlacementType::DestroyAnythingThatCollides;
					BuildingActor->bAllowUpgradeRegardlessOfPlayerBuildLevel = true;
					BuildingActor->bIsPlayerBuildable = true;
					BuildingActor->bPlayerPlaced = true;
					BuildingActor->SetMirrored(params->bMirrored);
					BuildingActor->InitializeKismetSpawnedBuildingActor(BuildingActor, Globals::GameController);
				}

			}

			if (FuncName == "ServerAttemptInteract") {
				Params::AFortPlayerController_ServerAttemptInteract_Params* paramaters = reinterpret_cast<Params::AFortPlayerController_ServerAttemptInteract_Params*>(Params);
				AActor* Actor = paramaters->ReceivingActor;
				if (Actor->IsA(ABuildingContainer::StaticClass())) {
					ABuildingContainer* Container = (ABuildingContainer*)Actor;
					Container->bAlreadySearched = true;
					Container->OnRep_bAlreadySearched();
				}

				if (Actor->IsA(ATiered_BluGlo_Parent_C::StaticClass())) {
					/*	auto BluGo = (ATiered_BluGlo_Parent_C*)Actor;
						BluGo->bAlreadySearched = true;
						BluGo->OnRep_bAlreadySearched();
						BluGo->K2_DestroyActor(); */
				}
			}

			if (FuncName == "CheatScript") {
				FString Cmd = reinterpret_cast<Params::UCheatManager_CheatScript_Params*>(Params)->ScriptName;
				std::string CmdStr = Cmd.ToString();
				std::string Args = "";
				if (CmdStr.find(" ") != std::string::npos) {
					Args = CmdStr.substr(CmdStr.find(" ") + 1);
				}

				CmdStr = CmdStr.substr(0, CmdStr.find(" "));

				if (CmdStr == "equipweapon") {
					if (Args != "") {
						auto name = std::format("FortWeaponRangedItemDefinition {}.{}", Args.c_str(), Args.c_str());
						UFortItemDefinition* ItemDef = UObject::FindObject<UFortItemDefinition>(name);
						if (ItemDef) {
							Inventory::HandleNewItem(ItemDef);
						}
					}
				}

				// it works
				if (CmdStr == "startmissilelaunch") {
					Sequences::MissileLaunchFarm(); // start the missile launch seq.
				}

				if (CmdStr == "showhud") {
					Helpers::ShowHud(); // fuck me daddy
				}
			}
		}

		return Globals::ProcessEvent(Object, Function, Params);
	}
}