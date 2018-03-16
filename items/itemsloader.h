#pragma once

#include "items.h"
#include <QJsonArray>

namespace MyTextAdventure
{

class CItemsFromJson: public CItems
{
protected:
    void LoadFromJSON(const QJsonArray &json);

    QString GetFilepathFromFolder(const string folder) const;

    void SaveToJson(const CItem *Item, QJsonObject &JsonItem) const;
public:
    void Load(const string folder);

    void Save(const string folder) const;
};

}
