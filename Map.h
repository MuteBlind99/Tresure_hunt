#pragma once
#include <map>

class Map
{
private:
	int digged_;
	int notresure_;
	int tresure_;
public:

	Map() = default;
	Map(int digged, int tresure, int notresure);
	void PlayerDig(int playerdig);


	int get_tresure() { return tresure_; }

	void GetPositionTresur(int position);
	bool GetTresure(int bulleyes);
};

