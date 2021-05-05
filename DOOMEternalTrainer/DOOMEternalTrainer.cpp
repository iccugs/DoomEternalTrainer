// DOOM Eternal Trainer for Ancient Gods Part 2
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <Windows.h>
#include "proc.h"
#include "mem.h"
#include "ascii.h"

int main()
{	
	//put variables here


	HANDLE hProcess = 0;

	uintptr_t moduleBase = 0, playerPtr = 0, healthAddr = 0;
	bool bHealth = false, bAmmo = false, bSword = false, bHammer = false, bGrenades = false, bFlame = false, bDash = false, bPunch = false;

	const float maxHealth = 999;

	DWORD procId = GetProcId(L"DOOMEternalx64vk.exe");

	//look for doom eternal process
	if (procId)
	{
		hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, procId);

		//set console colors
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 12);
		AsciiArt();
		getchar();
		ClearScreen();
		AsciiMenu();
		std::cout << "Infinite Health = " << bHealth << std::endl;
		std::cout << "Infinite Ammo = " << bAmmo << std::endl;
		std::cout << "Infinite Sword = " << bSword << std::endl;
		std::cout << "Infinite Hammer = " << bHammer << std::endl;
		std::cout << "Infinite Grenades = " << bGrenades << std::endl;
		std::cout << "Infinite Flamethrower = " << bFlame << std::endl;
		std::cout << "Infinite Dash = " << bDash << std::endl;
		std::cout << "Infinite Blood Punch = " << bPunch << std::endl;
	}
	//exit trainer if process not found
	else
	{
		std::cout << "DOOMEternal process not found, press enter to exit\n";
		getchar();
		return 0;
	}
	

	DWORD dwExit = 0;

	while (GetExitCodeProcess(hProcess, &dwExit) && dwExit == STILL_ACTIVE)
	{
		//infinite health toggle
		if (GetAsyncKeyState(VK_NUMPAD0) & 1)
		{
			bHealth = !bHealth;

			if (bHealth)
			{
				ClearScreen();
				AsciiMenu();
				std::cout << "Infinite Health = " << bHealth << std::endl;
				std::cout << "Infinite Ammo = " << bAmmo << std::endl;
				std::cout << "Infinite Sword = " << bSword << std::endl;
				std::cout << "Infinite Hammer = " << bHammer << std::endl;
				std::cout << "Infinite Grenades = " << bGrenades << std::endl;
				std::cout << "Infinite Flamethrower = " << bFlame << std::endl;
				std::cout << "Infinite Dash = " << bDash << std::endl;
				std::cout << "Infinite Blood Punch = " << bPunch << std::endl;
			}
			else
			{
				ClearScreen();
				AsciiMenu();
				std::cout << "Infinite Health = " << bHealth << std::endl;
				std::cout << "Infinite Ammo = " << bAmmo << std::endl;
				std::cout << "Infinite Sword = " << bSword << std::endl;
				std::cout << "Infinite Hammer = " << bHammer << std::endl;
				std::cout << "Infinite Grenades = " << bGrenades << std::endl;
				std::cout << "Infinite Flamethrower = " << bFlame << std::endl;
				std::cout << "Infinite Dash = " << bDash << std::endl;
				std::cout << "Infinite Blood Punch = " << bPunch << std::endl;
			}
		}
		
		//continuous write to health
		if (bHealth)
		{
			//pointer scan for health address
			moduleBase = GetModuleBaseAddress(procId, L"DOOMEternalx64vk.exe");
			playerPtr = moduleBase + 0x0660D210;
			healthAddr = FindDMAAddy(hProcess, playerPtr, { 0x00, 0x20, 0x74 });
			mem::PatchEx((BYTE*)healthAddr, (BYTE*)&maxHealth, sizeof(maxHealth), hProcess);
		}

		//infinite ammo
		if (GetAsyncKeyState(VK_NUMPAD1) & 1)
		{
			bAmmo = !bAmmo;

			if (bAmmo)
			{
				mem::NopEx((BYTE*)(moduleBase + 0x1B1C678), 3, hProcess);
				ClearScreen();
				AsciiMenu();
				std::cout << "Infinite Health = " << bHealth << std::endl;
				std::cout << "Infinite Ammo = " << bAmmo << std::endl;
				std::cout << "Infinite Sword = " << bSword << std::endl;
				std::cout << "Infinite Hammer = " << bHammer << std::endl;
				std::cout << "Infinite Grenades = " << bGrenades << std::endl;
				std::cout << "Infinite Flamethrower = " << bFlame << std::endl;
				std::cout << "Infinite Dash = " << bDash << std::endl;
				std::cout << "Infinite Blood Punch = " << bPunch << std::endl;
			}
			else
			{
				mem::PatchEx((BYTE*)(moduleBase + 0x1B1C678), (BYTE*)"\x01\x73\x40", 3, hProcess);
				ClearScreen();
				AsciiMenu();
				std::cout << "Infinite Health = " << bHealth << std::endl;
				std::cout << "Infinite Ammo = " << bAmmo << std::endl;
				std::cout << "Infinite Sword = " << bSword << std::endl;
				std::cout << "Infinite Hammer = " << bHammer << std::endl;
				std::cout << "Infinite Grenades = " << bGrenades << std::endl;
				std::cout << "Infinite Flamethrower = " << bFlame << std::endl;
				std::cout << "Infinite Dash = " << bDash << std::endl;
				std::cout << "Infinite Blood Punch = " << bPunch << std::endl;
			}
		}

		//infinite sword
		if (GetAsyncKeyState(VK_NUMPAD2) & 1)
		{
			bSword = !bSword;

			if (bSword)
			{
				mem::NopEx((BYTE*)(moduleBase + 0x1750062), 5, hProcess);
				ClearScreen();
				AsciiMenu();
				std::cout << "Infinite Health = " << bHealth << std::endl;
				std::cout << "Infinite Ammo = " << bAmmo << std::endl;
				std::cout << "Infinite Sword = " << bSword << std::endl;
				std::cout << "Infinite Hammer = " << bHammer << std::endl;
				std::cout << "Infinite Grenades = " << bGrenades << std::endl;
				std::cout << "Infinite Flamethrower = " << bFlame << std::endl;
				std::cout << "Infinite Dash = " << bDash << std::endl;
				std::cout << "Infinite Blood Punch = " << bPunch << std::endl;
			}
			else
			{
				mem::PatchEx((BYTE*)(moduleBase + 0x1750062), (BYTE*)"\xF3\x0F\x11\x5B\x08", 5, hProcess);
				ClearScreen();
				AsciiMenu();
				std::cout << "Infinite Health = " << bHealth << std::endl;
				std::cout << "Infinite Ammo = " << bAmmo << std::endl;
				std::cout << "Infinite Sword = " << bSword << std::endl;
				std::cout << "Infinite Hammer = " << bHammer << std::endl;
				std::cout << "Infinite Grenades = " << bGrenades << std::endl;
				std::cout << "Infinite Flamethrower = " << bFlame << std::endl;
				std::cout << "Infinite Dash = " << bDash << std::endl;
				std::cout << "Infinite Blood Punch = " << bPunch << std::endl;
			}
		}

		//infinite hammer and chainsaw
		if (GetAsyncKeyState(VK_NUMPAD3) & 1)
		{
			bHammer = !bHammer;

			if (bHammer)
			{
				mem::NopEx((BYTE*)(moduleBase + 0x1B1188C), 7, hProcess);
				ClearScreen();
				AsciiMenu();
				std::cout << "Infinite Health = " << bHealth << std::endl;
				std::cout << "Infinite Ammo = " << bAmmo << std::endl;
				std::cout << "Infinite Sword = " << bSword << std::endl;
				std::cout << "Infinite Hammer = " << bHammer << std::endl;
				std::cout << "Infinite Grenades = " << bGrenades << std::endl;
				std::cout << "Infinite Flamethrower = " << bFlame << std::endl;
				std::cout << "Infinite Dash = " << bDash << std::endl;
				std::cout << "Infinite Blood Punch = " << bPunch << std::endl;
			}
			else
			{
				mem::PatchEx((BYTE*)(moduleBase + 0x1B1188C), (BYTE*)"\x44\x89\xA8\x04\x67\x02\x00", 7, hProcess);
				ClearScreen();
				AsciiMenu();
				std::cout << "Infinite Health = " << bHealth << std::endl;
				std::cout << "Infinite Ammo = " << bAmmo << std::endl;
				std::cout << "Infinite Sword = " << bSword << std::endl;
				std::cout << "Infinite Hammer = " << bHammer << std::endl;
				std::cout << "Infinite Grenades = " << bGrenades << std::endl;
				std::cout << "Infinite Flamethrower = " << bFlame << std::endl;
				std::cout << "Infinite Dash = " << bDash << std::endl;
				std::cout << "Infinite Blood Punch = " << bPunch << std::endl;
			}
		}

		//infinite grenades
		if (GetAsyncKeyState(VK_NUMPAD4) & 1)
		{
			bGrenades = !bGrenades;

			if (bGrenades)
			{
				mem::PatchEx((BYTE*)(moduleBase + 0x9FE4003), (BYTE*)"\xEB", 1, hProcess);
				ClearScreen();
				AsciiMenu();
				std::cout << "Infinite Health = " << bHealth << std::endl;
				std::cout << "Infinite Ammo = " << bAmmo << std::endl;
				std::cout << "Infinite Sword = " << bSword << std::endl;
				std::cout << "Infinite Hammer = " << bHammer << std::endl;
				std::cout << "Infinite Grenades = " << bGrenades << std::endl;
				std::cout << "Infinite Flamethrower = " << bFlame << std::endl;
				std::cout << "Infinite Dash = " << bDash << std::endl;
				std::cout << "Infinite Blood Punch = " << bPunch << std::endl;
			}
			else
			{
				mem::PatchEx((BYTE*)(moduleBase + 0x9FE4003), (BYTE*)"\x75", 1, hProcess);
				ClearScreen();
				AsciiMenu();
				std::cout << "Infinite Health = " << bHealth << std::endl;
				std::cout << "Infinite Ammo = " << bAmmo << std::endl;
				std::cout << "Infinite Sword = " << bSword << std::endl;
				std::cout << "Infinite Hammer = " << bHammer << std::endl;
				std::cout << "Infinite Grenades = " << bGrenades << std::endl;
				std::cout << "Infinite Flamethrower = " << bFlame << std::endl;
				std::cout << "Infinite Dash = " << bDash << std::endl;
				std::cout << "Infinite Blood Punch = " << bPunch << std::endl;
			}
		}

		//infinite flamethrower
		if (GetAsyncKeyState(VK_NUMPAD5) & 1)
		{
			bFlame = !bFlame;

			if (bFlame)
			{
				mem::PatchEx((BYTE*)(moduleBase + 0x9FE40A1), (BYTE*)"\xEB", 1, hProcess);
				ClearScreen();
				AsciiMenu();
				std::cout << "Infinite Health = " << bHealth << std::endl;
				std::cout << "Infinite Ammo = " << bAmmo << std::endl;
				std::cout << "Infinite Sword = " << bSword << std::endl;
				std::cout << "Infinite Hammer = " << bHammer << std::endl;
				std::cout << "Infinite Grenades = " << bGrenades << std::endl;
				std::cout << "Infinite Flamethrower = " << bFlame << std::endl;
				std::cout << "Infinite Dash = " << bDash << std::endl;
				std::cout << "Infinite Blood Punch = " << bPunch << std::endl;
			}
			else
			{
				mem::PatchEx((BYTE*)(moduleBase + 0x9FE40A1), (BYTE*)"\x75", 1, hProcess);
				ClearScreen();
				AsciiMenu();
				std::cout << "Infinite Health = " << bHealth << std::endl;
				std::cout << "Infinite Ammo = " << bAmmo << std::endl;
				std::cout << "Infinite Sword = " << bSword << std::endl;
				std::cout << "Infinite Hammer = " << bHammer << std::endl;
				std::cout << "Infinite Grenades = " << bGrenades << std::endl;
				std::cout << "Infinite Flamethrower = " << bFlame << std::endl;
				std::cout << "Infinite Dash = " << bDash << std::endl;
				std::cout << "Infinite Blood Punch = " << bPunch << std::endl;
			}
		}

		//infinite dash
		if (GetAsyncKeyState(VK_NUMPAD6) & 1)
		{
			bDash = !bDash;

			if (bDash)
			{
				mem::NopEx((BYTE*)(moduleBase + 0x174FDCA), 5, hProcess);
				ClearScreen();
				AsciiMenu();
				std::cout << "Infinite Health = " << bHealth << std::endl;
				std::cout << "Infinite Ammo = " << bAmmo << std::endl;
				std::cout << "Infinite Sword = " << bSword << std::endl;
				std::cout << "Infinite Hammer = " << bHammer << std::endl;
				std::cout << "Infinite Grenades = " << bGrenades << std::endl;
				std::cout << "Infinite Flamethrower = " << bFlame << std::endl;
				std::cout << "Infinite Dash = " << bDash << std::endl;
				std::cout << "Infinite Blood Punch = " << bPunch << std::endl;
			}
			else
			{
				mem::PatchEx((BYTE*)(moduleBase + 0x174FDCA), (BYTE*)"\xF3\x0F\x11\x5F\x08", 5, hProcess);
				ClearScreen();
				AsciiMenu();
				std::cout << "Infinite Health = " << bHealth << std::endl;
				std::cout << "Infinite Ammo = " << bAmmo << std::endl;
				std::cout << "Infinite Sword = " << bSword << std::endl;
				std::cout << "Infinite Hammer = " << bHammer << std::endl;
				std::cout << "Infinite Grenades = " << bGrenades << std::endl;
				std::cout << "Infinite Flamethrower = " << bFlame << std::endl;
				std::cout << "Infinite Dash = " << bDash << std::endl;
				std::cout << "Infinite Blood Punch = " << bPunch << std::endl;
			}
		}

		//infinite blood punch
		if (GetAsyncKeyState(VK_NUMPAD7) & 1)
		{
			bPunch = !bPunch;

			if (bPunch)
			{
				mem::PatchEx((BYTE*)(moduleBase + 0x1AD5989), (BYTE*)"\xEB", 1, hProcess);
				ClearScreen();
				AsciiMenu();
				std::cout << "Infinite Health = " << bHealth << std::endl;
				std::cout << "Infinite Ammo = " << bAmmo << std::endl;
				std::cout << "Infinite Sword = " << bSword << std::endl;
				std::cout << "Infinite Hammer = " << bHammer << std::endl;
				std::cout << "Infinite Grenades = " << bGrenades << std::endl;
				std::cout << "Infinite Flamethrower = " << bFlame << std::endl;
				std::cout << "Infinite Dash = " << bDash << std::endl;
				std::cout << "Infinite Blood Punch = " << bPunch << std::endl;
			}
			else
			{
				mem::PatchEx((BYTE*)(moduleBase + 0x1AD5989), (BYTE*)"\x75", 1, hProcess);
				ClearScreen();
				AsciiMenu();
				std::cout << "Infinite Health = " << bHealth << std::endl;
				std::cout << "Infinite Ammo = " << bAmmo << std::endl;
				std::cout << "Infinite Sword = " << bSword << std::endl;
				std::cout << "Infinite Hammer = " << bHammer << std::endl;
				std::cout << "Infinite Grenades = " << bGrenades << std::endl;
				std::cout << "Infinite Flamethrower = " << bFlame << std::endl;
				std::cout << "Infinite Dash = " << bDash << std::endl;
				std::cout << "Infinite Blood Punch = " << bPunch << std::endl;
			}
		}

		//exit
		if (GetAsyncKeyState(VK_INSERT) & 1)
		{
			return 0;
		}

		Sleep(500);
	}
	ClearScreen();
	std::cout << "DOOMEternal process not found, press enter to exit\n";
	getchar();
	return 0;
}