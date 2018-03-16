#pragma once

#include "../stdafx.h"
#include "../items/item.h"

namespace MyTextAdventure
{

struct path_t
{
    double Room;
    string Title;
};

class CRoomData
{
public:
    double Id;
    string Title;
    string Description;
    vector<itemid_t> Items;
    vector<path_t> Paths;
    string Entry;
    string UseItem;
};

class CRoom: public CRoomData
{
protected:
public:
    void RemoveItem(itemid_t id);
};

}


/*
 * Id: 5,
        Title: "The smell of happiness",
        Description: "",
        Items: [],
        Paths: [
            {Room: 5.1, Title: "Order a beer"}
        ],
        Entry: function(Player) {
            if (Player.HasItem(4)) {
                this.Description = "An angry bartender looks at you and immediately shouts: 'HEY YOU, GIVE ME THAT REMOTE!'";
                this.Paths = [{Room: 2, Title: "Run out as fast as you can"}];
            } else {
                this.Description = "A bartender looks grumpy and distracted, but seems ready to take your order nonetheless.";
                this.Paths = [{Room: 5.1, Title: "Order a beer"}];
            }
        },
        UseItem: function(Player, ItemId, UI) {
            if (ItemId == 4) {
                UI.Info("Well done.");
                Player.EarnPoints(1);

                return 5
            } else {
                UI.Info("So yeah, you shouldn't have done that.");

                return 2;
            }
        }
        */
