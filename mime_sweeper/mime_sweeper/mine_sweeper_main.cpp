/* 计算机 1954263 宋子铭 */
#include"mine_sweeper.h"

int main() 
{
	cct_setconsoleborder(120, 40, 120, 9000);
	cct_setcolor(COLOR_BLACK, COLOR_WHITE);
	cct_setcursor(CURSOR_VISIBLE_NORMAL);
	cct_setfontsize("新宋体", 24);

	int order,model,select_row,select_col;
	int map[16][30] = { 0 };
	do {
		int visited[16][30] = { 0 };//辅助数组，标记是否被遍历过，遍历过为1，被标记为雷为2
		output_system(order);
		if (order == 0)
			break;
		if (init_model(model, map, visited, order, select_row, select_col)) {
			
			LARGE_INTEGER tick, begin;

			QueryPerformanceFrequency(&tick);	//获得计数器频率
			QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数

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