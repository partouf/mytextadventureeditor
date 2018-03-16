#include "items.h"

MyTextAdventure::CItems::CItems() {

}

MyTextAdventure::CItems::~CItems() {

}

MyTextAdventure::CItem *MyTextAdventure::CItems::GetByItemId(itemid_t id) {
    for (auto item: Items)
    {
        if (item->Id == id)
        {
            return item;
        }
    }

    throw new item_error(id);
}

MyTextAdventure::CItem *MyTextAdventure::CItems::GetByIndex(int index) {
    return Items[index];
}

size_t MyTextAdventure::CItems::Count() const
{
    return Items.size();
}
