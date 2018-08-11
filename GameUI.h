#pragma once
#include "Define.h"
#include "GameMaster.h"

enum NumColor { one = 2, two = 4, three = 8, four = 16, five = 32, six = 64, seven = 128, eight = 256, nine = 512, ten = 1024, eleven = 2048, twelve = 4096};
struct NumUI
{
	NumColor color;
	string num_UI[10];
};

class GameUI
{
private:
	NumUI number[MAXNUM];
public:
	GameUI();
	~GameUI() { }
	void BeginUI();
	void PrintGameBoard(class GameMaster) const;
};
