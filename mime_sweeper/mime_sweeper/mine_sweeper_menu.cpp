/* 计算机 1954263 宋子铭 */


#include <iostream>
#include <iomanip>
#include <conio.h>
#include <Windows.h>
#include "cmd_console_tools.h"

using namespace std;

void reset_map(int map[][30])
{
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 30; j++) {
			map[i][j] = 0;
		}
	}
}
void output_system(int& order)
{
	cout << "---------------------------------" << endl;
	cout << "1.选择难度并显示内部数组\n";
	cout << "2.输入初始位置并显示被打开的初始区域\n";
	cout << "3.内部数组基础版\n";
	cout << "4.内部数组完整版（标记、运行时间）\n";
	cout << "5.画出伪图形化框架并显示内部数据\n";
	cout << "6.检测鼠标位置和合法性（左键单击退出）\n";
	cout << "7.鼠标选择初始位置并显示被打开的初始区域\n";
	cout << "8.伪图形界面基础版\n";
	cout << "9.伪图形界面完整版\n";
	cout << "0.退出\n";
	cout << "---------------------------------" << endl;
	cout << "[请选择:]";
	while (1) {
		int x, y;
		cct_getxy(x, y);
		order = _getche();
		if (order >= '0' && order <= '9') {
			order -= '0';
			break;
		}
		else {
			rewind(stdin);
			cct_showch(x, y, ' ', COLOR_BLACK, COLOR_WHITE, 40);
			cct_gotoxy(x, y);
		}
	}
}
void back(int map[][30])
{
	cct_setcolor(COLOR_BLACK, COLOR_WHITE);
	cout << endl;
	cout << "按回车键继续";
	char choice;
	while (1) {
		choice = _getch();
		if (choice == '\r' || choice == '\n') {
			break;
		}
		else
			fflush(stdin);
	}
	cct_cls();
	cct_setconsoleborder(120, 40, 120, 9000);
	cct_setfontsize("新宋体", 28);
	reset_map(map);
	return;
}

