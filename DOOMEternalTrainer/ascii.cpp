#include "stdafx.h"
#include "ascii.h"

void AsciiArt()
{
	std::cout << "    ________   ________   ________      _____           " << std::endl;
	std::cout << "    \\______ \\  \\_____  \\  \\_____  \\    /     \\          " << std::endl;
	std::cout << "     |    |  \\  /   |   \\  /   |   \\  /  \\ /  \\         " << std::endl;
	std::cout << "     |    `   \\/    |    \\/    |    \\/    Y    \\        " << std::endl;
	std::cout << "    /_______  /\\_______  /\\_______  /\\____|__  /        " << std::endl;
	std::cout << "            \\/         \\/         \\/         \\/         " << std::endl;
	std::cout << "___________  __                                   .__   " << std::endl;
	std::cout << "\\_   _____/_/  |_   ____  _______   ____  _____   |  |  " << std::endl;
	std::cout << " |    __)_ \\   __\\_/ __ \\ \\_  __ \\ /    \\ \\__  \\  |  |  " << std::endl;
	std::cout << " |        \\ |  |  \\  ___/  |  | \\/|   |  \\ / __ \\_|  |__" << std::endl;
	std::cout << "/_______  / |__|   \\___  > |__|   |___|  /(____  /|____/" << std::endl;
	std::cout << "        \\/             \\/              \\/      \\/       " << std::endl;
	std::cout << "___________                .__                          " << std::endl;
	std::cout << "\\__    ___/_______ _____   |__|  ____    ____  _______  " << std::endl;
	std::cout << "  |    |   \\_  __ \\\\__  \\  |  | /    \\ _/ __ \\ \\_  __ \\ " << std::endl;
	std::cout << "  |    |    |  | \\/ / __ \\_|  ||   |  \\\\  ___/  |  | \\/ " << std::endl;
	std::cout << "  |____|    |__|   (____  /|__||___|  / \\___  > |__|    " << std::endl;
	std::cout << "                        \\/          \\/      \\/          " << std::endl;
	std::cout << "" << std::endl;
	std::cout << "                  Ancient Gods Part 2" << std::endl;
	std::cout << "                                      By: Paradox" << std::endl;
	std::cout << "" << std::endl;
	std::cout << "press enter to continue..." << std::endl;
}

void AsciiMenu()
{
	std::cout << "TOGGLE FUNCTIONS:" << std::endl;
	std::cout << "NUM0 = infinite health" << std::endl;
	std::cout << "NUM1 = infinite ammo" << std::endl;
	std::cout << "NUM2 = infinite sword" << std::endl;
	std::cout << "NUM3 = infinite hammer/chainsaw" << std::endl;
	std::cout << "NUM4 = infinite grenades" << std::endl;
	std::cout << "NUM5 = infinite flamethrower" << std::endl;
	std::cout << "NUM6 = infinite dash" << std::endl;
	std::cout << "NUM7 = infinite blood punch" << std::endl;
	std::cout << "Press INSERT to exit the trainer" << std::endl;
	std::cout << "" << std::endl;
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