#include<stdio.h>
#include"game.h"//这里是引用了头文件game.h

void menu()
{
	printf("*********************\n");
	printf("*****	1.play	*****\n");
	printf("*****	0.exit	*****\n");
	printf("*********************\n");	
}

void game()//记录玩家每一步 并且给出电脑的决定
{	
	char ret = 0;//接收游戏状态
	char board[ROW][COL];//存储数据-二维数组
	IntBoard(board,ROW,COL);//初始化棋盘
	DisplayBoard(board,ROW,COL);//打印棋盘

	while(1)
	{
		
		PlayerMove(board,ROW,COL);//玩家下棋
		DisplayBoard(board,ROW,COL);//打印棋盘
		printf("\n");//换行
		ret=IsWin(board,ROW,COL);//判断游戏状态
		if(ret != 'C')
		{
			break;
		}
		
		ComputerMove(board,ROW,COL);//电脑下棋
		DisplayBoard(board,ROW,COL);//打印棋盘
		printf("\n");//换行
		ret=IsWin(board,ROW,COL);//判断游戏状态
		if(ret != 'C')
		{
			break;
		}

	}
	if(ret == '*')
	{
		printf("玩家赢了\n");
	}	
	else if(ret == '#')
	{
		printf("电脑赢了\n");
	}
	else
	{
		printf("平局\n");
	}
	DisplayBoard(board,ROW,COL);//打印棋盘
		printf("\n");
		printf("\n");
		printf("\n");
}



int main()
{
	int input=0;
	srand((unsigned int)time(NULL));//使用srand函数
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d",&input);
		switch(input)//不为零进入循环
		{
		case 1:
			game();
			printf("三子棋游戏\n");
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	}
	while(input);//不为零继续上部分循环
	return 0;
}
