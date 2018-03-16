#include "room.h"
#include "../stdafx.h"

void MyTextAdventure::CRoom::RemoveItem(itemid_t id)
{
    auto iter = std::find(Items.begin(), Items.end(), id);
    if (iter != Items.end())
    {
        Items.erase(iter);
    }
}

