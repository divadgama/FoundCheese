#ifndef __Room__
#define __Room__


#include <string.h>
#include <iostream>
#include <vector>
#include "control.h"
#include "item.h"

class exit;

using namespace std;

class Room
{

public:
	
	char * name;
	char * description;
	bool light;
	Item * object;

public:
	Room(char*, char*,bool,Item*);
	~Room();
	void look();
	void lookItem();
	bool Stade();
	void changeStade();
	Item* getObjet();
};

#endif //__Room__