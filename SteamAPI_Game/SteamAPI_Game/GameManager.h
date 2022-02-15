#pragma once
#include "SteamAPI_Manager.h"

class GameManager
{
private:
    SteamAPI_Manager* pSteamManager;

    STEAM_CALLBACK(GameManager, OnFriendStatusChanged, PersonaStateChange_t);

    // void OnFriendStatusChanged(PersonaStateChange_t* pCallback); // Inutile

public:
    bool bRunning;

    //Constructeurs
    GameManager();

    //Mutateurs
    void SetSteamManager(SteamAPI_Manager* pSteamManager);

    //Fonctions
    void Update();
};