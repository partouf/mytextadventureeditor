#include "game.h"

std::unique_ptr<MyTextAdventure::CGame> gameInstance;

MyTextAdventure::CGame *MyTextAdventure::CGame::Instance() {
    if (gameInstance == nullptr)
    {
        gameInstance = std::make_unique<MyTextAdventure::CGame>();
    }

    return gameInstance.get();
}
