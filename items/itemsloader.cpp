#include "itemsloader.h"
#include "../stdafx.h"
#include <QJsonArray>
#include <QJsonObject>
#include <QString>
#include <QFile>
#include <QJsonParseError>
#include <QJsonDocument>

void MyTextAdventure::CItemsFromJson::LoadFromJSON(const QJsonArray &json)
{
    for (auto itemValue: json)
    {
        QJsonObject itemObj = itemValue.toObject();

        CItem *item = new CItem();
        item->Id = itemObj["Id"].toInt();
        item->Title = itemObj["Title"].toString().toStdString();

        Items.push_back(item);
    }
}

void MyTextAdventure::CItemsFromJson::Load(const string folder)
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

QString MyTextAdventure::CItemsFromJson::GetFilepathFromFolder(const string folder) const
{
   QString filepath = folder.c_str();

   if (!filepath.endsWith('/')) filepath.append('/');
   filepath.append("myitems.json");

   return filepath;
}
