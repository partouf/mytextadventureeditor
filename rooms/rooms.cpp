#include "rooms.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

MyTextAdventure::CRooms::CRooms()
{

}

MyTextAdventure::CRooms::~CRooms()
{

}

QStringList MyTextAdventure::CRooms::GetRoomTitles()
{
    QStringList lst;

    for (auto room: Rooms)
    {
        QString title = "";
        title.append(QString::number(room->Id, '.', 1));
        title.append(" - ");
        title.append(room->Title.c_str());
        lst.append(title);
    }

    return lst;
}

MyTextAdventure::CRoom *MyTextAdventure::CRooms::GetByIndex(int index)
{
    return Rooms[index];
}
