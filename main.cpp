#include "GameMaster.h"

using namespace std;

int main()
{
	system("color 3F");
	system("mode con cols=150 lines=45");//可以用于强行设置窗口大小
	GameUI UI;
	GameMaster Game;
	UI.BeginUI();
	Game.InitGameBoard();
	UI.PrintGameBoard(Game);
	return 0;
}