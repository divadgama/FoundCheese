#include "world.h"


World::World()
{
	//ITEM

	Item *lantern = new Item("lantern","This is a lantern, you can use lantern for illuminate");
	Item *key = new Item("key", "This is a Key, you can use for open door");
	Item *cheese = new Item("cheese", "CHEESE!! This is your food :)");



	//The place of house
	Room *hall = new Room("hall", "This is the Hall, the master room of the house ",true,NULL);
	Room *garage = new Room("garage", "This is the garage,here the human saved all tools",true,lantern);
	Room *bedroom = new Room("bedroom", "This is the bedroom, here the human saved things with value",false,key);
	Room *kitchen = new Room("kitchen","This is the kitchen,here you can found good food",false,cheese);

	rooms.push_back(hall);
	rooms.push_back(garage);
	rooms.push_back(bedroom);
	rooms.push_back(kitchen);
	
	// the game start hall
	parent = hall;

	// the exits
	Exit *exithall1 = new Exit("south hall","South hall, This leads to the garage exit",hall,garage,false);
	Exit *exithall2 = new Exit("east hall", "East hall, This leads to the bedroom exit", hall, bedroom, false);
	Exit *exithall3 = new Exit("north hall", "North hall, This leads to the kitchen exit", hall, kitchen,true);
	Exit *exitgarage = new Exit("north garage", "North garage, This leads to the hall exit", garage, hall, false);
	Exit *exitbedroom = new Exit("west bedroom", "West bedroom, This leads to the hall exit", bedroom, hall, false);
	Exit *exitkitchen = new Exit("south kitchen", "South kitchen, This leads to the hall exit", kitchen, hall, false);
	
	exits.push_back(exithall1);
	exits.push_back(exithall2);
	exits.push_back(exithall3);
	exits.push_back(exitgarage);
	exits.push_back(exitbedroom);
	exits.push_back(exitkitchen);
}


World::~World()
{
	rooms.clear();
	exits.clear();
}


void World::go(char * nameExit){

	Room* destiny=NULL;

	for (int i = 0; i < exits.size(); ++i)
	{
		if (strcmp(nameExit, exits[i]->getname()) == 0)//compare name exit
		{
			if (strcmp((exits[i]->getOriginRoom())->name,parent->name) == 0)//compare mane room parent and room origin exit
			{
				if (strcmp(exits[i]->Stade(), "false") == 0){//look stade door
					destiny = exits[i]->getDestinyRoom();
					break;
				}
				else
				{
					cout << "\nThe door is close, you need a Key\n";
				}
				
			}
		break;
		}		
	}
	if (destiny!=NULL)// if destiny is correct change parent
	{
		parent = destiny;
		cout << "\n** PLACE **\n";
		parent->look();
	}
	else
	{
		cout << "\nYou don't see this exit\n";
	}
	
}

void World::look(){// write description place, exit and item the room
	cout << "\n** PLACE **\n";
	parent->look();
	cout << "\n\n** EXIT **\n";
	for (int i = 0; i < exits.size(); ++i)
	{
		if (strcmp(exits[i]->getOriginRoom()->name, parent->name) == 0)
		{
			cout << "<> ";
			exits[i]->look();
			cout << "\n";
		}
	}

	if (parent->Stade())
	{
		cout << "\n** ITEM **\n";
		parent->lookItem();
	}
	else
	{
		cout << "\nYou can not see, the room is dark, you need a lantern\n";
	}
	
}

Room* World::returnRoomNow(){//return parent

	return parent;
}

void World::openDoor(){//change stade door

	for (int i = 0; i < exits.size(); ++i)
	{
		if (strcmp(exits[i]->getOriginRoom()->name, parent->name) == 0)//find is room correct
		{
			if (strcmp(exits[i]->Stade(), "true") == false){// change stade door
				exits[i]->changeStade();
			}
		}
	}
}

Item* World::putinventory(){//return the object in room
	
	if (parent->Stade()){
		return parent->getObjet();
	}
	else
	{
		return NULL;
	}
}

void World::deleteItem(){// delete object room

	parent->object = NULL;
}