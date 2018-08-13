#include "GameUI.h"

GameUI::GameUI()
{
	for (int i = 0; i < MAXNUM + 1; ++i)
	{
		number[i].color = (NumColor)(int)pow(2, i);
		number[i].num_UI[0] = (30, ' ');
		number[i].num_UI[1] = (30, ' ');
		number[i].num_UI[7] = (30, ' ');
		number[i].num_UI[8] = (30, ' ');
	}

	//0
	{
		for (int i = 2; i < 7; ++i)
			number[0].num_UI[i] = (30, ' ');
	}

	//2
	{
		number[1].num_UI[2] = "            ███            ";
		number[1].num_UI[3] = "                █            ";
		number[1].num_UI[4] = "            ███            ";
		number[1].num_UI[5] = "            █                ";
		number[1].num_UI[6] = "            ███            ";
	}

	//4
	{
		number[2].num_UI[2] = "            █  █            ";
		number[2].num_UI[3] = "            █  █            ";
		number[2].num_UI[4] = "            ███            ";
		number[2].num_UI[5] = "                █            ";
		number[2].num_UI[6] = "                █            ";
	}

	//8
	{
		number[3].num_UI[2] = "            ███            ";
		number[3].num_UI[3] = "            █  █            ";
		number[3].num_UI[4] = "            ███            ";
		number[3].num_UI[5] = "            █  █            ";
		number[3].num_UI[6] = "            ███            ";
	}

	//16
	{
		number[4].num_UI[2] = "          █ ███           ";
		number[4].num_UI[3] = "          █ █               ";
		number[4].num_UI[4] = "          █ ███           ";
		number[4].num_UI[5] = "          █ █  █           ";
		number[4].num_UI[6] = "          █ ███           ";
	}

}

void GameUI::VersionUI() const
{
	string blank(50, ' ');
	string short_blank(25, ' ');
	cout << "\n\n\n\n";
	cout << blank << "VERSION 版本信息" << endl << endl << endl << endl;
	cout << short_blank << "●2048小游戏 exeUI版" << endl << endl;
	cout << short_blank << "●version 2.0" << endl << endl;
	cout << short_blank << "●开发时间：2018.8.9 - 2018.8.12" << endl << endl;
	cout << short_blank << "●开发者/Programmer：GaoRP" << endl << endl;
	cout << short_blank << "●联系方式/E-mail：HELLORPG2017@gmail.com" << endl << endl;
	return;
}

void GameUI::BeginUI()
{
	system("color 3F");

	string blank(50, ' ');
	string short_blank(40, ' ');
	cout << "\n\n\n\n\n\n\n";

	int time_get = time(0);
	if (time_get % 3 == 0)
	{
		cout << blank << "   ╔══════════════════════════════════════╗   " << endl;
		cout << blank << "   ║   .d888b.  .d88b.    j88D  .d888b.   ║   " << endl;
		cout << blank << "   ║   VP  `8D .8P  88.  j8~88  88   8D   ║   " << endl;
		cout << blank << "   ║      odD' 88  d'88 j8' 88  `VoooY'   ║   " << endl;
		cout << blank << "   ║    .88'   88 d' 88 V88888D .d~~~b.   ║   " << endl;
		cout << blank << "   ║   j88.    `88  d8'     88  88   8D   ║   " << endl;
		cout << blank << "   ║   888888D  `Y88P'      VP  `Y888P'   ║   " << endl;
		cout << blank << "   ╚══════════════════════════════════════╝   " << endl;
	}
	else if (time_get % 3 == 1)
	{
		cout << blank << "╔════════════════════════════════════════════╗" << endl;
		cout << blank << "║  ..#######....#####...##.........#######.  ║" << endl;
		cout << blank << "║  .##.....##..##...##..##....##..##.....##  ║" << endl;
		cout << blank << "║  ........##.##.....##.##....##..##.....##  ║" << endl;
		cout << blank << "║  ..#######..##.....##.##....##...#######.  ║" << endl;
		cout << blank << "║  .##........##.....##.#########.##.....##  ║" << endl;
		cout << blank << "║  .##.........##...##........##..##.....##  ║" << endl;
		cout << blank << "║  .#########...#####.........##...#######.  ║" << endl;
		cout << blank << "╚════════════════════════════════════════════╝" << endl;
	}
	else
	{
		cout << short_blank << "╔══════════════════════════════════════════════════════════════════╗" << endl;
		cout << short_blank << "║    .--~*teu.        .n~~%x.             xeee       u+=~~~+u.     ║" << endl;
		cout << short_blank << "║   dF     988Nx    x88X   888.          d888R     z8F      `8N.   ║" << endl;
		cout << short_blank << "║  d888b   `8888>  X888X   8888L        d8888R    d88L       98E   ║" << endl;
		cout << short_blank << "║  ?8888>  98888F X8888X   88888       @ 8888R    98888bu.. .@*    ║" << endl;
		cout << short_blank << "║   \"**\"  x88888~ 88888X   88888X    .P  8888R    \"88888888NNu.    ║" << endl;
		cout << short_blank << "║        d8888*`  88888X   88888X   :F   8888R     \" * 8888888888  ║" << endl;
		cout << short_blank << "║      z8**\"`   : 88888X   88888f  x\"    8888R     .zf\"\"*8888888L  ║" << endl;
		cout << short_blank << "║    :?.....  ..F 48888X   88888  d8eeeee88888eer d8F      ^%888E  ║" << endl;
		cout << short_blank << "║   <\"\"888888888~  ?888X   8888\"         8888R    88>        `88~  ║" << endl;
		cout << short_blank << "║   8:  \"888888*    \"88X   88*`          8888R    '%N.       d*\"   ║" << endl;
		cout << short_blank << "║   \"\"    \"**\"`       ^\"===\"`         \"*%%%%%%**~    ^\"=====\"`     ║" << endl;
		cout << short_blank << "╚══════════════════════════════════════════════════════════════════╝" << endl;
	}
	cout << blank << blank << "         " << endl;
	cout << blank << blank << "          version 2.0" << endl;
	cout << blank << blank << "          By RP·G 2018.8.11" << endl;
	cout << blank << blank << "      ╘═════════════════════════" << endl;

	//cout << "\n\n\n\n\n\n\n";
	cout << endl << endl;
	cout << blank << "   ╔══════════════════════════════════════╗   " << endl;
	cout << blank << "   ║           按回车键开始游戏           ║   " << endl;
	cout << blank << "   ║    Press ENTER to enter the game!    ║   " << endl;
	cout << blank << "   ╚══════════════════════════════════════╝   " << endl;
	cout << endl << endl << endl << endl;

	cout << "->如果您发现任何BUG请与开发者联系 |" << endl;
	cout << "->If you find any BUG, please connect with the programmer |" << endl;

	do
	{
		int get = (_getch());
		if (get == 13)
			break;
		else if (get == 'v')
		{
			system("CLS");
			this->VersionUI();
		}
	} while (1);

	system("CLS");

	return;
}

void GameUI::PrintGameBoard(class GameMaster game) const
{
	//游戏盘的大小应该是94的长度，高度是34行
	int print_board[4][4];//这是打印的依据，可以方便寻找到需要的numUI
	for (int i = 0; i < FOUR; ++i)
	{
		for (int j = 0; j < FOUR; ++j)
		{
			if (game.game_board[i][j] == 0)
				print_board[i][j] = 0;
			else
				print_board[i][j] = log(game.game_board[i][j]) / log(2);
		}
	}

	cout << endl;
	cout << "╔";
	for (int i = 1; i < 4 * NUMWIDTH + 4; ++i)
		cout << "═";
	cout << "╗" << endl;
	//前述是输出了游戏盘的头

	for (int i = 1; i < 4 * NUMHEIGHT + 4; ++i)
	{
		cout << "->" << endl;
	}

	return;
}

