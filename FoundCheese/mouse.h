#ifndef __Mouse__
#define __Mouse__

#include <vector>
#include <iostream>
#include "world.h"
#include "item.h"

using namespace std;

class Mouse
{
private:
	std::vector<char*> instruction;
	vector<Item*>inventory;
	bool endGame = false;
public:
	Mouse();
	~Mouse();
	void controlInstruction(char*,World*);//parse intruction
	void getinventory();
	void putinventory(World*);
	void help();
	bool getEndGame();
	void finishedGame(World*);
	void useLantern(World*);
	void useKey(World*);
};

#endif //__Mouse__