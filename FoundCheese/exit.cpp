#include "exit.h"




Exit::Exit(char * na, char * des, Room* orig, Room *dest, bool clo = false) : name(na), description(des), origenRoom(orig), destinyRoom(dest), close(clo)
{
	
}


Exit::~Exit()
{
}


char* Exit::getname(){//return name exit

	return name;
}

Room* Exit::getOriginRoom(){//return origen room

	return origenRoom;
}

Room* Exit::getDestinyRoom(){//return destiny room

	return destinyRoom;
}


void Exit::look(){//wirte description exit

	cout << description;

}

char* Exit::Stade(){//return stade the exit
	if (close){

		return "true";
	}
	else
	{
		return "false";
	}
}
void Exit::changeStade(){// change stade

	if (close){
		close = false;
	}
}