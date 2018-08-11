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

bool GameMaster::MoveNum(int direction, int mode)
{
	bool flag = false;//作为是否有成功移动的标志
	int add_score = 0;//本次移动之后增加的分数
	int game_board_copy[4][4];//通过不同的copy方式达到不同的移动方向

	switch (direction)
	{
	case UP:
	{
		for (int i = 0; i < FOUR; ++i)
			for (int j = 0; j < FOUR; ++j)
				game_board_copy[i][j] = game_board[i][j];
	}break;
	case DOWN:
	{
		for (int i = 0; i < FOUR; ++i)
			for (int j = 0; j < FOUR; ++j)
				game_board_copy[i][j] = game_board[FOUR - 1 - i][FOUR - 1 - j];
	}break;
	case LEFT:
	{
		for (int i = 0; i < FOUR; ++i)
			for (int j = 0; j < FOUR; ++j)
				game_board_copy[i][j] = game_board[FOUR - 1 - j][i];
	}break;
	case RIGHT:
	{
		for (int i = 0; i < FOUR; ++i)
			for (int j = 0; j < FOUR; ++j)
				game_board_copy[i][j] = game_board[j][FOUR - 1 - i];
	}break;
	default:cout << "---------->中途出现了数据传输的错误或者数据遭到了污染，请联系程序开发者进行分析和解决" << endl; exit(-1); break;
	}

	//这是2048移动的关键代码
	for (int i = 0; i < FOUR; ++i)
	{
		for (int j = 0; j < FOUR; ++j)
		{
			//需要分成两种情况进行讨论，一种是该位置是空白的，一种是该位置有数据
			if (game_board_copy[i][j] == 0)
			{
				for (int find = i + 1; find < FOUR; ++find)
				{
					if (game_board_copy[find][j] != 0)//遇到不是0的数据就平移到当前的位置
					{
						game_board_copy[i][j] = game_board_copy[find][j];
						flag = true;
						break;
					}
				}
			}
			else
			{
				for (int find = i + 1; find < FOUR; ++find)
				{
					if (game_board_copy[find][j] != 0 && game_board_copy[find][j] != game_board_copy[i][j])
						break;
					if (game_board_copy[find][j] == game_board_copy[i][j])
					{
						game_board_copy[i][j] += game_board_copy[i][j];
						game_board_copy[find][j] = 0;
						flag = true;
						++add_score;
						break;
					}
				}
			}
		}
	}
	//以上是2048移动的关键代码

	//需要将原来所有的数据还回原来的游戏盘
	if (mode == 1)
	{
		switch (direction)
		{
		case UP:
		{
			for (int i = 0; i < FOUR; ++i)
				for (int j = 0; j < FOUR; ++j)
					game_board[i][j] = game_board_copy[i][j];
		}break;
		case DOWN:
		{
			for (int i = 0; i < FOUR; ++i)
				for (int j = 0; j < FOUR; ++j)
					game_board[FOUR - 1 - i][FOUR - 1 - j] = game_board_copy[i][j];
		}break;
		case LEFT:
		{
			for (int i = 0; i < FOUR; ++i)
				for (int j = 0; j < FOUR; ++j)
					game_board[FOUR - 1 - j][i] = game_board_copy[i][j];
		}break;
		case RIGHT:
		{
			for (int i = 0; i < FOUR; ++i)
				for (int j = 0; j < FOUR; ++j)
					game_board[j][FOUR - 1 - i] = game_board_copy[i][j];
		}break;
		default:cout << "---------->中途出现了数据传输的错误或者数据遭到了污染，请联系程序开发者进行分析和解决" << endl; exit(-1); break;
		}
	}

	score += add_score;//将分数上载

	return flag;
}

int GameMaster::DoOperate(int method)
{
	int ret = FALSEOPERATE;
	switch (method)
	{
	case FALSEOPERATE:ret = FALSEOPERATE; break;
	case INPUT:ret = INPUT; break;
	case VERSION:ret = VERSION; break;
	case QUIT:ret = QUIT; break;
	}
	return ret;
}

bool GameMaster::AddNum()
{
	int i = 0, j = 0;
	bool result = this->RandPlace(i, j);
	if (!result)
		return false;//此时无法添加数据
	else
	{
		if (rand() % 2 == 0)
			game_board[i][j] = 2;
		else
			game_board[i][j] = 4;
		return true;
	}
}