#pragma once

#include "../stdafx.h"

namespace MyTextAdventure
{

typedef int itemid_t;

class CItemData
{
public:
    itemid_t Id;
    string Title;
};

class CItem: public CItemData
{
protected:
public:

};

}
