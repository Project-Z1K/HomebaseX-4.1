#pragma once

// Dumped with Dumper-7!

#ifdef _MSC_VER
	#pragma pack(push, 0x01)
#endif

namespace SDK
{
//---------------------------------------------------------------------------------------------------------------------
// CLASSES
//---------------------------------------------------------------------------------------------------------------------

// 0x19C (0x65C - 0x4C0)
// BlueprintGeneratedClass B_Placement_Preview_AirStrike.B_Placement_Preview_AirStrike_C
class AB_Placement_Preview_AirStrike_C : public AFortDecoPreview
{
public:
	struct FPointerToUberGraphFrame              UberGraphFrame;                                    // 0x4C0(0x8)(Transient, DuplicateTransient)
	class UAudioComponent*                       Airstrike_incoming_place_audiocomponent;           // 0x4C8(0x8)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UStaticMeshComponent*                  GridDecal_Mesh;                                    // 0x4D0(0x8)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UStaticMeshComponent*                  Sm_SupplyDrop_TargetRay_01;                        // 0x4D8(0x8)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UDecalComponent*                       GridDecal;                                         // 0x4E0(0x8)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UBoxComponent*                         Box1;                                              // 0x4E8(0x8)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	float                                        Spawn_Arrow_NewTrack_0_D8CAB91943322A93E0FF2CA94190A798; // 0x4F0(0x4)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	enum class ETimelineDirection                Spawn_Arrow__Direction_D8CAB91943322A93E0FF2CA94190A798; // 0x4F4(0x1)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                        Pad_2E05[0x3];                                     // Fixing Size After Last Property  [ Dumper-7 ]
	class UTimelineComponent*                    Spawn_Arrow;                                       // 0x4F8(0x8)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                        ReticuleRestartDelay;                              // 0x500(0x4)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                        ReticuleIntermittentDelay;                         // 0x504(0x4)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                        BombsDelay;                                        // 0x508(0x4)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                         Can_212_x1_Repeat_;                                // 0x50C(0x1)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	bool                                         Can_212_x2_Repeat_;                                // 0x50D(0x1)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                        Pad_2E06[0x2];                                     // Fixing Size After Last Property  [ Dumper-7 ]
	float                                        DecalRotation;                                     // 0x510(0x4)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                        Dotted_Lines_Amount;                               // 0x514(0x4)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                        Dotted_Lines_Spacing_in_Z;                         // 0x518(0x4)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                        Pad_2E07[0x4];                                     // Fixing Size After Last Property  [ Dumper-7 ]
	TArray<class UStaticMeshComponent*>          Dotted_Lines_Spacing;                              // 0x520(0x10)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance)
	class UMaterialInstanceDynamic*              _3dline_MID;                                       // 0x530(0x8)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                               ArrowheadStartLocation;                            // 0x538(0xC)(Edit, BlueprintVisible, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                               ArrowheadEndLocation;                              // 0x544(0xC)(Edit, BlueprintVisible, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FTransform                            Bomb_Init_Transform;                               // 0x550(0x30)(Edit, BlueprintVisible, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	struct FVector                               Bomb_Start_Location;                               // 0x580(0xC)(Edit, BlueprintVisible, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                        ForLoopCounter;                                    // 0x58C(0x4)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FAirStrikesPatterns                   StrikePatternType;                                 // 0x590(0x10)(Edit, BlueprintVisible, DisableEditOnInstance, HasGetValueTypeHash)
	enum class EStrikePatternEnum                Current_Air_Strike_Pattern;                        // 0x5A0(0x1)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                        Pad_2E08[0x3];                                     // Fixing Size After Last Property  [ Dumper-7 ]
	float                                        SpacingBetweenObjects;                             // 0x5A4(0x4)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TArray<class UParticleSystemComponent*>      Current_Particle_Array;                            // 0x5A8(0x10)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance)
	TArray<struct FVector>                       Position_Array_Cleaned_of_duplicates;              // 0x5B8(0x10)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance)
	TArray<int32>                                Duplicate_Positions;                               // 0x5C8(0x10)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance)
	TArray<int32>                                Double_Entries;                                    // 0x5D8(0x10)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance)
	class UParticleSystem*                       One_Hit_Particle_Indicator;                        // 0x5E8(0x8)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UParticleSystem*                       Two_Hit_Particle_Indicator;                        // 0x5F0(0x8)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TArray<struct FVector>                       Position_Array_With_duplicates;                    // 0x5F8(0x10)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance)
	int32                                        MultiGateIndex;                                    // 0x608(0x4)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                        Pad_2E09[0x4];                                     // Fixing Size After Last Property  [ Dumper-7 ]
	TArray<struct FVector>                       TargetEmitterLocations;                            // 0x610(0x10)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance)
	TArray<float>                                TargetEmitterNewMovementStartTimes;                // 0x620(0x10)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance)
	TArray<class UParticleSystemComponent*>      DefaultPositonParticles;                           // 0x630(0x10)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance)
	class UParticleSystem*                       Default_Location_Template;                         // 0x640(0x8)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UMaterialInstanceDynamic*              Line_MID;                                          // 0x648(0x8)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                         Placement_is_Valid;                                // 0x650(0x1)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	bool                                         Placement_is_Valid_Previously;                     // 0x651(0x1)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	bool                                         Valid_state_changed;                               // 0x652(0x1)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	bool                                         Valid_State_Changed_Override;                      // 0x653(0x1)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	bool                                         Reinit_Particles;                                  // 0x654(0x1)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                         NewVar_0;                                          // 0x655(0x1)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	bool                                         Recreate_particles_if_valid;                       // 0x656(0x1)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                        Pad_2E0A[0x1];                                     // Fixing Size After Last Property  [ Dumper-7 ]
	float                                        Delay_Between_Particle_Spawns;                     // 0x658(0x4)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

	static class UClass* StaticClass()
	{
		static class UClass* Clss = UObject::FindClassFast("B_Placement_Preview_AirStrike_C");
		return Clss;
	}

	void Kill_Emitters_and_Start_Times(int32 Temp_int_Variable, int32 Temp_int_Variable1, int32 CallFunc_Add_IntInt_ReturnValue, int32 CallFunc_Add_IntInt_ReturnValue1, class UParticleSystemComponent* CallFunc_Array_Get_Item, int32 CallFunc_Array_Length_ReturnValue, bool CallFunc_Less_IntInt_ReturnValue, class UParticleSystemComponent* CallFunc_Array_Get_Item1, int32 CallFunc_Array_Length_ReturnValue1, bool CallFunc_Less_IntInt_ReturnValue1);
	void UserConstructionScript();
	void Spawn_Arrow__FinishedFunc();
	void Spawn_Arrow__UpdateFunc();
	void OnBounceMotionUpdate(float VectorScale);
	void OnInitializeDecoPreview(class ABuildingActor* NewBuildingActor, class UFortDecoItemDefinition* NewDecoItemDefinition);
	void OnUpdateScale(float Scale, struct FVector& InWorldSpacePivot);
	void OnUpdateVisuals(float DeltaSeconds, bool bSafeToPlace);
	void SetScalarParameterValueOnAllPreviewMIDs(class FName ParamName, float ParamValue);
	void SetVectorParameterValueOnAllPreviewMIDs(class FName ParamName, struct FLinearColor& ParamValue);
	void SwitchType(TArray<struct FVector>& Positions_With_Duplicates, TArray<struct FVector>& Cleaned_Positions, TArray<int32>& Duplicated_Entries);
	void ReceiveBeginPlay();
	void RestartLineReticule();
	void ToggleAirStrikeParticles(bool bInToggle);
	void ReceiveDestroyed();
	void ExecuteUbergraph_B_Placement_Preview_AirStrike(int32 EntryPoint, const struct FTransform& Temp_struct_Variable, class UParticleSystemComponent* CallFunc_AddComponent_ReturnValue, bool Temp_bool_Variable, TArray<class AActor*>& Temp_object_Variable, bool CallFunc_NotEqual_BoolBool_ReturnValue, bool Temp_bool_Variable1, TArray<class AActor*>& Temp_object_Variable1, int32 Temp_int_Variable, int32 Temp_int_Variable1, int32 CallFunc_Add_IntInt_ReturnValue, int32 CallFunc_Add_IntInt_ReturnValue1, int32 Temp_int_Variable12, int32 Temp_int_Variable123, int32 CallFunc_Add_IntInt_ReturnValue12, int32 CallFunc_Add_IntInt_ReturnValue123, int32 Temp_int_Variable1234, int32 Temp_int_Variable12345, int32 CallFunc_Add_IntInt_ReturnValue1234, int32 CallFunc_Add_IntInt_ReturnValue12345, float K2Node_Event_VectorScale, class ABuildingActor* K2Node_Event_NewBuildingActor, class UFortDecoItemDefinition* K2Node_Event_NewDecoItemDefinition, float K2Node_Event_Scale, const struct FVector& K2Node_Event_InWorldSpacePivot, float K2Node_Event_DeltaSeconds, bool K2Node_Event_bSafeToPlace, class FName K2Node_Event_ParamName1, float K2Node_Event_ParamValue1, class FName K2Node_Event_ParamName, const struct FLinearColor& K2Node_Event_ParamValue, TArray<struct FVector>& K2Node_CustomEvent_Positions_With_Duplicates, TArray<struct FVector>& K2Node_CustomEvent_Cleaned_Positions, TArray<int32>& K2Node_CustomEvent_Duplicated_Entries, int32 Temp_int_Array_Index_Variable, int32 CallFunc_Array_Add_ReturnValue, const struct FVector& CallFunc_Array_Get_Item, bool CallFunc_Array_Contains_ReturnValue, int32 CallFunc_Array_Length_ReturnValue, int32 CallFunc_Add_IntInt_ReturnValue123456, bool CallFunc_Less_IntInt_ReturnValue, int32 CallFunc_Array_LastIndex_ReturnValue, bool CallFunc_IsDedicatedServer_ReturnValue, int32 CallFunc_Add_IntInt_ReturnValue1234567, int32 CallFunc_Percent_IntInt_ReturnValue, float CallFunc_GetRealTimeSeconds_ReturnValue, float CallFunc_Array_Get_Item1, int32 CallFunc_Array_Length_ReturnValue1, float CallFunc_GetRealTimeSeconds_ReturnValue1, const struct FVector& CallFunc_Array_Get_Item12, float CallFunc_Subtract_FloatFloat_ReturnValue, class UParticleSystemComponent* CallFunc_Array_Get_Item123, const struct FTransform& CallFunc_GetTransform_ReturnValue, bool CallFunc_IsValid_ReturnValue, const struct FVector& CallFunc_TransformLocation_ReturnValue, const struct FVector& K2Node_Select_Default, const struct FVector& CallFunc_K2_GetComponentLocation_ReturnValue, const struct FVector& CallFunc_Subtract_VectorVector_ReturnValue, const struct FVector& CallFunc_VInterpTo_ReturnValue, const struct FVector& CallFunc_Add_VectorVector_ReturnValue, const struct FHitResult& CallFunc_K2_SetWorldLocation_SweepHitResult, const struct FHitResult& CallFunc_LineTraceSingle_OutHit, bool CallFunc_LineTraceSingle_ReturnValue, int32 Temp_int_Loop_Counter_Variable, bool CallFunc_BreakHitResult_bBlockingHit, bool CallFunc_BreakHitResult_bInitialOverlap, float CallFunc_BreakHitResult_Time, float CallFunc_BreakHitResult_Distance, const struct FVector& CallFunc_BreakHitResult_Location, const struct FVector& CallFunc_BreakHitResult_ImpactPoint, const struct FVector& CallFunc_BreakHitResult_Normal, const struct FVector& CallFunc_BreakHitResult_ImpactNormal, class UPhysicalMaterial* CallFunc_BreakHitResult_PhysMat, class AActor* CallFunc_BreakHitResult_HitActor, class UPrimitiveComponent* CallFunc_BreakHitResult_HitComponent, class FName CallFunc_BreakHitResult_HitBoneName, int32 CallFunc_BreakHitResult_HitItem, int32 CallFunc_BreakHitResult_FaceIndex, const struct FVector& CallFunc_BreakHitResult_TraceStart, const struct FVector& CallFunc_BreakHitResult_TraceEnd, const struct FVector& CallFunc_Add_VectorVector_ReturnValue1, bool CallFunc_Less_IntInt_ReturnValue1, const struct FHitResult& CallFunc_K2_SetWorldLocation_SweepHitResult1, int32 CallFunc_Add_IntInt_ReturnValue12345678, int32 CallFunc_Add_IntInt_ReturnValue123456789, const struct FTransform& CallFunc_GetTransform_ReturnValue1, class UParticleSystemComponent* CallFunc_Array_Get_Item1234, bool CallFunc_IsValid_ReturnValue1, const struct FVector& CallFunc_K2_GetComponentLocation_ReturnValue1, const struct FVector& CallFunc_TransformLocation_ReturnValue1, bool K2Node_CustomEvent_bInToggle, const struct FVector& K2Node_Select1_Default, const struct FVector& CallFunc_Subtract_VectorVector_ReturnValue1, class UParticleSystemComponent* CallFunc_Array_Get_Item12345, int32 CallFunc_Array_Length_ReturnValue12, bool CallFunc_Less_IntInt_ReturnValue12, class UParticleSystemComponent* CallFunc_Array_Get_Item123456, int32 CallFunc_Array_Length_ReturnValue123, class UParticleSystemComponent* CallFunc_Array_Get_Item1234567, bool CallFunc_Less_IntInt_ReturnValue123, int32 CallFunc_Array_Length_ReturnValue1234, const struct FVector& CallFunc_Add_VectorVector_ReturnValue12, bool CallFunc_Less_IntInt_ReturnValue1234, const struct FHitResult& CallFunc_LineTraceSingle_OutHit1, bool CallFunc_LineTraceSingle_ReturnValue1, bool CallFunc_BreakHitResult_bBlockingHit1, bool CallFunc_BreakHitResult_bInitialOverlap1, float CallFunc_BreakHitResult_Time1, float CallFunc_BreakHitResult_Distance1, const struct FVector& CallFunc_BreakHitResult_Location1, const struct FVector& CallFunc_BreakHitResult_ImpactPoint1, const struct FVector& CallFunc_BreakHitResult_Normal1, const struct FVector& CallFunc_BreakHitResult_ImpactNormal1, class UPhysicalMaterial* CallFunc_BreakHitResult_PhysMat1, class AActor* CallFunc_BreakHitResult_HitActor1, class UPrimitiveComponent* CallFunc_BreakHitResult_HitComponent1, class FName CallFunc_BreakHitResult_HitBoneName1, int32 CallFunc_BreakHitResult_HitItem1, int32 CallFunc_BreakHitResult_FaceIndex1, const struct FVector& CallFunc_BreakHitResult_TraceStart1, const struct FVector& CallFunc_BreakHitResult_TraceEnd1, const struct FVector& CallFunc_Add_VectorVector_ReturnValue123, class UParticleSystemComponent* CallFunc_Array_Get_Item12345678, int32 CallFunc_Array_Length_ReturnValue12345, class UParticleSystemComponent* CallFunc_Array_Get_Item123456789, bool CallFunc_Less_IntInt_ReturnValue12345, int32 CallFunc_Array_Length_ReturnValue123456, class UParticleSystemComponent* CallFunc_Array_Get_Item12345678910, bool CallFunc_Less_IntInt_ReturnValue123456, int32 CallFunc_Array_Length_ReturnValue1234567, bool CallFunc_Less_IntInt_ReturnValue1234567, bool Temp_bool_Variable12, class UParticleSystem* K2Node_Select12_Default);
};

}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
