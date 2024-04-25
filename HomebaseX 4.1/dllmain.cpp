// Homebase X - 4.1
#include <Windows.h>
#include "MinHook.h"
#include "SDK.hpp"
#include "Globals.h"
#include "Game.h"
#include <detours.h>
#include "UI.h"

using namespace SDK;

void InitalizeOthers() {
    Globals::Engine = UObject::FindObjectFast<UFortEngine>("FortEngine_0");
    Globals::World = Globals::Engine->GameViewport->World;
    Globals::GameplayStatics = UObject::FindObjectFast<UGameplayStatics>("Default__GameplayStatics");
    Globals::KismetString = UObject::FindObjectFast<UKismetStringLibrary>("Default__KismetStringLibrary");
    if (Helpers::IsNull(Globals::KismetString)) {
        printf("\n\n\nKISMETSTRING IS NULL\n\n\n");
    }
    Globals::LocalController = Globals::Engine->GameInstance->LocalPlayers[0]->PlayerController; // use only in lobby I beg you
    uintptr_t ProcessEventAddr = (uintptr_t(GetModuleHandle(0)) + Offsets::ProcessEvent);
    Globals::ProcessEvent = decltype(Globals::ProcessEvent)(ProcessEventAddr);
    Globals::Engine->GameViewport->ViewportConsole = reinterpret_cast<UConsole*>(Globals::GameplayStatics->SpawnObject(UConsole::StaticClass(), Globals::Engine->GameViewport));
}

DWORD WINAPI Main(LPVOID) {
    FILE* K;
    AllocConsole();
    freopen_s(&K, "CONOUT$", "w", stdout);

    MH_Initialize();

    InitGObjects();

    Globals::CreateDefaultObject = decltype(Globals::CreateDefaultObject)(uintptr_t(GetModuleHandle(0)) + Offsets::CreateDefaultObj);

    Globals::BaseTransform.Scale3D = { 1,1,1 };

    InitalizeOthers();

    UI::Init();
    UI::ShowWindow();

    auto welcome = R"(
  _    _                      ____                __   __
 | |  | |                    |  _ \               \ \ / /
 | |__| | ___  _ __ ___   ___| |_) | __ _ ___  ___ \ V / 
 |  __  |/ _ \| '_ ` _ \ / _ \  _ < / _` / __|/ _ \ > <  
 | |  | | (_) | | | | | |  __/ |_) | (_| \__ \  __// . \ 
 |_|  |_|\___/|_| |_| |_|\___|____/ \__,_|___/\___/_/ \_\
                                                         
    
Welcome to HomebaseX!
Created by @whisperends on Discord.
Contributors: @nax1800

Discord: https://discord.gg/hMw32VDPwt

                                               
)";

    printf(welcome);

    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    DetourAttach(&(PVOID&)Globals::ProcessEvent, Game::FNHook);
    DetourTransactionCommit();

    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0, Main, 0, 0, 0);
        break;
    }
    return TRUE;
}

