#pragma once
#include "..//HeaderFiles/steam_api.h"
#include <direct.h>

class SteamAPI_Manager
{
private:

public:
	SteamAPI_Manager();

	bool Init();
	void Quit();
	void Update();
	void ActivateOverlay();
};
