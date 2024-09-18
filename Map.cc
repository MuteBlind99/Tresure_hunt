#include "Map.h"
#include  <iostream>

Map::Map(int digged, int tresure, int notresure) :
	digged_(digged),
	tresure_(tresure),
	notresure_(notresure)
{

}
void Map::PlayerDig(int playerdig)
{

}
void Map::GetPositionTresur(int position)
{

}
bool Map::GetTresure(int bulleyes)
{
	if (bulleyes == tresure_)
	{
		std::cout << "You get the tresure";
		return true;
	}
	else if (bulleyes ==notresure_ )
	{
		std::cout << "You get nothing, the hole is empty"<<std::endl;
		return false;
	}
}


