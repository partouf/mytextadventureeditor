#pragma once

#include "../stdafx.h"
#include "item.h"
#include <QStringList>

namespace MyTextAdventure
{

class item_error: public std::runtime_error
{
public:
    itemid_t id;

    item_error(itemid_t id) : std::runtime_error("Item not found") {
        this->id = id;
    }
};

class CItems
{
protected:
    vector<CItem *> Items;
public:
    CItems();
    virtual ~CItems();

    virtual void Load(const string folder) = 0;

    CItem *GetByItemId(itemid_t id);

    CItem *GetByIndex(int index);
    size_t Count() const;
};

}
