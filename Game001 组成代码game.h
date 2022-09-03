//头文件的包含 在game.c中需要引用 在此处引用可以省略一个game.c中的引用
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//符号的定义
#define ROW 3
#define COL 3

//函数的声明
void IntBoard(char board[ROW][COL],int row,int col);//初始化棋盘的函数

//打印棋盘的函数
void DisplayBoard(char board[ROW][COL],int row,int col);

//玩家下棋
void PlayerMove(char board[][COL],int row,int col);

//电脑下棋
void ComputerMove(char board[][COL],int row,int col);

//判断游戏状态
 //1.玩家赢了-*
 //2.电脑赢了-#
 //3.平局    -Q
 //4.游戏继续-C
char IsWin(char board[][COL],int row,int col);
