#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"


void menu()//菜单界面
{
	printf("************************\n");
	printf("*****    1.play     ****\n");
	printf("*****    0.exit     ****\n");
	printf("************************\n");
}

void game()
{
	char PlayerMine[ROW][COL] = { 0 };
	char DesignerMine[ROW][COL] = { 0 };
	int ret = 0;
	InitMine(PlayerMine, DesignerMine, ROW, COL);   //初始化玩家棋盘和设计者棋盘

	SetMine(DesignerMine);   //设置雷

	PrintDesigner(DesignerMine, ROW, COL);  //打印设置好雷后的设计者棋盘（这个是方便编程者检验程序是否正确的用的）
	//printf("\n");

	PrintPlayer(PlayerMine, ROW, COL);   //打印玩家棋盘

	FirstMine(PlayerMine, DesignerMine);  //保证第一步不被炸死
	PrintPlayer(PlayerMine, ROW, COL);  //打印玩家棋盘

	while (1)
	{
		ret = IsSweeped(PlayerMine, DesignerMine, ROW, COL);   //1表示踩到雷，0表示没踩到雷
		if (ret == 1)
		{
			printf("踩到雷了，游戏结束\n\n");
			PrintDesigner(DesignerMine, ROW, COL);   //打印设计者棋盘，可以看到雷的分布位置
			break;
		}
		if (LeftMineCount(PlayerMine, ROW, COL) == COUNT)   //走到这儿表示未踩到雷。此时如果玩家棋盘中未展开区域即'*'的个数等于雷的个数，表示排雷成功
		{
			printf("玩家赢！\n");
			PrintDesigner(DesignerMine, ROW, COL);     //打印设计者棋盘，可以看到雷的分布位置
			break;
		}
		PrintPlayer(PlayerMine, ROW, COL);   //既没有踩到雷，也没有排除所有雷，所以打印玩家棋盘继续排雷
	}
}


int main()
{
	int input = 0;
	do
	{ 
		menu();
	    printf("请输入对应的数字:>");
	    scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入不正确 ，请重新选择！\n");
			break;
		}
	} while (input);
	
	return 0;
}
