/* ����� 1954263 ������ */
#include"mine_sweeper.h"

int main() 
{
	cct_setconsoleborder(120, 40, 120, 9000);
	cct_setcolor(COLOR_BLACK, COLOR_WHITE);
	cct_setcursor(CURSOR_VISIBLE_NORMAL);
	cct_setfontsize("������", 24);

	int order,model,select_row,select_col;
	int map[16][30] = { 0 };
	do {
		int visited[16][30] = { 0 };//�������飬����Ƿ񱻱�������������Ϊ1�������Ϊ��Ϊ2
		output_system(order);
		if (order == 0)
			break;
		if (init_model(model, map, visited, order, select_row, select_col)) {
			
			LARGE_INTEGER tick, begin;

			QueryPerformanceFrequency(&tick);	//��ü�����Ƶ��
			QueryPerformanceCounter(&begin);	//��ó�ʼӲ������������

			if (order == 1) 
				display_array(model, map);
			else if (order == 2|| order == 3 || order == 4){
			    display_unhide(model, select_row, select_col, map, visited);
				if (order == 3 || order == 4)
				    play_game_base(model, order, map, visited, tick, begin);
			}
			else if (order == 5 || order == 6) {
				draw_graph(model, map);
				if (order == 6)
					mouse_move(model);
			}
			else if (order == 7) 
					draw_unhide_graph(model, select_row, select_col, map, visited);
			else if (order == 8 || order == 9) {
				draw_unhide_graph(model, select_row, select_col, map, visited);
				play_game_graph(model, order, map, visited, tick, begin);
			}
		}
		back(map);
	} while (1);
	return 0;
}