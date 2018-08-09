#pragma once
#include "Define.h"
#include "GameUI.h"

class GameMaster
{
	friend class GameUI;
private:
	string player_name;
	int game_board[4][4] = { 0 };//作为2048基础数据的存储形式
	int score = 0;
	//mutable vector<int> mod{ 0 };//作为目前行使的模式的标志依据
public:
	GameMaster() = default;//默认的构造函数
	GameMaster(string input_name);//输入用户名之后的初始化
	~GameMaster() { }
	void InitGameBoard();//初始化随机数以及游戏盘
	bool RandPlace(int &row, int &col) const;//用于随机2048游戏盘上的某一个有效位置
	int GetOperate() const;
	int DoOperate(int method);//返回值用于告诉UI下一步的动作
	bool MoveNum(int direction);//用于返回这次移动是否是合法的
};