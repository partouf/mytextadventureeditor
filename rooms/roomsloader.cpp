#include "roomsloader.h"
#include "../stdafx.h"
#include <QJsonArray>
#include <QJsonObject>
#include <QString>
#include <QFile>
#include <QJsonParseError>
#include <QJsonDocument>

void MyTextAdventure::CRoomsFromJson::LoadFromJSON(const QJsonArray &json)
{
    for (auto roomValue: json)
    {
        QJsonObject roomObj = roomValue.toObject();

        CRoom *room = new CRoom();
        room->Id = roomObj["Id"].toDouble();
        room->Title = roomObj["Title"].toString().toStdString();

        room->Description = "";
        if (roomObj["Description"].isArray())
        {
            for (auto line: roomObj["Description"].toArray())
            {
                if (room->Description != "")
                {
                    room->Description.append("\n");
                }

                room->Description.append(line.toString().toStdString());
            }
        }
        else
        {
            room->Description = roomObj["Description"].toString().toStdString();
        }

        if (roomObj["Items"].isArray())
        {
           for (auto item : roomObj["Items"].toArray())
           {
              room->Items.push_back(item.toInt());
           }
        }

        if (roomObj["Paths"].isArray())
        {
           for (auto path : roomObj["Paths"].toArray())
           {
              auto pathObj = path.toObject();

              room->Paths.push_back({
                 pathObj["Room"].toDouble(),
                 pathObj["Title"].toString().toStdString()
                 });
           }
        }

        Rooms.push_back(room);
    }
}

void MyTextAdventure::CRoomsFromJson::Load(const string folder)
{
    auto filepath = GetFilepathFromFolder(folder);
    QFile loadFile(filepath);

    if (!loadFile.open(QIODevice::ReadOnly)) {
        throw std::runtime_error("Couldn't open save file.");
    }

    QByteArray saveData = loadFile.readAll();

    QJsonParseError error;
    QJsonDocument loadDoc(QJsonDocument::fromJson(saveData, &error));
    if (error.error)
    {
        throw std::runtime_error(error.errorString().toStdString());
    }

    LoadFromJSON(loadDoc.array());
}

QString MyTextAdventure::CRoomsFromJson::GetFilepathFromFolder(const string folder) const
{
   QString filepath = folder.c_str();

   if (!filepath.endsWith('/')) filepath.append('/');
   filepath.append("myrooms.json");

   return filepath;
}

void MyTextAdventure::CRoomsFromJson::SaveToJson(const MyTextAdventure::CRoom *Room, QJsonObject &JsonRoom)
{
   JsonRoom["Id"] = Room->Id;
   JsonRoom["Title"] = Room->Title.c_str();
   if (Room->Description.find("\n") != -1)
   {
      vector<string> lines;
      split(Room->Description, '\n', std::back_inserter(lines));

      QJsonArray jsonLines;
      for (auto line : lines)
      {
         jsonLines.append(line.c_str());
      }

      JsonRoom["Description"] = jsonLines;
   }
   else
   {
      JsonRoom["Description"] = Room->Description.c_str();
   }

   QJsonArray jsonItems;
   for (auto item : Room->Items)
   {
      jsonItems.append(item);
   }
   JsonRoom["Items"] = jsonItems;

   QJsonArray jsonPaths;
   for (auto path : Room->Paths)
   {
      QJsonObject pathObj;
      pathObj["Room"] = path.Room;
      pathObj["Title"] = path.Title.c_str();

      jsonPaths.append(pathObj);
   }

   JsonRoom["Paths"] = jsonPaths;
}

void MyTextAdventure::CRoomsFromJson::Save(const string folder)
{
   auto filepath = GetFilepathFromFolder(folder);
   QFile saveFile(filepath);

   if (!saveFile.open(QIODevice::WriteOnly)) {
      throw std::runtime_error("Couldn't open save file.");
   }

   QJsonArray roomArray;

   for (auto room : Rooms)
   {
      QJsonObject roomObj;
      SaveToJson(room, roomObj);
      roomArray.append(roomObj);
   }

   QJsonDocument saveDoc(roomArray);
   saveFile.write(saveDoc.toJson());
}
