#include "cmd_console_tools.h"
#include <iostream>
#include<iomanip>
#include<Windows.h>
#include <conio.h>
using namespace std;

#define SIMPLE 1
#define MIDDLE 2
#define HARD 3
#define BOOM 9
void output_system(int& order);
void back(int map[][30]);

int judge_row(const int model);
int judge_col(const int model);
int judge_boom_num(const int model);
int judge_game(const int map[][30], const int visited[][30], const int model, const int select_row, const int type_col);

char int_trans_char(const int n);

bool row_col_select(int& select_row, int& select_col, const int model);
int complex_select_base(int& select_row, int& select_col, const int model, int visited[][30]);
bool init_model(int& model, int map[][30], int visited[][30], const int order, int& select_row, int& select_col);

void display_array(int model, const int map[][30]);
void display_hide_array(const int model, const int map[][30], const int visited[][30]);

void display_unhide(const int model, const int select_row, const int select_col, const int map[][30], int visited[][30]);
void play_game_base(const int model, const int order, int map[][30], int visited[][30], LARGE_INTEGER tick, LARGE_INTEGER begin);

void display_time(LARGE_INTEGER tick, LARGE_INTEGER begin);

void draw_graph(const int model, const int map[][30]);
void draw_hide_graph(const int model, const int map[][30], const int visited[][30]);
void draw_unhide_graph(const int model, const int select_row, const int select_col, const int map[][30], int visited[][30]);

void mouse_move(int model);

int graph_row_col_select(int& select_row, int& select_col, const int model);

void play_game_graph(const int model, const int order, int map[][30], int visited[][30], LARGE_INTEGER tick, LARGE_INTEGER begin);