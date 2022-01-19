#include <iostream>
#include "mem.h"
#include "Player.h"

uintptr_t moduleBase;
HMODULE myhModule;


DWORD __stdcall EjectThread(LPVOID lpParameter) {
	Sleep(100);
	FreeLibraryAndExitThread(myhModule, 0);
}

DWORD WINAPI HackThread(HMODULE hModule)
{
	AllocConsole();
	FILE* fp;
	freopen_s(&fp, "CONOUT$", "w", stdout); // output only
	std::cout << "[+] Entrypoint reached" << std::endl;


	uintptr_t moduleBase = (uintptr_t)GetModuleHandle(NULL);
	DWORD* playerPtr = (DWORD*)((DWORD)moduleBase + 0x1D2D8);
	std::printf("\nsize of `playerPtr`:%u | address of `playerPtr` :%p\n\n", sizeof(playerPtr), *playerPtr);


	Player* pPlayer;
	ZeroMemory(&pPlayer, sizeof(Player));
	pPlayer = reinterpret_cast<Player*>(*playerPtr);
	while (true) {

		if (GetAsyncKeyState(VK_ESCAPE)) {
			pPlayer->health = 100;
			pPlayer->mana = 100;

			std::cout << "\nCurrent player health: " << pPlayer->health << std::endl;
			std::cout << "Current player mana: " << pPlayer->mana << std::endl;
		};

		Sleep(100);
	}

	CreateThread(0, 0, EjectThread, 0, 0, 0);
	return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		myhModule = hModule;
		CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)HackThread, hModule, 0, nullptr));
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}