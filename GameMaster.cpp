#include "GameMaster.h"

GameMaster::GameMaster(string input_name)
{
	player_name = input_name;//用户名的存入
}

bool GameMaster::RandPlace(int &row, int &col) const
{
	bool any_blank = false;
	for (int i = 0; i < FOUR; ++i)
	{
		for (int j = 0; j < FOUR; ++j)
		{
			if (game_board[i][j] == 0)
			{
				any_blank = true;
			}
		}
	}
	if (!any_blank)
		return false;//这个时候已经没有了任何空位

	do
	{
		row = rand() % 4;
		col = rand() % 4;
	} while (game_board[row][col] != 0);
	return true;
}

void GameMaster::InitGameBoard()
{
	for (int i = 0; i < FOUR; ++i)
	{
		for (int j = 0; j < FOUR; ++j)
		{
			game_board[i][j] = 0;
		}
	}
	//需要将左右的位置归零，作为一个保险操作
#if RANDTEST == 1
	cout << "---------->随机种子数为：" << srand(time(0)) << endl;
#else
	srand(time(0));
#endif
	game_board[rand()][rand()] = TWO;
	int i = 0, j = 0;
	this->RandPlace(i, j);
	game_board[i][j] = TWO;
	return;
}

int GameMaster::GetOperate() const
{
	int ret = FALSEOPERATE;//0是无效的捕捉值
	switch (_getch())
	{
	case 224://这个时候是功能键
	{
		switch (_getch())
		{
		case UP:ret = UP; break;
		case DOWN:ret = DOWN; break;
		case LEFT:ret = LEFT; break;
		case RIGHT:ret = RIGHT; break;
		default:ret = FALSEOPERATE; break;
		}
		break;
	}
	case 'w':ret = UP; break;
	case 's':ret = DOWN; break;
	case 'a':ret = LEFT; break;
	case 'd':ret = RIGHT; break;
	case 'i':ret = INPUT; break;
	case ESC:ret = QUIT; break;
	case 'v':ret = VERSION; break;
	default:break;
	}
	return ret;
}

int GameMaster::DoOperate(int &method)
{
	switch (method)
	{

	}
}