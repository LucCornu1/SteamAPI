#include "GameManager.h"

void GameManager::OnFriendStatusChanged(PersonaStateChange_t* pCallback)
{
    const char* friendName = SteamFriends()->GetFriendPersonaName(pCallback->m_ulSteamID);
    EPersonaState friendStatusEnum = SteamFriends()->GetFriendPersonaState(pCallback->m_ulSteamID);

    const char* friendStatus;
    switch (friendStatusEnum)
    {
        case k_EPersonaStateOffline:
            friendStatus = "offline";
            break;
        case k_EPersonaStateOnline:
            friendStatus = "online";
            break;
        case k_EPersonaStateBusy:
            friendStatus = "busy";
            break;
        case k_EPersonaStateAway:
            friendStatus = "away";
            break;
        case k_EPersonaStateSnooze:
            friendStatus = "set on snooze";
            break;
        case k_EPersonaStateLookingToTrade:
            friendStatus = "looking to trade";
            break;
        case k_EPersonaStateLookingToPlay:
            friendStatus = "looking to play";
            break;
        case k_EPersonaStateInvisible:
            friendStatus = "invisible";
            break;
        default:
            friendStatus = "unkown status";
            break;
    }

    std::cout << friendName << " status is now " << friendStatus << " !" << std::endl;

    // Getting player count
    SteamAPICall_t hSteamAPICall = SteamUserStats()->GetNumberOfCurrentPlayers();
    m_NumberOfCurrentPlayersCallResult.Set(hSteamAPICall, this, &GameManager::OnGetNumberOfCurrentPlayer);
}

void GameManager::OnGetNumberOfCurrentPlayer(NumberOfCurrentPlayers_t* pCallback, bool bIOFailure)
{
    if (bIOFailure || !pCallback->m_bSuccess)
    {
        std::cout << "Error : NumberOfCurrentPlayers_t failed" << std::endl;
        return;
    }

    std::cout << "Numbers of players currently playing : " << pCallback->m_cPlayers << std::endl << std::endl;
}

GameManager::GameManager()
{
    bRunning = true;
    pSteamManager = nullptr;
}

void GameManager::SetSteamManager(SteamAPI_Manager* pSteamManager)
{
    this->pSteamManager = pSteamManager;
}

void GameManager::Update()
{
    while (bRunning)
    {
        if (pSteamManager != nullptr)
        {
            pSteamManager->Update();
            pSteamManager->GetFriends();
        }
    }
}