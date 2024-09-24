#pragma once
#include <map>

class Map
{
private:
	int digged_;
	
public:
	
	Map() = default;
	

	void ShowMap(int row_size, int col_size);
	
	bool GetNumberValid(int player_dig);
};

