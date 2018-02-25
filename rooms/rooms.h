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
    CRoom *GetByIndex(int index);
    size_t Count() const;

    QString FormatRoomTitle(const CRoom *room) const;
    QString FormatPathTitle(const path_t path) const;

    double GetMaxRoomId();

    CRoom *AddRoom(double id);

    virtual void Load(const string folder) = 0;
};

}
