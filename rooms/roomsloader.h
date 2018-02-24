#pragma once

#include "rooms.h"
#include <QJsonArray>

namespace MyTextAdventure
{

class CRoomsFromJson: public CRooms
{
protected:
    void LoadFromJSON(const QJsonArray &json);

    QString GetFilepathFromFolder(const string folder) const;

    void SaveToJson(const CRoom *Room, QJsonObject &JsonRoom) const;
public:
    void Load(const string folder);

    void Save(const string folder) const;
};



}
