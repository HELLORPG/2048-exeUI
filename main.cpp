#include "GameMaster.h"

using namespace std;

int main()
{
	system("color 3F");
	system("mode con cols=120 lines=40");//可以用于强行设置窗口大小
	GameUI UI;
	GameMaster Game;
	UI.BeginUI();
	return 0;
}