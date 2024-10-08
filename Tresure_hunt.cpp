
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

int party_player = 6;

Map starting_map;
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
				std::cout << " # ";//Pas creus�
				break;
			case 1:
				std::cout << " x ";//Creus� vide
				break;
			case 2:
				std::cout << " $ ";//Tr�sor
				break;
			}
		}
	}
}



int main()
{
	//Creation du tableau

	std::array<int, 16>solution_mono_dim;
	solution_mono_dim.fill(0);

	//Salutation et presentation du jeu avec ses regles

	std::cout << "Welcome to the treasure hunt, booty hunter" << std::endl;
	std::cout << "You can choose a number between 1 and 4 for the row and the column to start digging" << std::endl;
	std::cout << "[#]Not dug  [x]Empty  [$]Treasure found\n" << "Break a leg, hunter" << std::endl;
	starting_map.ShowMap(row_size, col_size);


	/*int solution[4][5] = {
		{ 0,0,0,0,0 },
		{ 0,0,0,0,0 },
		{ 0,0,0,0,0 },
		{ 0,0,0,0,0 }

	};*/
	//Boucle de reset du jeu

	while (replayLoop)
	{
		//Boucle du jeu Chasse au Tresor

		while (gameLoop)
		{
			std::cout << '\n' << "-----------------------------------------" << std::endl;

			//Affichage du nombre d'essais restant du joueur

			std::cout << "You can retry : " << party_player << " times" << std::endl;
			if (party_player > 0)
			{
				gameLoop = true;
				tresuremap = (treasur_position_x - 1) * col_size + (treasur_position_y - 1);
				//Aquisition du nombre choisi par le joueur pour l'axe x 
				std::cin >> player_dig_x;
				//Aquisition du nombre choisi par le joueur pour l'axe y
				std::cin >> player_dig_y;

				//Verification que les nombres choissis ne depassent pas la taille du tableau
				if ((position_x.GetNumberValid(player_dig_x) && position_y.GetNumberValid(player_dig_y)) == true)
				{

					player_dig = (player_dig_x - 1) * col_size + (player_dig_y - 1);
					//Y a t-il un tresor a l'endroit choissi par le joueur ?
					if (tresuremap == player_dig)
					{
						solution_mono_dim[tresuremap] = 2;
						treasure(solution_mono_dim);
						std::cout << '\n' << "You get the treasure." << '\n' << "You win." << std::endl;
						gameLoop = false;

					}
					else
					{
						solution_mono_dim[player_dig] = 1;
						treasure(solution_mono_dim);
						std::cout << '\n' << " You get nothing, the hole is empty." << '\n' << "Try again" << std::endl;
						party_player -= 1;

					}
				}
				else
				{
					std::cout << "Invalid Command" << '\n' << "Try again" << std::endl;

				}

			}

			else
			{

				gameLoop = false;

			}


		}
		//Fin de la partie, demande au joueur s'il veut recommencer a jouer

		std::cout << '\n' << "-----------------------------------------" << std::endl;
		std::cout << "Wanna play again ?\n" << "[Y/y]Yes  [N/n]No" << std::endl;

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
			std::cout << "Alright\nSee ya, hunter..." << std::endl;
			replayLoop = false;
			break;
		case 'n':
			std::cout << "Alright\nSee ya, hunter..." << std::endl;
			replayLoop = false;
			break;
		default:
			std::cout << "Invalid Command" << std::endl;
			break;
		}
	}

}


