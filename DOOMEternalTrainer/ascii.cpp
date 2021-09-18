#include "stdafx.h"
#include "ascii.h"

void AsciiArt()
{
	std::cout<<"    ________   ________   ________      _____\n";
	std::cout<<"    \\______ \\  \\_____  \\  \\_____  \\    /     \\\n";
	std::cout<<"     |    |  \\  /   |   \\  /   |   \\  /  \\ /  \\\n";
	std::cout<<"     |    `   \\/    |    \\/    |    \\/    Y    \\\n";
	std::cout<<"    /_______  /\\_______  /\\_______  /\\____|__  /\n";
	std::cout<<"            \\/         \\/         \\/         \\/\n";
	std::cout<<"___________  __                                   .__\n";
	std::cout<<"\\_   _____/_/  |_   ____  _______   ____  _____   |  |\n";
	std::cout<<" |    __)_ \\   __\\_/ __ \\ \\_  __ \\ /    \\ \\__  \\  |  |\n";
	std::cout<<" |        \\ |  |  \\  ___/  |  | \\/|   |  \\ / __ \\_|  |__\n";
	std::cout<<"/_______  / |__|   \\___  > |__|   |___|  /(____  /|____/\n";
	std::cout<<"        \\/             \\/              \\/      \\/\n";
	std::cout<<"___________                .__\n";
	std::cout<<"\\__    ___/_______ _____   |__|  ____    ____  _______\n";
	std::cout<<"  |    |   \\_  __ \\\\__  \\  |  | /    \\ _/ __ \\ \\_  __ \\\n";
	std::cout<<"  |    |    |  | \\/ / __ \\_|  ||   |  \\\\  ___/  |  | \\/\n";
	std::cout<<"  |____|    |__|   (____  /|__||___|  / \\___  > |__|\n";
	std::cout<<"                        \\/          \\/      \\/\n\n";
	std::cout<<"                  Ancient Gods Part 2 Update 6.4\n";
	std::cout<<"                                      By: Paradox\n\n";
	std::cout << "press enter to continue...\n";
}

void ClearScreen()
{

	HANDLE hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD count, cellCount;
	COORD homeCoords = { 0,0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE)return;
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi))return;
	cellCount = csbi.dwSize.X * csbi.dwSize.Y;

	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR)' ',
		cellCount,
		homeCoords,
		&count
	))return;

	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
	))return;

	SetConsoleCursorPosition(hStdOut, homeCoords);

}