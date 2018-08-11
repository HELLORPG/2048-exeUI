#include "GameUI.h"

GameUI::GameUI()
{
	for (int i = 0; i < MAXNUM; ++i)
	{
		number[i].color = (NumColor)(int)pow(2, i + 1);
	}
	number[0].num_UI[0] = (20, ' ');
}
void GameUI::BeginUI()
{
	string blank(35, ' ');
	string short_blank(25, ' ');
	cout << "\n\n\n\n\n\n\n\n\n";
	if (time(0) % 3 == 0)
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
	else if (time(0) % 3 == 1)
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
	cout << "\n\n\n\n\n\n\n";
	cout << "->如果您发现任何BUG请与开发者联系 |" << endl;
	cout << "->If you find any BUG, please connect with the programmer |" << endl;
	return;
}