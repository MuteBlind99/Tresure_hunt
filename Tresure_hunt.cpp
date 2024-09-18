
#include <iostream>
#include <array>
//#define array_size 20


int playerdig = 0;
int row_size = 4;
int col_size = 5;


int main()
{

	std::array<int, 20>solution_mono_dim;
	solution_mono_dim.fill(0);
	/*int solution[4][5] = {
		{ 0,0,0,0,0 },
		{ 0,0,0,0,0 },
		{ 0,0,0,0,0 },
		{ 0,0,0,0,0 }

	};*/
	
		for (int num_row = 0;num_row < 4; num_row++)
		{
			std::cout << std::endl;
			for (int numb_col = 0; numb_col < 5; numb_col++)
			{
				int idx = num_row * col_size + numb_col;


				switch (solution_mono_dim[idx])
				{
				case 0:
					std::cout<< " # ";//Pas creusé
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


