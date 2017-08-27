#include "roomsloader.h"
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

        Rooms.push_back(room);
    }
}

void MyTextAdventure::CRoomsFromJson::Load(const string folder)
{
    QString filepath = folder.c_str();
    if (!filepath.endsWith('/')) filepath.append('/');
    filepath.append("myrooms.json");

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
