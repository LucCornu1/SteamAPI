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