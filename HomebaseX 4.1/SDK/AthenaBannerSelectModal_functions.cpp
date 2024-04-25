#pragma once

// Dumped with Dumper-7!

#ifdef _MSC_VER
	#pragma pack(push, 0x01)
#endif

#include "../SDK.hpp"

namespace SDK
{
//---------------------------------------------------------------------------------------------------------------------
// FUNCTIONS
//---------------------------------------------------------------------------------------------------------------------


// Function AthenaBannerSelectModal.AthenaBannerSelectModal_C.HandleNextAction
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                               Passthrough                                                      (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UAthenaBannerSelectModal_C::HandleNextAction(bool* Passthrough)
{
	static auto Func = Class->GetFunction("AthenaBannerSelectModal_C", "HandleNextAction");

	Params::UAthenaBannerSelectModal_C_HandleNextAction_Params Parms;

	UObject::ProcessEvent(Func, &Parms);

	if (Passthrough != nullptr)
		*Passthrough = Parms.Passthrough;

}


// Function AthenaBannerSelectModal.AthenaBannerSelectModal_C.HandlePreviousAction
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                               Passthrough                                                      (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UAthenaBannerSelectModal_C::HandlePreviousAction(bool* Passthrough)
{
	static auto Func = Class->GetFunction("AthenaBannerSelectModal_C", "HandlePreviousAction");

	Params::UAthenaBannerSelectModal_C_HandlePreviousAction_Params Parms;

	UObject::ProcessEvent(Func, &Parms);

	if (Passthrough != nullptr)
		*Passthrough = Parms.Passthrough;

}


// Function AthenaBannerSelectModal.AthenaBannerSelectModal_C.Setup Input Action Handlers
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// UDelegateProperty_                 K2Node_CreateDelegate_OutputDelegate                             (ZeroConstructor, NoDestructor)
// UDelegateProperty_                 K2Node_CreateDelegate_OutputDelegate1                            (ZeroConstructor, NoDestructor)
// UDelegateProperty_                 K2Node_CreateDelegate_OutputDelegate12                           (ZeroConstructor, NoDestructor)

void UAthenaBannerSelectModal_C::Setup_Input_Action_Handlers(UDelegateProperty_ K2Node_CreateDelegate_OutputDelegate, UDelegateProperty_ K2Node_CreateDelegate_OutputDelegate1, UDelegateProperty_ K2Node_CreateDelegate_OutputDelegate12)
{
	static auto Func = Class->GetFunction("AthenaBannerSelectModal_C", "Setup Input Action Handlers");

	Params::UAthenaBannerSelectModal_C_Setup_Input_Action_Handlers_Params Parms;
	Parms.K2Node_CreateDelegate_OutputDelegate = K2Node_CreateDelegate_OutputDelegate;
	Parms.K2Node_CreateDelegate_OutputDelegate1 = K2Node_CreateDelegate_OutputDelegate1;
	Parms.K2Node_CreateDelegate_OutputDelegate12 = K2Node_CreateDelegate_OutputDelegate12;

	UObject::ProcessEvent(Func, &Parms);

}


// Function AthenaBannerSelectModal.AthenaBannerSelectModal_C.HandleCloseAction
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                               Passthrough                                                      (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
// class UFortUIManagerWidget_NUI*    CallFunc_GetUIManagerWidget_ReturnValue                          (ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UAthenaBannerSelectModal_C::HandleCloseAction(bool* Passthrough, class UFortUIManagerWidget_NUI* CallFunc_GetUIManagerWidget_ReturnValue)
{
	static auto Func = Class->GetFunction("AthenaBannerSelectModal_C", "HandleCloseAction");

	Params::UAthenaBannerSelectModal_C_HandleCloseAction_Params Parms;
	Parms.CallFunc_GetUIManagerWidget_ReturnValue = CallFunc_GetUIManagerWidget_ReturnValue;

	UObject::ProcessEvent(Func, &Parms);

	if (Passthrough != nullptr)
		*Passthrough = Parms.Passthrough;

}


// Function AthenaBannerSelectModal.AthenaBannerSelectModal_C.Construct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)
// Parameters:

void UAthenaBannerSelectModal_C::Construct()
{
	static auto Func = Class->GetFunction("AthenaBannerSelectModal_C", "Construct");

	Params::UAthenaBannerSelectModal_C_Construct_Params Parms;

	UObject::ProcessEvent(Func, &Parms);

}


// Function AthenaBannerSelectModal.AthenaBannerSelectModal_C.BndEvt__BP_LocalPlayerProfileManagement_K2Node_ComponentBoundEvent_14_CloseProfileModal__DelegateSignature
// (BlueprintEvent)
// Parameters:

void UAthenaBannerSelectModal_C::BndEvt__BP_LocalPlayerProfileManagement_K2Node_ComponentBoundEvent_14_CloseProfileModal__DelegateSignature()
{
	static auto Func = Class->GetFunction("AthenaBannerSelectModal_C", "BndEvt__BP_LocalPlayerProfileManagement_K2Node_ComponentBoundEvent_14_CloseProfileModal__DelegateSignature");

	Params::UAthenaBannerSelectModal_C_BndEvt__BP_LocalPlayerProfileManagement_K2Node_ComponentBoundEvent_14_CloseProfileModal__DelegateSignature_Params Parms;

	UObject::ProcessEvent(Func, &Parms);

}


// Function AthenaBannerSelectModal.AthenaBannerSelectModal_C.BndEvt__BP_LocalPlayerBannerEditor_K2Node_ComponentBoundEvent_18_CloseBannerEditor__DelegateSignature
// (BlueprintEvent)
// Parameters:
// class FName                        IconId                                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class FName                        ColorId                                                          (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UAthenaBannerSelectModal_C::BndEvt__BP_LocalPlayerBannerEditor_K2Node_ComponentBoundEvent_18_CloseBannerEditor__DelegateSignature(class FName IconId, class FName ColorId)
{
	static auto Func = Class->GetFunction("AthenaBannerSelectModal_C", "BndEvt__BP_LocalPlayerBannerEditor_K2Node_ComponentBoundEvent_18_CloseBannerEditor__DelegateSignature");

	Params::UAthenaBannerSelectModal_C_BndEvt__BP_LocalPlayerBannerEditor_K2Node_ComponentBoundEvent_18_CloseBannerEditor__DelegateSignature_Params Parms;
	Parms.IconId = IconId;
	Parms.ColorId = ColorId;

	UObject::ProcessEvent(Func, &Parms);

}


// Function AthenaBannerSelectModal.AthenaBannerSelectModal_C.OnDeactivated
// (Event, Protected, BlueprintEvent)
// Parameters:

void UAthenaBannerSelectModal_C::OnDeactivated()
{
	static auto Func = Class->GetFunction("AthenaBannerSelectModal_C", "OnDeactivated");

	Params::UAthenaBannerSelectModal_C_OnDeactivated_Params Parms;

	UObject::ProcessEvent(Func, &Parms);

}


// Function AthenaBannerSelectModal.AthenaBannerSelectModal_C.OnActivated
// (Event, Protected, BlueprintEvent)
// Parameters:

void UAthenaBannerSelectModal_C::OnActivated()
{
	static auto Func = Class->GetFunction("AthenaBannerSelectModal_C", "OnActivated");

	Params::UAthenaBannerSelectModal_C_OnActivated_Params Parms;

	UObject::ProcessEvent(Func, &Parms);

}


// Function AthenaBannerSelectModal.AthenaBannerSelectModal_C.ExecuteUbergraph_AthenaBannerSelectModal
// ()
// Parameters:
// int32                              EntryPoint                                                       (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class FName                        K2Node_ComponentBoundEvent_IconId                                (ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class FName                        K2Node_ComponentBoundEvent_ColorId                               (ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                               CallFunc_HandleCloseAction_PassThrough                           (ZeroConstructor, IsPlainOldData, NoDestructor)
// bool                               CallFunc_HandleCloseAction_PassThrough1                          (ZeroConstructor, IsPlainOldData, NoDestructor)

void UAthenaBannerSelectModal_C::ExecuteUbergraph_AthenaBannerSelectModal(int32 EntryPoint, class FName K2Node_ComponentBoundEvent_IconId, class FName K2Node_ComponentBoundEvent_ColorId, bool CallFunc_HandleCloseAction_PassThrough, bool CallFunc_HandleCloseAction_PassThrough1)
{
	static auto Func = Class->GetFunction("AthenaBannerSelectModal_C", "ExecuteUbergraph_AthenaBannerSelectModal");

	Params::UAthenaBannerSelectModal_C_ExecuteUbergraph_AthenaBannerSelectModal_Params Parms;
	Parms.EntryPoint = EntryPoint;
	Parms.K2Node_ComponentBoundEvent_IconId = K2Node_ComponentBoundEvent_IconId;
	Parms.K2Node_ComponentBoundEvent_ColorId = K2Node_ComponentBoundEvent_ColorId;
	Parms.CallFunc_HandleCloseAction_PassThrough = CallFunc_HandleCloseAction_PassThrough;
	Parms.CallFunc_HandleCloseAction_PassThrough1 = CallFunc_HandleCloseAction_PassThrough1;

	UObject::ProcessEvent(Func, &Parms);

}

}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
