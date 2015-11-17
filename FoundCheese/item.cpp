#include "item.h"


Item::Item(char* na, char* des) :name(na), description(des)
{
}


Item::~Item()
{
}

char* Item::getName(){

	return name;

}

char* Item::getDescription(){

	return description;
}