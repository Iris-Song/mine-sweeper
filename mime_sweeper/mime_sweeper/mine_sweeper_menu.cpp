/* ����� 1954263 ������ */


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
	cout << "1.ѡ���ѶȲ���ʾ�ڲ�����\n";
	cout << "2.�����ʼλ�ò���ʾ���򿪵ĳ�ʼ����\n";
	cout << "3.�ڲ����������\n";
	cout << "4.�ڲ����������棨��ǡ�����ʱ�䣩\n";
	cout << "5.����αͼ�λ���ܲ���ʾ�ڲ�����\n";
	cout << "6.������λ�úͺϷ��ԣ���������˳���\n";
	cout << "7.���ѡ���ʼλ�ò���ʾ���򿪵ĳ�ʼ����\n";
	cout << "8.αͼ�ν��������\n";
	cout << "9.αͼ�ν���������\n";
	cout << "0.�˳�\n";
	cout << "---------------------------------" << endl;
	cout << "[��ѡ��:]";
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
	cout << "���س�������";
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
	cct_setfontsize("������", 28);
	reset_map(map);
	return;
}

