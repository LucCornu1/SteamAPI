#include <iostream>
#include "SteamAPI_Manager.h"
#include <windows.h>


int main()
{
	SteamAPI_Manager SteamAPIManager;

	if (SteamAPIManager.Init())
	{
		printf_s(" Success");
	}
	else {
		printf_s(" Fail");
	}

	Sleep(50000);

	return 1;
}