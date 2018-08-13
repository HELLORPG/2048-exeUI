#pragma once
#include "Define.h"
#include "GameMaster.h"

enum NumColor { one = 2, two = 4, three = 8, four = 16, five = 32, six = 64, seven = 128, eight = 256, nine = 512, ten = 1024, eleven = 2048, twelve = 4096 };
struct NumUI
{
	NumColor color;
	string num_UI[9];
};

class GameUI
{
private:
	NumUI number[MAXNUM + 1];
public:
	GameUI();
	~GameUI() { }
	void BeginUI();
	void VersionUI() const;
	void PrintGameBoard(class GameMaster game) const;
};
