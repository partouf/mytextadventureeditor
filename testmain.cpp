#include "stdafx.h"
#include "mytextadventure.h"

#include "Rooms/rooms.h"
#include "Rooms/roomsloader.h"
#include "game.h"

using namespace MyTextAdventure;

void DoSave(CRooms *rooms)
{
   reinterpret_cast<CRoomsFromJson *>(rooms)->Save("../mytextadventure");
}

int main() {
   std::unique_ptr<CRoomsFromJson> loader = std::make_unique<CRoomsFromJson>();
   loader->Load("../mytextadventure");

   CGame::Instance()->Rooms = std::move(loader);

   auto rooms = CGame::Instance()->Rooms.get();

   //double nextroomid = floor(rooms->GetMaxRoomId()) + 1.0;

   //CGame::Instance()->Rooms->AddRoom(nextroomid);

   rooms->GetRoomTitles();

   DoSave(rooms);

   return 0;
}
