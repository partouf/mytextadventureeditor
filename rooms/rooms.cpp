#include "rooms.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

#ifndef min
   #define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif

#ifndef max
   #define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif

MyTextAdventure::CRooms::CRooms()
{

}

MyTextAdventure::CRooms::~CRooms()
{

}

size_t MyTextAdventure::CRooms::Count() const
{
    return Rooms.size();
}

QString MyTextAdventure::CRooms::FormatRoomTitle(const MyTextAdventure::CRoom *room) const
{
    QString title = "";
    title.append(QString::number(room->Id, '.', 1));
    title.append(" - ");
    title.append(room->Title.c_str());

    return title;
}

QString MyTextAdventure::CRooms::FormatPathTitle(const path_t path) const
{
    QString title = "";
    title.append(QString::number(path.Room, '.', 1));
    title.append(" - ");
    title.append(path.Title.c_str());

    return title;
}

QStringList MyTextAdventure::CRooms::GetRoomTitles()
{
    QStringList lst;

    for (auto room: Rooms)
    {
        lst.append(FormatRoomTitle(room));
    }

    return lst;
}

MyTextAdventure::CRoom *MyTextAdventure::CRooms::GetByIndex(int index)
{
    return Rooms[index];
}

double MyTextAdventure::CRooms::GetMaxRoomId()
{
   double maxid = 0;

   for (auto room : Rooms)
   {
      maxid = max(maxid, room->Id);
   }

   return maxid;
}

MyTextAdventure::CRoom * MyTextAdventure::CRooms::AddRoom(double id)
{
   auto room = new CRoom();
   room->Id = id;

   this->Rooms.push_back(room);

   return room;
}
