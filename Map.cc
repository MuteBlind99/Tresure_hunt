#include "Map.h"
#include  <iostream>

//Affichage du tableau vide
void Map::ShowMap(int row_size, int col_size)
{
	for (row_size = 0;row_size < 4; row_size++)
	{
		std::cout << std::endl;
		for (col_size = 0; col_size < 4; col_size++)
		{

			std::cout << " # ";

		}
	}
}

//Verification si le nombre choissi est valide
bool Map::GetNumberValid(int player_dig)
{
	switch (player_dig)
	{
	case 1: case 2: case 3: case 4:
		return true;
		break;
	default:
		return false;
		break;
	}
}


