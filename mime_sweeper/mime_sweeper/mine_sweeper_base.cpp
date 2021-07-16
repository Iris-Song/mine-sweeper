
#include"mine_sweeper.h"

void display_array(const int model,const int map[][30])
{
    int row=judge_row(model), col= judge_col(model);
       
    cout << "内部数组：" << endl;
    cout << "  |";
    for (int i = 0; i < col&&i<9; i++) {
        cout << i + 1 << " ";
    }
    for (int i = 9; i < col; i++) {
        cout << char('a' + i-9)<<" ";
    }
    cout << endl;
    cout << "--+"; 
    for (int i = 0; i < col; i++) {
        cout << "--";
    }
    cout << endl;
    char head = 'A';
    for (int i = 0; i < row; i++, head++) {
        cout << head << " |";
        for (int j = 0; j < col; j++) {
            if (map[i][j] != BOOM)
                cout << map[i][j] << " ";
            else
                cout << "* ";
        }
        cout << endl;
    }
    cout << endl;
    return;
}
void display_hide_array(const int model, const int map[][30], const int visited[][30])
{
    int row = judge_row(model), col = judge_col(model);
    cout << "  |";
    for (int i = 0; i < col && i < 9; i++) {
        cout << i + 1 << " ";
    }
    for (int i = 9; i < col; i++) {
        cout << char('a' + i - 9) << " ";
    }
    cout << endl;
    cout << "--+";
    for (int i = 0; i < col; i++) {
        cout << "--";
    }
    cout << endl;
    char head = 'A';
    for (int i = 0; i < row; i++, head++) {
        cout << head << " |";
        for (int j = 0; j < col; j++) {
            if (visited[i][j]==0)
                cout << "X ";
            else if(visited[i][j] == 2){
                int x, y;
                cct_getxy(x, y);
                cct_showch(x, y, 'X', COLOR_RED, COLOR_WHITE, 1);
                cct_setcolor(COLOR_BLACK, COLOR_WHITE);
                cout << " ";
            }
            else {
                int x, y;
                cct_getxy(x, y);
                char ch = int_trans_char(map[i][j]);
                if(ch=='*')
                    cct_showch(x, y, ch, COLOR_BLACK, COLOR_WHITE, 1);
                else
                    cct_showch(x, y, ch, COLOR_HYELLOW, map[i][j], 1);
                cct_setcolor(COLOR_BLACK, COLOR_WHITE);
                cout << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
    return;
}
//void display_visited_array(const int model, const bool visited[][30])
//{
//    int row = judge_row(model), col = judge_col(model);
//
//    cout << "内部数组：" << endl;
//    cout << "  |";
//    for (int i = 0; i < col && i < 9; i++) {
//        cout << i + 1 << " ";
//    }
//    for (int i = 9; i < col; i++) {
//        cout << char('a' + i - 9) << " ";
//    }
//    cout << endl;
//    cout << "--+";
//    for (int i = 0; i < col; i++) {
//        cout << "--";
//    }
//    cout << endl;
//    char head = 'A';
//    for (int i = 0; i < row; i++, head++) {
//        cout << head << " |";
//        for (int j = 0; j < col; j++) {
//            if (visited[i][j] == 1)
//                cout << 1 << " ";
//            else
//                cout << "0 ";
//        }
//        cout << endl;
//    }
//    cout << endl;
//    return;
//}

void DFS_display_unhide(const int model,const int select_row, const int select_col, const int bgrow,const int bgcol,const int map[][30], int visited[][30])
{
    int  max_row = judge_row(model), max_col = judge_col(model);
    char ch = int_trans_char(map[select_row][select_col]);
    if (ch == '*') {
        return;
    }
    visited[select_row][select_col] = 1;
    cct_showch(bgrow + 2 * select_col, bgcol + select_row, ch, COLOR_HYELLOW, map[select_row][select_col],1);
    if (ch == '0') {
        if (select_row - 1 >= 0&&visited[select_row-1][select_col]!=1)
            DFS_display_unhide(model,select_row - 1, select_col, bgrow, bgcol,map,visited);
        if (select_row + 1 < max_row && visited[select_row+1][select_col] != 1)
            DFS_display_unhide(model, select_row + 1, select_col, bgrow, bgcol, map, visited);
        if (select_col - 1 >= 0 && visited[select_row][select_col-1] != 1)
            DFS_display_unhide(model, select_row , select_col - 1, bgrow, bgcol, map, visited);
        if (select_col + 1 < max_col && visited[select_row][select_col+1] != 1)
            DFS_display_unhide(model, select_row , select_col + 1, bgrow, bgcol, map, visited);
        if (select_col - 1 >= 0 && select_row - 1 >= 0 && visited[select_row-1][select_col-1] != 1)
            DFS_display_unhide(model, select_row - 1, select_col - 1, bgrow, bgcol, map, visited);
        if (select_col - 1 >= 0 && select_row + 1 < max_row && visited[select_row+1][select_col-1] != 1)
            DFS_display_unhide(model, select_row + 1, select_col - 1, bgrow, bgcol, map, visited);
        if (select_col + 1 < max_col && select_row - 1 >= 0 && visited[select_row-1][select_col+1] != 1)
            DFS_display_unhide(model, select_row - 1, select_col + 1, bgrow, bgcol, map, visited);
        if (select_col + 1 < max_col && select_row + 1 < max_row && visited[select_row+1][select_col+1] != 1)
            DFS_display_unhide(model, select_row + 1, select_col + 1, bgrow, bgcol, map, visited);
    }
    return;
}
void display_unhide(const int model, const int select_row, const int select_col,const int map[][30], int visited[][30])
{
    cout << endl;
    int x, y;
    cct_getxy(x, y);
    cout << "当前数组：" << endl;
    display_hide_array(model,map,visited);
    int x1, y1;
    cct_getxy(x1, y1);
    DFS_display_unhide(model,select_row, select_col, x+3, y+3, map, visited);
    cct_gotoxy(x1, y1);
    cct_setcolor(COLOR_BLACK, COLOR_WHITE);
}

void play_game_base(const int model,const int order,int map[][30], int visited[][30], LARGE_INTEGER tick, LARGE_INTEGER begin)
{
    int select_row=0, select_col=0;
    int row_max = judge_row(model), col_max = judge_col(model);
    int bgrow, bgcol;
    cct_getxy(bgrow, bgcol);
    while (1)
    {
        if (order == 3) {
            cout << "输入非雷位置的行列坐标（先行后列，严格区分大小写，例：G1 / Af，按Q / q退出）：";
            if(!row_col_select(select_row, select_col, model))
                break;
            visited[select_row][select_col] = 1;
        }
        else if (order == 4) {
            int result = complex_select_base(select_row, select_col, model, visited);
            if (result== 0) {
                break;
            }
            else if (result == 1)
                visited[select_row][select_col] = 1;
            else if (result == 2) {
                cout << endl;
                display_time(tick, begin);
                cout << endl;
                continue;
            }
            else if (result == 3) {
                if (visited[select_row][select_col] == 0) 
                    visited[select_row][select_col] = 2;
                cout << "当前数组：" << endl;
                display_hide_array(model, map, visited);
                continue;
            }
            else {
                if (visited[select_row][select_col] == 2)
                visited[select_row][select_col] = 0;
                cout << "当前数组：" << endl;
                display_hide_array(model, map, visited);
                continue;
            }
        }
        display_unhide(model, select_row, select_col, map,visited);
        int judge = judge_game(map, visited, model, select_row, select_col);
        if (judge == 1) {
            cout << "恭喜胜利，游戏结束" << endl;
            break;
        }
        if (judge == 0) {
            cout << "你输了，游戏结束" << endl;
            break;
        }
    }
}

