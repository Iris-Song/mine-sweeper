/* 计算机 1954263 宋子铭 */
#include"mine_sweeper.h"
int judge_row(const int model)
{
    if (model == SIMPLE)
        return 9;
    if (model == MIDDLE)
        return 16;
    if (model == HARD) {
        return 16;
    }
    return 0;
}
int judge_col(const int model)
{
    if (model == SIMPLE)
        return 9;
    if (model == MIDDLE)
        return 16;
    if (model == HARD) {
        return 30;
    }
    return 0;
}
int judge_boom_num(const int model) 
{
    if (model == SIMPLE)
        return 10;
    if (model == MIDDLE)
        return 40;
    if (model == HARD) {
        return 99;
    }
    return 0;
}

void model_select(int& model)//选择难度
{
    cct_cls();
    cout << "请选择难度：" << endl;
    cout << "1.初级(9 * 9 - 10颗雷)" << endl;
    cout << "2.中级(16 * 16 - 40颗雷)" << endl;
    cout << "3.高级(16 * 30 - 99颗雷)" << endl;
    cout << "请输入[1..3]：" << endl;
    while (1) {
        int x, y;
        cct_getxy(x, y);
        model = _getche();
        if (model >= '1' && model <= '3') {
            model -= '0';
            break;
        }
        else {
            rewind(stdin);
            cct_showch(x, y, ' ', COLOR_BLACK, COLOR_WHITE, 40);
            cct_gotoxy(x, y);
        }
    }
}
bool row_col_select(int& select_row, int& select_col, const int model)
{
    //得到的是下标
    int row_max = judge_row(model), col_max = judge_col(model);
    
    while (1) {
        int x, y;
        cct_getxy(x, y);
        select_row = _getche();
        if (select_row == 'q' || select_row == 'Q') {
            return false;
        }
        else if (select_row >= 'A' && select_row < 'A' + row_max) {
            select_row -= 'A';
            break;
        }
        else {
            rewind(stdin);
            cct_showch(x, y, ' ', COLOR_BLACK, COLOR_WHITE, 40);
            cct_gotoxy(x, y);
        }
    }
    while (1) {
        int x, y;
        cct_getxy(x, y);
        select_col = _getche();
        if (select_row == 'q' || select_row == 'Q') {
            return false;
        }
        else if (select_col >= '1' && select_col <= '9') {
            select_col -= '1';
            break;
        }
        else if (select_col >= 'a' && select_col < 'a' + col_max) {
            select_col -= 'a' ;
            select_col += 9;
            break;
        }
        else {
            rewind(stdin);
            cct_showch(x, y, ' ', COLOR_BLACK, COLOR_WHITE, 40);
            cct_gotoxy(x, y);
        }
    }
    cout << endl;
    return true;
}
int complex_select_base(int& select_row, int& select_col, const int model, int visited[][30])
{
    //退出返回0
    //正常输入位置返回1
    //看时间返回2
    //标记返回3
    //取消标记返回4
    int row_max = judge_row(model), col_max = judge_col(model);
    int bgrow, bgcol;
    cct_getxy(bgrow, bgcol);
    cout << "特殊输入说明：& - 游戏已运行时间(单字符即可，不需要加坐标)" << endl;
    cout << "              ! - 标记该坐标为雷(例：!E3)" << endl;
    cout << "              # - 取消标记      (例：#E3)" << endl;
    cout << "输入非雷位置的行列坐标（先行后列，严格区分大小写，例：G1 / Af，按Q / q退出）：";
    while (1) {
        int x, y;
        cct_getxy(x, y);
        select_row = _getche();
        if (select_row == 'q' || select_row == 'Q') {
            return 0;
        }
        else if (select_row == '&') 
            return 2;
        else if (select_row == '!') {
            while (!row_col_select(select_row, select_col, model));
            return 3;
        }
        else if (select_row == '#') {
            while (!row_col_select(select_row, select_col, model));
            return 4;
        }
        else if (select_row >= 'A' && select_row < 'A' + row_max) {
            select_row -= 'A';
            break;
        }
        else {
            rewind(stdin);
            cct_showch(x, y, ' ', COLOR_BLACK, COLOR_WHITE, 40);
            cct_gotoxy(x, y);
        }
    }
    while (1) {
        int x, y;
        cct_getxy(x, y);
        select_col = _getche();
        if (select_row == 'q' || select_row == 'Q') {
            return false;
        }
        else if (select_col >= '1' && select_col <= '9') {
            select_col -= '1';
            break;
        }
        else if (select_col >= 'a' && select_col < 'a' + col_max) {
            select_col -= 'a';
            select_col += 9;
            break;
        }
        else {
            rewind(stdin);
            cct_showch(x, y, ' ', COLOR_BLACK, COLOR_WHITE, 40);
            cct_gotoxy(x, y);
        }
    }
    cout << endl;
    return 1;
}

void count_boom(int map[][30], const int row, const int col)
{
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (map[i][j] == BOOM)
                continue;
            else {
                int num = 0;
                if (i - 1 >= 0 && map[i - 1][j] == BOOM)
                    num++;
                if (i + 1 < row && map[i + 1][j] == BOOM)
                    num++;
                if (j - 1 >= 0 && map[i][j - 1] == BOOM)
                    num++;
                if (map[i][j + 1] == BOOM && j + 1 < col)
                    num++;
                if (j - 1 >= 0 && i - 1 >= 0 && map[i - 1][j - 1] == BOOM)
                    num++;
                if (j - 1 >= 0 && i + 1 < row && map[i + 1][j - 1] == BOOM)
                    num++;
                if (j + 1 < col && i - 1 >= 0 && map[i - 1][j + 1] == BOOM)
                    num++;
                if (j + 1 < col && i + 1 < row && map[i + 1][j + 1] == BOOM)
                    num++;
                map[i][j] = num;
            }
        }
    }
}
void set_map(int map[][30], const int model, const int order,const int select_row,const int select_col) //num为雷的数量
{
    int row = judge_row(model);
    int col = judge_col(model);
    int num = judge_boom_num(model);
    srand((unsigned int)time(0));
    for (int i = 0; i < num;)
    {
        int x = (rand() % row);
        int y = (rand() % col);
        if (map[x][y] != BOOM)
        {
            if (order != 1 && x >= select_row-1 && x <= select_row + 1 && y >= select_col-1 && y <= select_col + 1)
                continue;
            map[x][y] = BOOM;
            i++;
        }
    }
    count_boom(map, row, col);
}
bool init_model(int& model, int map[][30], int visited[][30],const int order, int& select_row, int& select_col)
{
    model_select(model);
    cct_cls();
    if (order == 2||order==3|| order == 4) {
        cout << "内部数组：" << endl;
        display_hide_array(model,map,visited);
        cout << "输入非雷位置的行列坐标（先行后列，严格区分大小写，例：G1 / Af，按Q / q退出）：";
        if (!row_col_select(select_row, select_col, model))
            return false;
    }
    else if(order>6) {
        draw_hide_graph(model, map, visited);
        if (order == 8 || order == 9) {
            int x, y;
            cct_getxy(x, y);
            cct_gotoxy(0, 0);
            cout << "按ESC退出";
            cct_gotoxy(x, y);
        }
        if (!graph_row_col_select(select_row, select_col, model))
            return false;
    }
    set_map(map, model, order, select_row, select_col);
    return true;
}

char int_trans_char(const int n) 
{
    //将整型转换为字符
    if (n != BOOM)
        return char(n + '0');
    else
        return '*';
}

int judge_game(const int map[][30], const int visited[][30], const int model,const int select_row,const int select_col)
{
    //如果获胜返回1
    //如果失败返回0
    //游戏继续返回2
    if (map[select_row][select_col] == BOOM) 
    {
        return 0;
    }
    int row_max = judge_row(model);
    int col_max = judge_col(model);
    int num = judge_boom_num(model);
    for (int i = 0; i < row_max; i++) {
        for (int j = 0; j < col_max; j++) {
            if (map[i][j] != BOOM && visited[i][j] == 0)
                return 2;
        }
    }
    return 1;
}

void display_time(LARGE_INTEGER tick, LARGE_INTEGER begin)
{
    LARGE_INTEGER end;
    QueryPerformanceCounter(&end);
    cout << setiosflags(ios::fixed) << setprecision(4) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "秒" ;
}