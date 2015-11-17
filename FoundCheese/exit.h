#ifndef __Exit__
#define __Exit__

#include"room.h"

class Exit
{
private:
	char * name;
	char * description;
	Room *origenRoom;
	Room *destinyRoom;
	bool close;

public:

	Exit(char*, char*, Room*, Room*,bool);
	~Exit();
	char* getname();
	Room* getOriginRoom();
	Room* getDestinyRoom();
	void look();
	char* Stade();
	void changeStade();

};

#endif //__Exit__