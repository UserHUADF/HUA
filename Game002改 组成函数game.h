#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define ROW 12   //行
#define COL 12   //列

#define COUNT 10  //雷的个数


void InitMine(char PlayerMine[ROW][COL], char DesignerMine[ROW][COL], int row, int col);//初始化玩家棋盘和设计者棋盘
void PrintPlayer(char PlayerMine[ROW][COL], int row, int col);//打印玩家棋盘
void PrintDesigner(char DesignerMine[ROW][COL], int row, int col);//打印雷的分布棋盘
void SetMine(char DesignerMine[ROW][COL]);//设置雷
int CountMine(char DesignerMine[ROW][COL], int x, int y);//统计雷的数目
void OpenMine(char PlayerMine[ROW][COL], char DesignerMine[ROW][COL], int x, int y);//周围非雷区域展开函数
void FirstMine(char PlayerMine[ROW][COL], char DesignerMine[ROW][COL]);//避免第一步被炸死
int LeftMineCount(char PlayerMine[ROW][COL], int row, int col);//玩家棋盘中'*'的剩余个数
int IsSweeped(char PlayerMine[ROW][COL], char DesignerMine[ROW][COL], int row, int col);//是否踩到雷，踩到返回1，没有踩到返回0
