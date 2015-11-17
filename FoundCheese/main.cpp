#include <iostream>
#include <string.h>
#include <vector>
#include "world.h"
#include "mouse.h"

using namespace std;

int main() {

	char readUser[20];
	char flag[1];
	World theHouse;
	Mouse player;

	cout << "   __^__                                      __^__\n";
	cout << "   (___)--------------------------------------(___)\n";
	cout << "   | _ | The history of a mouse very rogue    | _ |\n";
	cout << "   | _ | that all he wants is to eat, to do   | _ |\n";
	cout << "   | _ |  this he must get to the kitchen     | _ |\n";
	cout << "   | _ | and eat the piece of cheese hidden . | _ |\n";
	cout << "   | _ |   Be careful with the dangers!!      | _ |\n";
	cout << "   |___|--------------------------------------|___|\n";
	cout << "  (_____)                                    (_____)\n";
	cout << "\n\n\n";
	cout << "You're a mouse in search of food, you remember to give the correct instructions.";

	//read commands, for read "quit"
	do
	{
		if (player.getEndGame())//finsh game
			break;
		cout << "\n\nWhat you want to do?\n";
		cin.getline(readUser, 20);
		//parse instruction
		player.controlInstruction(readUser,&theHouse);
	
	} while ((strcmp(readUser, "quit") != 0));


	if (player.getEndGame()){
		cout << "\n*** MY CONGRATULATIONS!!! ***, you have complete the game.\n";
	}

	cout << "\nBye, Bye!!!, come back early :)\n";
	cin.getline(flag,1);
	return 0;
}