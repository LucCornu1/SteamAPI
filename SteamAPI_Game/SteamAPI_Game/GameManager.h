#pragma once
#include "SteamAPI_Manager.h"

class GameManager
{
private:
    SteamAPI_Manager* pSteamManager;

    // Callbacks
    STEAM_CALLBACK(GameManager, OnFriendStatusChanged, PersonaStateChange_t);

    STEAM_CALLBACK(GameManager, OnLobbyEntered, LobbyEnter_t);

    // Call results
    void OnGetNumberOfCurrentPlayer(NumberOfCurrentPlayers_t* pCallback, bool bIOFailure);
    CCallResult<GameManager, NumberOfCurrentPlayers_t> m_NumberOfCurrentPlayersCallResult;

    void OnGetLobbyMatchList(LobbyMatchList_t* pCallback, bool bIOFailure);
    CCallResult<GameManager, LobbyMatchList_t> m_LobbyMatchListCallResult;

    void OnLobbyEntered(LobbyEnter_t* pCallback, bool bIOFailure);
    CCallResult<GameManager, LobbyEnter_t> m_LobbyEnterCallResult;

    void OnLobbyCreated(LobbyCreated_t* pCallback, bool bIOFailure);
    CCallResult<GameManager, LobbyCreated_t> m_LobbyCreatedCallResult;

    // void OnFriendStatusChanged(PersonaStateChange_t* pCallback); // Inutile

public:
    bool bRunning;
    bool bSearching;

    //Constructeurs
    GameManager();

    //Mutateurs
    void SetSteamManager(SteamAPI_Manager* pSteamManager);

    //Fonctions
    void Update();
};