#include "SteamAPI_Manager.h"

SteamAPI_Manager::SteamAPI_Manager()
{
	// Nothing
}

bool SteamAPI_Manager::Init()
{
	if (SteamAPI_RestartAppIfNecessary(k_uAppIdInvalid))
	{
		printf_s("Erreur lors du rechargement de l'api steam.");
		return false;
	}

	if (!SteamAPI_Init())
	{
		printf_s("Erreur lors de l'initialisation de l'api steam.");
		return false;
	}

	if (!SteamUser()->BLoggedOn())
	{
		printf_s("Fatal Error Steam user must be logged in to play this game (SteamUser()->BLoggedOn() returned false).\n");
		return false;
	}

	if (!SteamInput()->Init(false))
	{
		printf_s("Fatal Error SteamInput()->Init failed.\n");
		return false;
	}

	char rgchCWD[1024];
	if (!_getcwd(rgchCWD, sizeof(rgchCWD)))
	{
		strcpy_s(rgchCWD, ".");
	}

	char rgchFullPath[1024];
	_snprintf_s(rgchFullPath, sizeof(rgchFullPath), "%s\\%s", rgchCWD, "steam_input_manifest.vdf");

	SteamInput()->SetInputActionManifestFilePath(rgchFullPath);

	//Test du Steamworks Interfaces pour afficher le nom de l'utilisateur.
	const char* name = SteamFriends()->GetPersonaName();
	printf_s(name);

	return true;
}

void SteamAPI_Manager::Quit()
{
	SteamAPI_Shutdown();
}

void SteamAPI_Manager::Update()
{
	SteamAPI_RunCallbacks();
}

void SteamAPI_Manager::ActivateOverlay()
{
	printf_s("Activate overlay\n");
	SteamFriends()->ActivateGameOverlay("friends");
}