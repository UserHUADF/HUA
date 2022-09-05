//此为程序代码实现模块 编写实现不同功能的函数
#include"game.h"

void InitBoard(char board[ROWS][COLS],int rows,int cols,char set)
{
	int i=0;
	int j=0;
	for(i=0;i<rows;i++)
	{
		for(j=0;j<cols;j++)
		{
			board[i][j]=set;
		}
	}
}


void DisPlayBoard(char board[ROWS][COLS],int row,int col)
{
	int i=0;
	int j=0;
	printf("-----------------扫雷游戏------------------\n");
	//打印列号：
	for(i=0;i<=col;i++)
	{
		printf("%d ",i);
	}
	printf("\n");
	//打印棋盘：
	for(i=1;i<=row;i++)//整个棋盘范围是0-10 我们只需要打印1-9就行
	{
		//打印行号：
		printf("%d ",i);
		//下面为棋盘
		for(j=1;j<=col;j++)
		{

			printf("%c ",board[i][j]);

		}
		printf("\n");
	}
	printf("-----------------扫雷游戏------------------\n");

}


void SetMine(char mine[ROWS][COLS],int row,int col)
{
	//布置10个雷
	int count=EASY_COUNT;
	while(count)
	{
		//生成随机的下标
		int x=rand()%row+1;//%9生成的是1-8 而此处的%row+1就是 %10 也就是1-9
		int y=rand()%col+1;
		if(mine[x][y]=='0')//此处判断是否有雷
		{
			mine[x][y]='1';
			count--;
		}
	}

}


//static使函数只在此文件中使用 不会与其他文件的同名文件冲突
//1.修饰局部变量
//2.修饰全局变量
//3.修饰函数
static int get_mine_count(char mine[ROWS][COLS],int x,int y)
{
	return mine[x-1][y]+  
		   mine[x-1][y-1]+
		   mine[x][y-1]+
		   mine[x+1][y-1]+
		   mine[x+1][y]+
		   mine[x+1][y+1]+
		   mine[x][y+1]+
		   mine[x-1][y+1] -  8 * '0';//也可以用for函数for(i=-1;i<=1;i++){for(j=-1;j<=1;j++){mine[x+i][y+i]}} 这里是九种相加 单得到的依然是雷的个数（本身为0）

}

//此处为优化 如果不是雷 周围没有雷 则显示3*3的信息进一步加速扫雷
void OUT_MINE(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col,int x,int y)
{
				//不是雷的话，统计下x,y坐标周围有几个雷
				int count=get_mine_count(mine,x,y);
				int count1=get_mine_count(mine,x-1,y-1);
				int count2=get_mine_count(mine,x-1,y);
				int count3=get_mine_count(mine,x-1,y+1);
				int count4=get_mine_count(mine,x,y-1);
				int count5=get_mine_count(mine,x,y+1);
				int count6=get_mine_count(mine,x+1,y-1);
				int count7=get_mine_count(mine,x+1,y);
				int count8=get_mine_count(mine,x+1,y+1);

				if(count==0)
				{
					show[x][y] = count+'0';
					show[x-1][y-1] = count1+'0';
					show[x-1][y] = count2+'0';
					show[x-1][y+1] = count3+'0';
					show[x][y-1] = count4+'0';
					show[x][y+1] = count5+'0';
					show[x+1][y-1] = count6+'0';
					show[x+1][y] = count7+'0';
					show[x+1][y+1] = count8+'0';
				}
				

				
				
}

void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col)
{
	//1.输入排查雷的坐标
	//2.检查是不是雷的坐标
	//如果是雷 = 很遗憾 炸死了 - 游戏结束
	//如果不是雷 = 统计坐标周围有几个雷 - 存储排查雷的信息到show数组 - 游戏继续
	int x = 0;
	int y = 0;
	int win=0;
	while(win<row*col-EASY_COUNT)
	{
		printf("请输入要排查的坐标 :>");
		scanf("%d %d",&x,&y);//横纵坐标有范围x-(1,9) y-(1,9)
		//判断坐标的合法性
		if(x>=1 && x<=row && y>=1 && y<=col)
		{
			if(mine[x][y]=='1')
			{
				printf("\n");
				printf("很遗憾，你被炸死了\n");
				printf("棋盘如下:(1为雷 0为非雷)\n");
				DisPlayBoard(mine,ROW,COL);
				break;
			}
			else//此处要判断是否已经全部排查完毕
			{
				int count=get_mine_count(mine,x,y);
				if(count==0)
				{
					//优化
					OUT_MINE(mine,show,row,col,x,y);
					win=win+9;
				}
				else
				{
					show[x][y] = count+'0';//0的ascll值为48只要用count+‘0’=对应的数字字符
					win++;
				}


				//显示排查出的信息
				DisPlayBoard(show,ROW,COL);
			}
		}
		else
		{
			printf("坐标不合法，请重新输入\n");
		}
	}

	if(win == row * col - EASY_COUNT)
	{
		printf("\n");
		printf("恭喜你排雷成功!\n");
		printf("棋盘如下:(1为雷 0为非雷)\n");
		DisPlayBoard(mine,ROW,COL);
	}
}
