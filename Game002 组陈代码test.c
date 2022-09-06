#include"game.h"

void menu()
{
	printf("\n");
	printf("*****************************************\n");
	printf("**************    1.play    *************\n");
	printf("**************    0.exit    *************\n");
	printf("*****************************************\n");
	printf("\n");
}


void game()
{
	char mine[ROWS][COLS] = {0};//存放布置好的雷的信息 初始化全为0
	char show[ROWS][COLS] = {0};//存放排查出的雷的信息 初始化全为*
	//初始化棋盘
	InitBoard(mine,ROWS,COLS,'0');
	InitBoard(show,ROWS,COLS,'*');

	//打印棋盘
	//DisPlayBoard(mine,ROW,COL);//此处是调试棋盘
	DisPlayBoard(show,ROW,COL);

	//布置雷
	SetMine(mine,ROW,COL);
	//DisPlayBoard(mine,ROW,COL);//此处是调试棋盘

	//排查雷
	FindMine(mine,show,ROW,COL);//排查出雷放在show数组中
}



int main()
{
	int input=0;
	srand((unsigned int)time(NULL));//用rand函数之前要调用sran函数 此处必不可少 此处强制转换了类型为int型 为了不报警告
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d",&input);
		switch(input)
		{
		case 1:
			game();
			//printf("\n");
			//printf("扫雷\n");
			break;
		case 0:
			printf("\n");
			printf("退出游戏\n");
			break;
		default:
			printf("\n");
			printf("选择错误，重新选择\n");
			break;
		}
	}
	while(input);
	return 0;
}


//此游戏依然可以优化
//1.如果不是雷 周围都没有雷 展开一片（利用递归）
//2.标记雷
//3.程序结束出现问题 无法准确结束游戏（判断胜利条件有问题）
