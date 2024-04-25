#pragma once

// Dumped with Dumper-7!

#ifdef _MSC_VER
	#pragma pack(push, 0x01)
#endif

#include "../SDK.hpp"

namespace SDK
{
namespace Params
{
//---------------------------------------------------------------------------------------------------------------------
// PARAMETERS
//---------------------------------------------------------------------------------------------------------------------

// 0x89 (0x89 - 0x0)
// Function GA_Athena_Bush.GA_Athena_Bush_C.K2_CanActivateAbility
struct UGA_Athena_Bush_C_K2_CanActivateAbility_Params
{
public:
	struct FGameplayAbilityActorInfo             ActorInfo;                                         // 0x0(0x40)(BlueprintVisible, BlueprintReadOnly, Parm, ContainsInstancedReference)
	struct FGameplayTagContainer                 RelevantTags;                                      // 0x40(0x20)(Parm, OutParm)
	bool                                         ReturnValue;                                       // 0x60(0x1)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor)
	uint8                                        Pad_5301[0x7];                                     // Fixing Size After Last Property  [ Dumper-7 ]
	class AFortPlayerPawnAthena*                 K2Node_DynamicCast_AsFort_Player_Pawn_Athena;      // 0x68(0x8)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                         K2Node_DynamicCast_bSuccess;                       // 0x70(0x1)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                        Pad_5302[0x7];                                     // Fixing Size After Last Property  [ Dumper-7 ]
	UInterfaceProperty_                          CallFunc_HasMatchingGameplayTag_self_CastInput;    // 0x78(0x10)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                         CallFunc_HasMatchingGameplayTag_ReturnValue;       // 0x88(0x1)(ZeroConstructor, IsPlainOldData, NoDestructor)
};

// 0x28 (0x28 - 0x0)
// Function GA_Athena_Bush.GA_Athena_Bush_C.Completed_6FA77BEE4AD5C961BBDC6682C81BD718
struct UGA_Athena_Bush_C_Completed_6FA77BEE4AD5C961BBDC6682C81BD718_Params
{
public:
	struct FGameplayAbilityTargetDataHandle      TargetData;                                        // 0x0(0x20)(ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
	struct FGameplayTag                          ApplicationTag;                                    // 0x20(0x8)(BlueprintVisible, BlueprintReadOnly, Parm, NoDestructor, HasGetValueTypeHash)
};

// 0x28 (0x28 - 0x0)
// Function GA_Athena_Bush.GA_Athena_Bush_C.Cancelled_6FA77BEE4AD5C961BBDC6682C81BD718
struct UGA_Athena_Bush_C_Cancelled_6FA77BEE4AD5C961BBDC6682C81BD718_Params
{
public:
	struct FGameplayAbilityTargetDataHandle      TargetData;                                        // 0x0(0x20)(ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
	struct FGameplayTag                          ApplicationTag;                                    // 0x20(0x8)(BlueprintVisible, BlueprintReadOnly, Parm, NoDestructor, HasGetValueTypeHash)
};

// 0x28 (0x28 - 0x0)
// Function GA_Athena_Bush.GA_Athena_Bush_C.Triggered_6FA77BEE4AD5C961BBDC6682C81BD718
struct UGA_Athena_Bush_C_Triggered_6FA77BEE4AD5C961BBDC6682C81BD718_Params
{
public:
	struct FGameplayAbilityTargetDataHandle      TargetData;                                        // 0x0(0x20)(ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
	struct FGameplayTag                          ApplicationTag;                                    // 0x20(0x8)(BlueprintVisible, BlueprintReadOnly, Parm, NoDestructor, HasGetValueTypeHash)
};

// 0x0 (0x0 - 0x0)
// Function GA_Athena_Bush.GA_Athena_Bush_C.K2_ActivateAbility
struct UGA_Athena_Bush_C_K2_ActivateAbility_Params
{
public:
};

// 0x270 (0x270 - 0x0)
// Function GA_Athena_Bush.GA_Athena_Bush_C.ExecuteUbergraph_GA_Athena_Bush
struct UGA_Athena_Bush_C_ExecuteUbergraph_GA_Athena_Bush_Params
{
public:
	int32                                        EntryPoint;                                        // 0x0(0x4)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                        Pad_5303[0x4];                                     // Fixing Size After Last Property  [ Dumper-7 ]
	UDelegateProperty_                           K2Node_CreateDelegate_OutputDelegate;              // 0x8(0x10)(ZeroConstructor, NoDestructor)
	bool                                         CallFunc_K2_CommitAbility_ReturnValue;             // 0x18(0x1)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                        Pad_5304[0x7];                                     // Fixing Size After Last Property  [ Dumper-7 ]
	struct FGameplayAbilityTargetDataHandle      Temp_struct_Variable;                              // 0x20(0x20)()
	struct FGameplayTag                          Temp_struct_Variable1;                             // 0x40(0x8)(NoDestructor, HasGetValueTypeHash)
	struct FGameplayAbilityActorInfo             CallFunc_GetActorInfo_ReturnValue;                 // 0x48(0x40)(ContainsInstancedReference)
	struct FGameplayAbilityTargetDataHandle      K2Node_CustomEvent_TargetData1;                    // 0x88(0x20)(ConstParm)
	struct FGameplayTag                          K2Node_CustomEvent_ApplicationTag1;                // 0xA8(0x8)(NoDestructor, HasGetValueTypeHash)
	class AFortPlayerPawn*                       K2Node_DynamicCast_AsFort_Player_Pawn;             // 0xB0(0x8)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                         K2Node_DynamicCast_bSuccess;                       // 0xB8(0x1)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                        Pad_5305[0x7];                                     // Fixing Size After Last Property  [ Dumper-7 ]
	struct FGameplayAbilityTargetDataHandle      CallFunc_AbilityTargetDataFromActor_ReturnValue;   // 0xC0(0x20)()
	TArray<struct FActiveGameplayEffectHandle>   CallFunc_BP_ApplyGameplayEffectToTarget_ReturnValue; // 0xE0(0x10)(ZeroConstructor, ReferenceParm)
	struct FGameplayAbilityTargetDataHandle      K2Node_CustomEvent_TargetData12;                   // 0xF0(0x20)(ConstParm)
	struct FGameplayTag                          K2Node_CustomEvent_ApplicationTag12;               // 0x110(0x8)(NoDestructor, HasGetValueTypeHash)
	UDelegateProperty_                           K2Node_CreateDelegate_OutputDelegate1;             // 0x118(0x10)(ZeroConstructor, NoDestructor)
	UDelegateProperty_                           K2Node_CreateDelegate_OutputDelegate12;            // 0x128(0x10)(ZeroConstructor, NoDestructor)
	bool                                         CallFunc_K2_CommitAbility_ReturnValue1;            // 0x138(0x1)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                        Pad_5306[0x7];                                     // Fixing Size After Last Property  [ Dumper-7 ]
	class UFortAbilityTask_PlayMontageWaitTarget* CallFunc_PlayMontageInfoAndWaitForTrigger_ReturnValue; // 0x140(0x8)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FGameplayCueParameters                K2Node_MakeStruct_GameplayCueParameters;           // 0x148(0xB8)(ContainsInstancedReference)
	bool                                         CallFunc_IsValid_ReturnValue;                      // 0x200(0x1)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                        Pad_5307[0x3];                                     // Fixing Size After Last Property  [ Dumper-7 ]
	struct FActiveGameplayEffectHandle           CallFunc_BP_ApplyGameplayEffectToOwner_ReturnValue; // 0x204(0x8)(NoDestructor, HasGetValueTypeHash)
	uint8                                        Pad_5308[0x4];                                     // Fixing Size After Last Property  [ Dumper-7 ]
	struct FGameplayAbilityTargetDataHandle      K2Node_CustomEvent_TargetData;                     // 0x210(0x20)(ConstParm)
	struct FGameplayTag                          K2Node_CustomEvent_ApplicationTag;                 // 0x230(0x8)(NoDestructor, HasGetValueTypeHash)
	bool                                         CallFunc_IsValid_ReturnValue1;                     // 0x238(0x1)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                        Pad_5309[0x7];                                     // Fixing Size After Last Property  [ Dumper-7 ]
	class AController*                           CallFunc_GetController_ReturnValue;                // 0x240(0x8)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                         CallFunc_IsDBNO_ReturnValue;                       // 0x248(0x1)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                        Pad_530A[0x7];                                     // Fixing Size After Last Property  [ Dumper-7 ]
	class AFortPlayerController*                 K2Node_DynamicCast_AsFort_Player_Controller;       // 0x250(0x8)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                         K2Node_DynamicCast_bSuccess1;                      // 0x258(0x1)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                        Pad_530B[0x7];                                     // Fixing Size After Last Property  [ Dumper-7 ]
	TArray<class AFortPlayerController*>         K2Node_MakeArray_Array;                            // 0x260(0x10)(ZeroConstructor, ReferenceParm)
};

}
}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif