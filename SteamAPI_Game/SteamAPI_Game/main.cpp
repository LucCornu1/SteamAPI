#include <iostream>
#include "SteamAPI_Manager.h"
#include "GameManager.h"
#include <windows.h>


int main()
{
	SteamAPI_Manager steamAPIManager;
	GameManager gameManager;

	if (steamAPIManager.Init())
	{
		gameManager.SetSteamManager(&steamAPIManager);
		gameManager.Update();
		// std::cout << "Success" << std::endl;
	}
	else {
		// std::cout << "Fail" << std::endl;
	}

	Sleep(16000);

	return 1;
}