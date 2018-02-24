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
   std::unique_ptr<CRoomsFromJson> rooms = std::make_unique<CRoomsFromJson>();
   rooms->Load("../mytextadventure");

   CGame::Instance()->Rooms = std::move(rooms);

   //double nextroomid = floor(CGame::Instance()->Rooms->GetMaxRoomId()) + 1.0;

   //CGame::Instance()->Rooms->AddRoom(nextroomid);

   CGame::Instance()->Rooms->GetRoomTitles();

   DoSave(CGame::Instance()->Rooms.get());

   return 0;
}
