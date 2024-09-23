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
bool Map::GetTresure(int playerx, int playery)
{
	if (playerx == tresure_)
	{
		std::cout << "You get the tresure";
		return true;
	}
	else
	{
		std::cout << "You get nothing, the hole is empty" << std::endl;
		return false;
	}
}
bool Map::GetNumberValid(int player_dig)
{
	switch (player_dig)
	{
	case 1:
		return true;
		break;
	case 2:
		return true;
		break;
	case 3:
		return true;
		break;
	case 4:
		return true;
		break;
	default:
		return false;
		break;
	}
}


