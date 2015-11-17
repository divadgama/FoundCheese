#include "mouse.h"


Mouse::Mouse()
{
	//Instuction look
	instruction.push_back("look");
	instruction.push_back("look inventory");

	//Instruction go
	instruction.push_back("go south hall");
	instruction.push_back("go north hall");
	instruction.push_back("go east hall");
	instruction.push_back("go north garage");
	instruction.push_back("go west bedroom");
	instruction.push_back("go south kitchen");
	
	//instruction pick
	instruction.push_back("pick object");
	instruction.push_back("use lantern");
	instruction.push_back("use key");
	instruction.push_back("eat cheese");
	
	//other order
	instruction.push_back("quit");
	instruction.push_back("help");
	
	
}


Mouse::~Mouse()
{
}

void Mouse::controlInstruction(char* instruc,World* theHouse){

	int option = -1;
	int iterator = 0;
	bool Orderfind = true;

	while (Orderfind && iterator < instruction.size())
	{

		if (strcmp(instruc, instruction[iterator]) == 0)//check that there is the accition
		{
			option = iterator;
			Orderfind = false;
		}
		++iterator;
	}

	switch (option)// check position vector
	{
	case 0://look
		theHouse->look();
		break;
	case 1://look inventory
		getinventory();
		break;
	case 2://go south hall
		theHouse->go("south hall");
		break;
	case 3://go north hall
		theHouse->go("north hall");
		break;
	case 4://go east hall
		theHouse->go("east hall");
		break;
	case 5://go north garage
		theHouse->go("north garage");
		break;
	case 6://go west bedroom
		theHouse->go("west bedroom");
		break;
	case 7://go south kitchen
		theHouse->go("south kitchen");
		break;
	case 8:// pick object
		putinventory(theHouse);
		break;
	case 9:// use lantern
		useLantern(theHouse);
		break;
	case 10:// use key
		useKey(theHouse);
		break;
	case 11:// eat cheese
		finishedGame(theHouse);
		break;
	case 12://quit
		break;
	case 13:// help
		help();
		break;
	default:
		cout << "The wrong order, if you need help you write 'help'";
		break;
	}
}

void Mouse::getinventory(){

	cout << "\n** INVENTORY **\n";
	for (int i = 0; i < inventory.size(); ++i)//look the inventatry vector
	{
		cout << "<>"<<inventory[i]->getDescription()<<"\n";
	}
	if (inventory.size() == 0)
	{
		cout << "Empty inventory";
	}

}

void Mouse::putinventory(World* theHouse){

	if (theHouse->putinventory() != NULL)//get item in the room
	{
		cout << "\nYou take "<<theHouse->putinventory()->getName();
		inventory.push_back(theHouse->putinventory());//save item in the vector (inventory)
		theHouse->deleteItem();// delete item in the room
	}
	else//no ligth in the room
	{
		cout << "\nYou can't see the object\n";
	}
}

void Mouse::help(){
	cout << "\n** HELP **\n";
	for (int i = 0; i <instruction.size()-1; ++i)//look the instructuon vector
	{
		cout << "<> ";
		cout << instruction[i]<<"\n";
	}
	
}

bool Mouse::getEndGame(){//return bool the game
	return endGame;
}

void Mouse::finishedGame(World* theHouse){//eat cheese
	
	Item* object = theHouse->putinventory();//get the object (cheese)

	if (object != NULL)
	{
		if (strcmp(object->getName(), "cheese")==0)// the objet is cheese
		{
			theHouse->deleteItem();// delete item the room
			endGame = true;
		}
		else
		{
			cout << "You can't see food";
		}
	}
	else
	{
		cout << "You can't see food";
	}
}


void Mouse::useLantern(World* thehouse){
	
	bool found = false;

	for (int i = 0; i < inventory.size(); ++i) //look the inventory vector
	{
		if (strcmp(inventory[i]->getName(),"lantern")==0)//object == lantern
		{
			found = true;
			if (!thehouse->returnRoomNow()->Stade()) //need the lantern?
			{
				thehouse->returnRoomNow()->changeStade();// change litgh = true in room
				cout << "\nYou can see!!\n";
			}
			else
			{
				cout << "You don't need the lantern";
			}
			break;
		}
	}
	if (!found)
	{
		cout << "You haven't the lantern";
	}

}
void Mouse::useKey(World* thehouse){
	
	bool found=false;
	for (int i = 0; i < inventory.size(); ++i)// look the inventory vector
	{
		if (strcmp(inventory[i]->getName(), "key") == 0)// the object is key
		{
			found = true;
			if (strcmp(thehouse->returnRoomNow()->name, "hall") == 0)// you is hall
			{
				thehouse->openDoor();
				cout << "\nThe door is open!!\n";
			}
			else
			{
				cout << "\nYou don't need the key\n";
			}
			break;
		}
	}
	if (!found)
	{
		cout << "You haven't the key";
	}
}