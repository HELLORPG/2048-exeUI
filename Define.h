#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include <Windows.h>
#include <cmath>
//将所有需要的头文件尽可能的写在了Define.h中

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

#define ZERO 0
#define TWO 2
#define FOUR 4

#define FUNCTION 224
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
//这五个是所需要的上下左右键的捕获数据

#define INPUT 1//这个是作为在游戏中输入字符的标志符号
#define ESC 27//这个是作为在游戏中强行退出的捕获码
#define QUIT -1//作为与上面对应的退出的标志符号
#define VERSION 100//作为查看版本的标志符号
#define FALSEOPERATE 0//作为错误的操作提示

#define RANDTEST 0//为1的时候作为随机数的开发者监视模式

#define MAXNUM 12//作为一共有多少个数字可能性的表示

#define NUMWIDTH 30//每一个数字UI的宽度
#define NUMHEIGHT 9//每一个数字UI的高度