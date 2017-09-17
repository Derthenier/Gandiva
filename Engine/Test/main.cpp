#include <windows.h>
#include "Game.hpp"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR cmdline, int cmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(cmdline);

	Game* game = new Game();
	if (!game->initialize(hInstance, L"World of Warcraft", cmdShow)) {
		game->run();
	}
}
