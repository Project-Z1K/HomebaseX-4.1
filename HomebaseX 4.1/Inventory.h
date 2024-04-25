#pragma once
#include "Globals.h"
#include "SDK.hpp"
#include "Helpers.h"
using namespace SDK;

namespace Inventory {
	void Update() {
		Globals::GameController->WorldInventory->HandleInventoryLocalUpdate();
		Globals::GameController->HandleWorldInventoryLocalUpdate();
		Globals::GameController->OnRep_QuickBar();
		Globals::GameController->QuickBars->OnRep_PrimaryQuickBar();
		Globals::GameController->QuickBars->OnRep_SecondaryQuickBar();
	}

	int GetOpenSlot() {
		for (int i = 0; i < 6; i++) {
			if (Globals::GameController->QuickBars->PrimaryQuickBar.Slots[i].Items.Data == nullptr) {
				return i;
			}
		}
		return -1;
	}

	int GetItemSlot(FGuid ItemGuid) {
		for (int i = 0; i < 6; i++) {
			if (Globals::GameController->QuickBars->PrimaryQuickBar.Slots[i].Items.Data != nullptr && Globals::GameController->QuickBars->PrimaryQuickBar.Slots[i].Items[0] == ItemGuid) {
				return i;
			}
		}
		return -1;
	}

	void EquipItem(UFortWorldItem* Weapon) {
		UFortWeaponItemDefinition* ItemDef = (UFortWeaponItemDefinition*)Weapon->GetItemDefinitionBP();
		AFortWeapon* WeaponData = Globals::Character->EquipWeaponDefinition(ItemDef, Weapon->GetItemGuid());
		WeaponData->OnRep_ReplicatedWeaponData();
		WeaponData->ClientGivenTo(Globals::Character);
		Globals::Character->ClientInternalEquipWeapon(WeaponData);
	}

	void SpawnPickup(UFortWorldItem* Item) {
		FTransform SpawnTransform = Globals::BaseTransform;
		SpawnTransform.Translation = Globals::Character->K2_GetActorLocation();
		AFortPickupAthena* Pickup = reinterpret_cast<AFortPickupAthena*>(Globals::GameplayStatics->FinishSpawningActor(Globals::GameplayStatics->BeginDeferredActorSpawnFromClass(Globals::Engine->GameViewport->World, AFortPickupAthena::StaticClass(), SpawnTransform, ESpawnActorCollisionHandlingMethod::AlwaysSpawn, Globals::GameController), SpawnTransform));
		Pickup->PrimaryPickupItemEntry = Item->ItemEntry;
		Pickup->OnRep_PrimaryPickupItemEntry();
		Pickup->TossPickup(Globals::Character->K2_GetActorLocation(), Globals::Character, Pickup->PrimaryPickupItemEntry.Count, true);
	}

	void DropItem(FGuid ItemGuid) {
		int ItemSlot = GetItemSlot(ItemGuid);
		for (int i = 0; i < Globals::GameController->WorldInventory->Inventory.ItemInstances.Num(); i++) {
			if (Globals::GameController->WorldInventory->Inventory.ItemInstances[i]->ItemEntry.ItemGuid == ItemGuid) {
				SpawnPickup(Globals::GameController->WorldInventory->Inventory.ItemInstances[i]);
				Globals::GameController->WorldInventory->Inventory.ItemInstances.RemoveAt(i);
				break;
			}
		}
		for (int i = 0; i < Globals::GameController->WorldInventory->Inventory.ReplicatedEntries.Num(); i++) {
			if (Globals::GameController->WorldInventory->Inventory.ReplicatedEntries[i].ItemGuid == ItemGuid) {
				Globals::GameController->WorldInventory->Inventory.ReplicatedEntries.RemoveAt(i);
				break;
			}
		}
		Globals::GameController->QuickBars->ServerRemoveItemInternal(ItemGuid, false, true);
		Globals::GameController->QuickBars->EmptySlot(EFortQuickBars::Primary, ItemSlot);
		Globals::GameController->QuickBars->PrimaryQuickBar.Slots[ItemSlot].Items.Data = nullptr;
		Globals::GameController->QuickBars->PrimaryQuickBar.Slots[ItemSlot].Items.ResetNum();
		Update();
	}

	UFortWorldItem* AddItemToInventory(UFortItemDefinition* ItemDef, int Slot, int Count = 1, EFortQuickBars QBs = EFortQuickBars::Primary) {
		UFortWorldItem* Weapon = (UFortWorldItem*)ItemDef->CreateTemporaryItemInstanceBP(Count, 1);
		Globals::GameController->WorldInventory->Inventory.ReplicatedEntries.Add(Weapon->ItemEntry);
		Globals::GameController->WorldInventory->Inventory.ItemInstances.Add(Weapon);
		Globals::GameController->QuickBars->ServerAddItemInternal(Weapon->GetItemGuid(), QBs, Slot);
		Update();
		return Weapon;
	}

	void HandleNewItem(UFortItemDefinition* ItemDef, int Count = 1) {
		int Slot = GetOpenSlot();
		if (Slot != -1) {
			AddItemToInventory(ItemDef, Slot, Count);
		}
		else {
			FGuid CurrentSlot = {};
			if (Globals::GameController->QuickBars->PrimaryQuickBar.CurrentFocusedSlot != 0) {
				CurrentSlot = Globals::GameController->QuickBars->PrimaryQuickBar.Slots[Globals::GameController->QuickBars->PrimaryQuickBar.CurrentFocusedSlot].Items[0];
			}
			else {
				CurrentSlot = Globals::GameController->QuickBars->PrimaryQuickBar.Slots[1].Items[0];
			}

			DropItem(CurrentSlot);
			AddItemToInventory(ItemDef, Globals::GameController->QuickBars->PrimaryQuickBar.CurrentFocusedSlot, Count);
		}
	}

	void EquipInventoryItem(FGuid ItemGuid) {
		for (int i = 0; i < Globals::GameController->WorldInventory->Inventory.ItemInstances.Num(); i++) {
			// Globals::GameController->WorldInventory->Inventory.ItemInstances[i]->GetItemGuid() == ItemGuid
			if (Helpers::AreGuidsEqual(Globals::GameController->WorldInventory->Inventory.ItemInstances[i]->GetItemGuid(), ItemGuid)) {
				EquipItem(Globals::GameController->WorldInventory->Inventory.ItemInstances[i]);
				break;
			}
		}
	}

	void GiveMaterials() {
		// FortResourceItemDefinition /Game/Items/ResourcePickups/WoodItemData.WoodItemData
		// FortResourceItemDefinition /Game/Items/ResourcePickups/StoneItemData.StoneItemData
		// FortResourceItemDefinition /Game/Items/ResourcePickups/MetalItemData.MetalItemData

		auto WoodItemDef = UObject::FindObject<UFortResourceItemDefinition>("FortResourceItemDefinition WoodItemData.WoodItemData");
		auto StoneItemDef = UObject::FindObject<UFortResourceItemDefinition>("FortResourceItemDefinition StoneItemData.StoneItemData");
		auto MetalItemDef = UObject::FindObject<UFortResourceItemDefinition>("FortResourceItemDefinition MetalItemData.MetalItemData");

		AddItemToInventory(WoodItemDef, 0, 999, EFortQuickBars::Secondary);
		AddItemToInventory(StoneItemDef, 1, 999, EFortQuickBars::Secondary);
		AddItemToInventory(MetalItemDef, 2, 999, EFortQuickBars::Secondary);
	}

	void SetupInventory() {
		Globals::GameController->QuickBars = reinterpret_cast<AFortQuickBars*>(Globals::GameplayStatics->FinishSpawningActor(Globals::GameplayStatics->BeginDeferredActorSpawnFromClass(Globals::Engine->GameViewport->World, AFortQuickBars::StaticClass(), Globals::BaseTransform, ESpawnActorCollisionHandlingMethod::AlwaysSpawn, Globals::GameController), Globals::BaseTransform));
		auto WorldInventory = Globals::GameController->WorldInventory;
		auto Inventory = WorldInventory->Inventory;
		auto Pickaxe = UObject::FindObject<UAthenaPickaxeItemDefinition>("AthenaPickaxeItemDefinition DefaultPickaxe.DefaultPickaxe");
		auto PickaxeWeaponDef = UObject::FindObject<UFortWeaponMeleeItemDefinition>("FortWeaponMeleeItemDefinition WID_Harvest_Pickaxe_Athena_C_T01.WID_Harvest_Pickaxe_Athena_C_T01");

		auto WallItemDef = UObject::FindObject<UFortBuildingItemDefinition>("FortBuildingItemDefinition BuildingItemData_Wall.BuildingItemData_Wall");
		auto StairItemDef = UObject::FindObject<UFortBuildingItemDefinition>("FortBuildingItemDefinition BuildingItemData_Stair_W.BuildingItemData_Stair_W");
		auto ConeItemDef = UObject::FindObject<UFortBuildingItemDefinition>("FortBuildingItemDefinition BuildingItemData_RoofS.BuildingItemData_RoofS");
		auto FloorItemDef = UObject::FindObject<UFortBuildingItemDefinition>("FortBuildingItemDefinition BuildingItemData_Floor.BuildingItemData_Floor");

		EquipItem(AddItemToInventory(PickaxeWeaponDef, 0));

		AddItemToInventory(WallItemDef, 0, 1, EFortQuickBars::Secondary);
		AddItemToInventory(FloorItemDef, 1, 1, EFortQuickBars::Secondary);
		AddItemToInventory(StairItemDef, 2, 1, EFortQuickBars::Secondary);
		AddItemToInventory(ConeItemDef, 3, 1, EFortQuickBars::Secondary);
	}
}