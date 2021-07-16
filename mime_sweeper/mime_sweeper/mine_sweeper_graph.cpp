/* 计算机 1954263 宋子铭 */
#include"mine_sweeper.h"
void draw_graph(const int model, const int map[][30]) 
{
	int row = judge_row(model), col = judge_col(model);
	cct_setfontsize("Terminal", 16, 8);
	cct_setconsoleborder(6*(col+1), 6*(row+1), 120, 9000);
	cout << endl;
	for (int i = 0; i < col ; i++) {
		cout << setiosflags(ios::right)<<setw(6)<<i ;
	}
	cout << endl;

	cct_setcolor(COLOR_BLACK, COLOR_WHITE);
	cout << "  ";
	int x, y;
	cct_getxy(x, y);
	cct_showstr(x, y, "╔", COLOR_WHITE, COLOR_BLACK);
	for (int i = 0; i < col-1; i++) {
		cct_getxy(x, y);
		cct_showstr(x, y, "══╦", COLOR_WHITE, COLOR_BLACK);
	}
	cct_getxy(x, y);
	cct_showstr(x, y, "══╗", COLOR_WHITE, COLOR_BLACK);
	cout << endl;

	char head = 'A';
	for (int i = 0; i < row; i++, head++) {
		cct_setcolor(COLOR_BLACK, COLOR_WHITE);
		cout << "  ";
		for (int j = 0; j < col; j++) {
			cct_getxy(x, y);
			cct_showstr(x, y, "║", COLOR_WHITE, COLOR_BLACK);
			cct_getxy(x, y);
			cct_showch(x, y, ' ', COLOR_HCYAN, COLOR_HCYAN, 4);
		}
		cct_getxy(x, y);
		cct_showstr(x, y, "║", COLOR_WHITE, COLOR_BLACK);
		cct_setcolor(COLOR_BLACK, COLOR_WHITE);
		cout << endl;
		cout << head << " ";
		for (int j = 0; j < col; j++) {
			cct_getxy(x, y);
			cct_showstr(x, y, "║", COLOR_WHITE, COLOR_BLACK);
			cct_getxy(x, y);
			cct_showch(x, y, ' ', COLOR_HCYAN, COLOR_HCYAN, 1);
			cct_getxy(x, y);
			if (map[i][j] == 0)
				cct_showch(x, y, ' ', COLOR_HCYAN, COLOR_HCYAN, 1);
			else {
				char ch = int_trans_char(map[i][j]);
				if (map[i][j] == BOOM)
					cct_showch(x, y, ch, COLOR_HCYAN, COLOR_BLACK, 1);
				else
					cct_showch(x, y, ch, COLOR_HCYAN, map[i][j], 1);
			}
			cct_getxy(x, y);
			cct_showch(x, y, ' ', COLOR_HCYAN, COLOR_HCYAN, 2);
		}
		cct_getxy(x, y);
		cct_showstr(x, y, "║", COLOR_WHITE, COLOR_BLACK);
		cout << endl;
		cct_setcolor(COLOR_BLACK, COLOR_WHITE);
		if (i != row - 1) {
			cct_setcolor(COLOR_BLACK, COLOR_WHITE);
			cout << "  ";
			cct_getxy(x, y);
			cct_showstr(x, y, "║", COLOR_WHITE, COLOR_BLACK);
			for (int i = 0; i < col - 1; i++) {
				cct_getxy(x, y);
				cct_showstr(x, y, "══╬", COLOR_WHITE, COLOR_BLACK);
			}
			cct_getxy(x, y);
			cct_showstr(x, y, "══╣", COLOR_WHITE, COLOR_BLACK);
			cout << endl;
		}

	}

	cout << "  ";
	cct_getxy(x, y);
	cct_showstr(x, y, "╚", COLOR_WHITE, COLOR_BLACK);
	for (int i = 0; i < col - 1; i++) {
		cct_getxy(x, y);
		cct_showstr(x, y, "══╩", COLOR_WHITE, COLOR_BLACK);
	}
	cct_getxy(x, y);
	cct_showstr(x, y, "══╝", COLOR_WHITE, COLOR_BLACK);
	cout << endl;
	cct_setcolor(COLOR_BLACK, COLOR_WHITE);
}
void draw_hide_graph(const int model, const int map[][30], const int visited[][30])
{
	int row = judge_row(model), col = judge_col(model);
	cct_setfontsize("Terminal", 16, 8);
	cct_setconsoleborder(6 * (col + 1), 6 * (row + 1), 120, 9000);
	cout << endl;
	for (int i = 0; i < col; i++) {
		cout << setiosflags(ios::right) << setw(6) << i;
	}
	cout << endl;

	cct_setcolor(COLOR_BLACK, COLOR_WHITE);
	cout << "  ";
	int x, y;
	cct_getxy(x, y);
	cct_showstr(x, y, "╔", COLOR_WHITE, COLOR_BLACK);
	for (int i = 0; i < col - 1; i++) {
		cct_getxy(x, y);
		cct_showstr(x, y, "══╦", COLOR_WHITE, COLOR_BLACK);
	}
	cct_getxy(x, y);
	cct_showstr(x, y, "══╗", COLOR_WHITE, COLOR_BLACK);
	cout << endl;

	char head = 'A';
	for (int i = 0; i < row; i++, head++) {
		cct_setcolor(COLOR_BLACK, COLOR_WHITE);
		cout << "  ";
		for (int j = 0; j < col; j++) {
			cct_getxy(x, y);
			cct_showstr(x, y, "║", COLOR_WHITE, COLOR_BLACK);
			cct_getxy(x, y);
			cct_showch(x, y, ' ', visited[i][j]+10, visited[i][j] + 10, 4);
		}
		cct_getxy(x, y);
		cct_showstr(x, y, "║", COLOR_WHITE, COLOR_BLACK);
		cct_setcolor(COLOR_BLACK, COLOR_WHITE);
		cout << endl;
		cout << head << " ";
		for (int j = 0; j < col; j++) {
			cct_getxy(x, y);
			cct_showstr(x, y, "║", COLOR_WHITE, COLOR_BLACK);
			cct_getxy(x, y);
			cct_showch(x, y, ' ', visited[i][j] + 10, visited[i][j] + 10, 1);
			cct_getxy(x, y);
			if (visited[i][j] == 0) {
				cct_showch(x, y, ' ', visited[i][j] + 10, visited[i][j] + 10, 1);
			}
			else if (visited[i][j] == 2) {
				cct_showch(x, y, '#', visited[i][j] + 10, COLOR_HBLACK, 1);
			}
			else {
				if (map[i][j] == 0)
					cct_showch(x, y, ' ', COLOR_HCYAN, COLOR_HCYAN, 1);
				else {
					char ch = int_trans_char(map[i][j]);
					if (map[i][j] == BOOM)
						cct_showch(x, y, ch, COLOR_HCYAN, COLOR_BLACK, 1);
					else
						cct_showch(x, y, ch, COLOR_HCYAN, map[i][j], 1);
				}
			}
			cct_getxy(x, y);
			cct_showch(x, y, ' ', visited[i][j] + 10, visited[i][j] + 10, 2);
		}
		cct_getxy(x, y);
		cct_showstr(x, y, "║", COLOR_WHITE, COLOR_BLACK);
		cout << endl;
		cct_setcolor(COLOR_BLACK, COLOR_WHITE);
		if (i != row - 1) {
			cct_setcolor(COLOR_BLACK, COLOR_WHITE);
			cout << "  ";
			cct_getxy(x, y);
			cct_showstr(x, y, "║", COLOR_WHITE, COLOR_BLACK);
			for (int i = 0; i < col - 1; i++) {
				cct_getxy(x, y);
				cct_showstr(x, y, "══╬", COLOR_WHITE, COLOR_BLACK);
			}
			cct_getxy(x, y);
			cct_showstr(x, y, "══╣", COLOR_WHITE, COLOR_BLACK);
			cout << endl;
		}
	}
	cout << "  ";
	cct_getxy(x, y);
	cct_showstr(x, y, "╚", COLOR_WHITE, COLOR_BLACK);
	for (int i = 0; i < col - 1; i++) {
		cct_getxy(x, y);
		cct_showstr(x, y, "══╩", COLOR_WHITE, COLOR_BLACK);
	}
	cct_getxy(x, y);
	cct_showstr(x, y, "══╝", COLOR_WHITE, COLOR_BLACK);
	cout << endl;
	cct_setcolor(COLOR_BLACK, COLOR_WHITE);
}

bool judge_position(const int model,const int x, const int y) 
{
	int row = judge_row(model), col = judge_col(model);
	if (y % 3 == 2 || y >= 3 * (row + 1) || y < 3)
		return false;
	else if ((x - 3) % 6 == 5 || (x - 3) % 6 == 0 || x > 6 * (col)+3 || x < 3)
		return false;
	else
		return true;
}
char trans_to_row(int relativey)
{
	return 'A' + relativey / 3 - 1;
}
char trans_to_col(int relativex) 
{
	return '0' + (relativex - 4) / 6;
}
int trans_row(char row) 
{
	return row - 'A';
}
int trans_col(char col)
{
	return col - '0';
}
void mouse_move(int model) 
{
	int x , y ;
	int ret, maction;
	int keycode1, keycode2;
	int loop = 1;

	cct_getxy(x, y);
	int row = judge_row(model), col = judge_col(model);
	int graph_beginx = 0;
	int graph_beginy = y - (row + 1) * 3;

	cct_enable_mouse();
	while (loop) {
		/* 读鼠标/键盘，返回值为下述操作中的某一种, 当前鼠标位置在<X,Y>处 */
		int X, Y;
		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
		if (ret == CCT_MOUSE_EVENT) {
			cct_gotoxy(x, y);
			cout << "[当前光标] :" ;
			if (maction == MOUSE_LEFT_BUTTON_CLICK) {
				loop = 0;
				break;
			}
			else if (maction == MOUSE_ONLY_MOVED) 
			{
				int tempy = Y - graph_beginy;
				if (!judge_position(model, X, tempy)) {
					cout << "位置非法                    ";
				}
				else {
					cout << trans_to_row (tempy)<<"行"<<trans_to_col(X)<<"列          ";
				}
			}
			
		} 
	}
}

int graph_row_col_select(int& select_row, int& select_col, const int model)
{
	//退出返回0
	//点开返回1
	//看时间返回2
	//成功标记或取消标记返回3
	//其他情况则继续
	int x, y;
	int ret, maction;
	int keycode1, keycode2;
	int loop = 1;

	cct_getxy(x, y);
	int row = judge_row(model), col = judge_col(model);
	int graph_beginx = 0;
	int graph_beginy = y - (row + 1) * 3;

	cct_enable_mouse();
	while (loop) {
		/* 读鼠标/键盘，返回值为下述操作中的某一种, 当前鼠标位置在<X,Y>处 */
		int X, Y;
		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
		if (ret == CCT_MOUSE_EVENT) {
			cct_gotoxy(0, y);
			cout << "[当前光标] :";
			if (maction == MOUSE_LEFT_BUTTON_CLICK) {
				int tempy = Y - graph_beginy;
				if (judge_position(model, X, tempy)) {
					select_row = trans_row(trans_to_row(tempy));
					select_col = trans_col((trans_to_col(X)));
					return 1;
				}
			}
			else if (maction == MOUSE_ONLY_MOVED)
			{
				int tempy = Y - graph_beginy;
				if (!judge_position(model, X, tempy)) {
					cout << "位置非法                    ";
				}
				else {
					cout << trans_to_row(tempy) << "行" << trans_to_col(X) << "列          ";
				}
			}
			else if (maction == MOUSE_RIGHT_BUTTON_CLICK)
			{
				int tempy = Y - graph_beginy;
				if (judge_position(model, X, tempy)) {
					select_row = trans_row(trans_to_row(tempy));
					select_col = trans_col((trans_to_col(X)));
					return 3;
				}
			}
		}
		if (ret == CCT_KEYBOARD_EVENT) {
			if (keycode1 == 27) {
				//ESC键
				return 0;
			}
			if (keycode1 == 32) {
				return 2;
			}
		}
	}
	return 0;
}

void DFS_draw_unhide_graph(const int model, const int select_row, const int select_col,  const int map[][30], int visited[][30])
{
	int  max_row = judge_row(model), max_col = judge_col(model);
	char ch = int_trans_char(map[select_row][select_col]);
	if (ch == '*') {
		return;
	}
	visited[select_row][select_col] = 1;
	int x = 4+select_col*6;
	int y = 3+select_row*3;
	cct_showch(x, y, ' ', visited[select_row][select_col] + 10, visited[select_row][select_col] + 10, 4);
	cct_showch(x, y+1, ' ', visited[select_row][select_col] + 10, visited[select_row][select_col] + 10, 1);
	if (map[select_row][select_col] == 0)
		cct_showch(x+1, y+1, ' ', COLOR_HCYAN, COLOR_HCYAN, 1);
	else {
		char ch = int_trans_char(map[select_row][select_col]);
		if (map[select_row][select_col] == BOOM)
			cct_showch(x + 1, y+1, ch, COLOR_HCYAN, COLOR_BLACK, 1);
		else
			cct_showch(x + 1, y+1, ch, COLOR_HCYAN, map[select_row][select_col], 1);
	}
	cct_getxy(x, y);
	cct_showch(x, y, ' ', visited[select_row][select_col] + 10, visited[select_row][select_col] + 10, 2);
	if (ch == '0') {
		if (select_row - 1 >= 0 && visited[select_row - 1][select_col] != 1)
			DFS_draw_unhide_graph(model, select_row - 1, select_col,  map, visited);
		if (select_row + 1 < max_row && visited[select_row + 1][select_col] != 1)
			DFS_draw_unhide_graph(model, select_row + 1, select_col,  map, visited);
		if (select_col - 1 >= 0 && visited[select_row][select_col - 1] != 1)
			DFS_draw_unhide_graph(model, select_row, select_col - 1, map, visited);
		if (select_col + 1 < max_col && visited[select_row][select_col + 1] != 1)
			DFS_draw_unhide_graph(model, select_row, select_col + 1,  map, visited);
		if (select_col - 1 >= 0 && select_row - 1 >= 0 && visited[select_row - 1][select_col - 1] != 1)
			DFS_draw_unhide_graph(model, select_row - 1, select_col - 1,  map, visited);
		if (select_col - 1 >= 0 && select_row + 1 < max_row && visited[select_row + 1][select_col - 1] != 1)
			DFS_draw_unhide_graph(model, select_row + 1, select_col - 1,  map, visited);
		if (select_col + 1 < max_col && select_row - 1 >= 0 && visited[select_row - 1][select_col + 1] != 1)
			DFS_draw_unhide_graph(model, select_row - 1, select_col + 1,  map, visited);
		if (select_col + 1 < max_col && select_row + 1 < max_row && visited[select_row + 1][select_col + 1] != 1)
			DFS_draw_unhide_graph(model, select_row + 1, select_col + 1,  map, visited);
	}
	return;
}
void draw_unhide_graph(const int model, const int select_row, const int select_col, const int map[][30], int visited[][30])
{
	/*draw_hide_graph(model, map, visited);*/
	int x1, y1;
	cct_getxy(x1, y1);
	if (map[select_row][select_col] != BOOM) {
		DFS_draw_unhide_graph(model, select_row, select_col, map, visited);
	}
	else {
		int tx = select_col * 6 + 4;
		int ty = (select_row + 1) * 3;
		cct_showch(tx, ty, ' ', visited[select_row][select_col] + 10, visited[select_row][select_col] + 10, 4);
		cct_showch(tx, ty + 1, ' ', visited[select_row][select_col] + 10, visited[select_row][select_col] + 10, 1);
		cct_showch(tx + 1, ty + 1, '*', visited[select_row][select_col] + 10, COLOR_BLACK, 1);
		cct_showch(tx + 2, ty + 1, ' ', visited[select_row][select_col] + 10, visited[select_row][select_col] + 10, 2);
	}
	cct_gotoxy(x1, y1);
	cct_setcolor(COLOR_BLACK, COLOR_WHITE);
}

void play_game_graph(const int model, const int order, int map[][30], int visited[][30], LARGE_INTEGER tick, LARGE_INTEGER begin)
{
	int select_row, select_col;
	int row_max = judge_row(model), col_max = judge_col(model);

	int x, y;
	cct_getxy(x, y);
	cct_gotoxy(0, 0);
	if (order == 8)
		cout << "按ESC退出";
	else if (order == 9)
		cout << "按ESC退出,空格显示时间";
	cct_gotoxy(x, y);
	while (1)
	{
		int result = graph_row_col_select(select_row,select_col,model);
		if (result == 0)
			return;
		else if (result == 1)
			visited[select_row][select_col] = 1;
		else if (result == 2) {
			cct_gotoxy(0, 0);
			display_time(tick, begin);
			cout << "   按ESC退出,空格显示时间";
			cct_gotoxy(x, y);
			continue;
		}
		else if (result == 3) {
			int tx = select_col*6+4;
			int ty = (select_row + 1) * 3;
			if (visited[select_row][select_col] == 2) {
				visited[select_row][select_col] = 0;
				cct_showch(tx, ty, ' ', visited[select_row][select_col] + 10, visited[select_row][select_col] + 10, 4);
				cct_showch(tx, ty +1, ' ', visited[select_row][select_col] + 10, visited[select_row][select_col] + 10, 4);
			}
			else if (visited[select_row][select_col] == 0) {
				visited[select_row][select_col] = 2;
				cct_showch(tx, ty, ' ', visited[select_row][select_col] + 10, visited[select_row][select_col] + 10, 4);
				cct_showch(tx, ty + 1, ' ', visited[select_row][select_col] + 10, visited[select_row][select_col] + 10, 1);
				cct_showch(tx +1, ty +1, '#', visited[select_row][select_col] + 10, COLOR_HBLACK, 1);
				cct_showch(tx +2, ty + 1, ' ', visited[select_row][select_col] + 10, visited[select_row][select_col] + 10, 2);
			}
			cct_setcolor(COLOR_BLACK, COLOR_WHITE);
			cct_gotoxy(x, y);
			continue;
		}
		draw_unhide_graph(model, select_row, select_col, map, visited);
		int x2, y2;
		cct_getxy(x2, y2);
		int judge = judge_game(map, visited, model, select_row, select_col);
		if (judge == 1) {
			cct_gotoxy(0, y2);
			cout << "恭喜胜利，游戏结束          " << endl;
			break;
		}
		if (judge == 0) {
			cct_gotoxy(0, y2);
			cout << "你输了，游戏结束        " << endl;
			break;
		}
	}
}
