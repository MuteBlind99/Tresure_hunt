#include "Map.h"
#include  <iostream>

void Map::ShowMap(int row_size, int col_size)
{
	for (row_size = 0;row_size < 4; row_size++)
	{
		std::cout << std::endl;
		for (col_size = 0; col_size < 4; col_size++)
		{
			//int idx = num_row * col_size + numb_col;
			std::cout << " # ";

		}
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


