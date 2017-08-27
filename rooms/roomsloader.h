#pragma once

#include "rooms.h"
#include <QJsonArray>

namespace MyTextAdventure
{

class CRoomsFromJson: public CRooms
{
protected:
    void LoadFromJSON(const QJsonArray &json);
public:
    void Load(const string folder);
};

}
