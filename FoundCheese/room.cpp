#include "room.h"


Room::Room(char *na, char *des, bool lig=true, Item*it = NULL) : name(na), description(des), light(lig), object(it)

{

}

Room::~Room()
{
}

void Room::look(){//wirte description the room


	cout << description;

}

void Room::lookItem(){//wirte object description in the room

	if (object==NULL)
	{
		cout << "No objet in this room";
	}
	else{
		cout << object->getDescription();
	}	
}

bool Room::Stade(){//return stade light 

		return light;
}

void Room::changeStade(){// change light

	if (!light){
		light = true;
	}
}

Item* Room::getObjet(){// return item room
	return object;
}