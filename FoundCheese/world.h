#ifndef __ World__
#define __ World__

#include "room.h"
#include "exit.h"
#include "item.h"
#include <vector>

using namespace std;

class World
{
private:
	vector <Room*>rooms;
	vector <Exit*>exits;
	Room* parent;

public:
	World();
	~World();
	void look();// see description of room and object in the room
	void go(char *);// action player
	Room* returnRoomNow();// return parent now
	Item* putinventory();// save in inventory
	void openDoor();// use key
	void deleteItem();// delete item in room
};

#endif //__ World__