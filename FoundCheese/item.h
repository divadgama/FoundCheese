#ifndef __Item__
#define __Item__

#include <iostream>

using namespace std;

class Item //content description object in the house
{
private:
	char* name;
	char* description;

public:
	Item(char*, char*);
	~Item();
	char* getName();//return name
	char* getDescription();//return description
};

#endif //__Item__