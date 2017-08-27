#pragma once

#include "../stdafx.h"
#include "room.h"
#include <QStringList>

namespace MyTextAdventure
{

class CRooms
{
protected:
    vector<CRoom *> Rooms;
public:
    CRooms();
    virtual ~CRooms();

    QStringList GetRoomTitles();

    virtual void Load(const string folder) = 0;
};

}
