
#include <iostream>
#include <array>

#include "Map.h"
//#define array_size 20


bool gameLoop = true;
bool replayLoop = true;

int row_size = 4;
int col_size = 4;

int treasur_position_x = 3;
int treasur_position_y = 2;
int tresuremap;

int player_dig_x = 0;
int player_dig_y = 0;
int player_dig = 0;

int party_player = 3;

Map position_x;
Map position_y;

void treasure(std::array<int, 16> solution_mono_dim)
{

	for (int num_row = 0;num_row < 4; num_row++)
	{
		std::cout << std::endl;
		for (int numb_col = 0; numb_col < 4; numb_col++)
		{
			int idx = num_row * col_size + numb_col;


			switch (solution_mono_dim[idx])
			{
			case 0:
				std::cout << " # ";//Pas creusé
				break;
			case 1:
				std::cout << " x ";//Creusé vide
				break;
			case 2:
				std::cout << " $ ";//Trésor
				break;
			}
		}
	}
}



int main()
{
	std::array<int, 16>solution_mono_dim;
	solution_mono_dim.fill(0);

	std::cout << "Welcome to the treasure hunt, booty hunter" << std::endl;
	std::cout << "You can choose a number between 1 and 4 for the row and the column to start digging" << std::endl;



	/*int solution[4][5] = {
		{ 0,0,0,0,0 },
		{ 0,0,0,0,0 },
		{ 0,0,0,0,0 },
		{ 0,0,0,0,0 }

	};*/
	while (replayLoop)
	{

		while (gameLoop)
		{
			std::cout << "You can retry : " << party_player << " times" << std::endl;
			if (party_player > 0)
			{
				gameLoop = true;
			}
			else
			{

				gameLoop = false;

			}


			tresuremap = (treasur_position_x - 1) * col_size + (treasur_position_y - 1);

			std::cin >> player_dig_x;


			std::cin >> player_dig_y;

			if ((position_x.GetNumberValid(player_dig_x) && position_y.GetNumberValid(player_dig_y)) == true)
			{

				player_dig = (player_dig_x - 1) * col_size + (player_dig_y - 1);

				if (tresuremap == player_dig)
				{
					solution_mono_dim[tresuremap] = 2;
					treasure(solution_mono_dim);
					std::cout << '\n' << "You get the tresure." << '\n' << "You win." << std::endl;
					gameLoop = false;


				}
				else
				{
					solution_mono_dim[player_dig] = 1;
					treasure(solution_mono_dim);
					std::cout << '\n' << "You get nothing, the hole is empty." << '\n' << "You lose" << std::endl;
					party_player -= 1;

				}
			}
			else
			{
				std::cout << "Invalid Command"<<'\n'<<"Try again"<<std::endl;

			}

		}
		std::cout << "Wanna play again ?" << std::endl;
		char replay;
		std::cin >> replay;
		switch (replay)
		{
		case 'Y':
			gameLoop = true;
			party_player = 3;
			break;
		case 'y':
			gameLoop = true;
			party_player = 3;
			break;
		case 'N':
			std::cout << "Bye Bye..." << std::endl;
			replayLoop = false;
			break;
		case 'n':
			std::cout << "Bye Bye..." << std::endl;
			replayLoop = false;
			break;
		default:
			std::cout << "Invalid Command" << std::endl;
			break;
		}
	}

}


