
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


#define EASY_COUNT 10
#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

//初始化棋盘
void InitBoard(char board[ROWS][COLS],int rows,int cols,char set);

//打印棋盘
void DisPlayBoard(char board[ROWS][COLS],int row,int col);

//布置雷
void SetMine(char mine[ROWS][COLS],int row,int col);

//排查雷
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col);

////统计雷
//int get_mine_count(char mine[ROWS][COLS],int x,int y);//此处不需要设置头文件 因为get_mine_count只是为了FindMine函数使用

