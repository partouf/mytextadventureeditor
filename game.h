#pragma once

#include "mytextadventure.h"

namespace MyTextAdventure
{
    class CGame
    {
    public:
        std::unique_ptr<CRooms> Rooms;

        static CGame *Instance();
    };
}
