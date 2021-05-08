#include "stdafx.h"
#include "ascii.h"

void AsciiArt()
{
	std::cout << "    ________   ________   ________      _____           \n";
	std::cout << "    \\______ \\  \\_____  \\  \\_____  \\    /     \\          \n";
	std::cout << "     |    |  \\  /   |   \\  /   |   \\  /  \\ /  \\         \n";
	std::cout << "     |    `   \\/    |    \\/    |    \\/    Y    \\        \n";
	std::cout << "    /_______  /\\_______  /\\_______  /\\____|__  /        \n";
	std::cout << "            \\/         \\/         \\/         \\/         \n";
	std::cout << "___________  __                                   .__   \n";
	std::cout << "\\_   _____/_/  |_   ____  _______   ____  _____   |  |  \n";
	std::cout << " |    __)_ \\   __\\_/ __ \\ \\_  __ \\ /    \\ \\__  \\  |  |  \n";
	std::cout << " |        \\ |  |  \\  ___/  |  | \\/|   |  \\ / __ \\_|  |__\n";
	std::cout << "/_______  / |__|   \\___  > |__|   |___|  /(____  /|____/\n";
	std::cout << "        \\/             \\/              \\/      \\/       \n";
	std::cout << "___________                .__                          \n";
	std::cout << "\\__    ___/_______ _____   |__|  ____    ____  _______  \n";
	std::cout << "  |    |   \\_  __ \\\\__  \\  |  | /    \\ _/ __ \\ \\_  __ \\ \n";
	std::cout << "  |    |    |  | \\/ / __ \\_|  ||   |  \\\\  ___/  |  | \\/ \n";
	std::cout << "  |____|    |__|   (____  /|__||___|  / \\___  > |__|    \n";
	std::cout << "                        \\/          \\/      \\/          \n\n";
	std::cout << "                  Ancient Gods Part 2\n";
	std::cout << "                                      By: Paradox\n\n";
	std::cout << "press enter to continue..." << std::endl;
}

void AsciiMenu()
{
	std::cout << "TOGGLE FUNCTIONS:\n";
	std::cout << "NUM0 = infinite health\n";
	std::cout << "NUM1 = infinite armor\n";
	std::cout << "NUM2 = infinite rad/o2\n";
	std::cout << "NUM3 = infinite ammo\n";
	std::cout << "NUM4 = infinite sword\n";
	std::cout << "NUM5 = infinite hammer/chainsaw\n";
	std::cout << "NUM6 = infinite grenades\n";
	std::cout << "NUM7 = infinite flamethrower\n";
	std::cout << "NUM8 = infinite dash\n";
	std::cout << "NUM9 = infinite blood punch\n";
	std::cout << "Press INSERT to exit the trainer\n\n";
	std::cout << "Hack Status:" << std::endl;
}

void ClearScreen()
{
	HANDLE hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD count, cellCount;
	COORD homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X * csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR)' ',
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Move the cursor home */
	SetConsoleCursorPosition(hStdOut, homeCoords);
}

void ConsoleColors()
{
	//set console colors
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 12);
}