#pragma once

#include "mytextadventure.h"

namespace MyTextAdventure
{
    class CGame
    {
    public:
        std::unique_ptr<CRooms> Rooms;
        std::unique_ptr<CItems> Items;

        static CGame *Instance();
    };
}
