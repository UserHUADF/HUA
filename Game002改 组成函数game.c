#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

//初始化玩家棋盘和设计者棋盘
void InitMine(char PlayerMine[ROW][COL], char DesignerMine[ROW][COL], int row, int col)
{
	//memset函数按字节对内存块进行初始化
	//不能利用它对int型数组初始化为0和-1之外的其他值（除非该值高字节与低字节相同）
	//memset(void*s,int ch,size_t n)函数中ch的实际范围应该在0~~255函数只能取ch的后八位赋值
	//注意：如果想利用函数将一个char a[20]清零 一定是memset(a,0,20*sizeof(char)); 而不是memset(a,20*sizeofchar),0)
	memset(PlayerMine, '*', row*col);  
	memset(DesignerMine, '0', row*col);  
}
//打印棋盘
void PrintPlayer(char PlayerMine[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	printf("0  ");
	for (i = 1; i < row - 1; i++)  //打印1到10（列标）
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i < row - 2; i++)   //打印9*10的棋盘
	{
		printf("%d  ", i);  //打印行标
		for (j = 1; j < col - 1; j++)
		{
			printf("%c ", PlayerMine[i][j]);
		}
		printf("\n");
	}
	printf("10 ");   

	for (i = 1; i < col - 1; i++)
	{
		printf("%c ", PlayerMine[10][i]);
	}
	printf("\n\n");
}

//打印设计者棋盘
void PrintDesigner(char DesignerMine[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	printf("0  ");
	for (i = 1; i < row - 1; i++)  //打印1到10（列标）
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i < row - 2; i++)   //打印9*10的棋盘
	{
		printf("%d  ", i);   //打印行标
		for (j = 1; j < col - 1; j++)
		{
			printf("%c ", DesignerMine[i][j]);
		}
		printf("\n");
	}
	printf("10 ");  
	for (i = 1; i < col - 1; i++)
	{
		printf("%c ", DesignerMine[10][i]);
	}
	printf("\n");
}


//随机设置雷的位置
void SetMine(char DesignerMine[ROW][COL])
{
	int x = 0;
	int y = 0;
	int count = COUNT;
	while (count)
	{
		x = rand() % 10 + 1;  //产生1到10之间的随机整数作为横坐标
		y = rand() % 10 + 1;  //产生1到10之间的随机整数作为纵坐标
		if (DesignerMine[x][y] == '0')   //如果此位置为0则将该位置变为1，表示此位置有雷，否则不再重复标记
		{
			DesignerMine[x][y] = '1';
			count--;
		}
	}
}


//计算某一位置周围8个区域雷的个数
int CountMine(char DesignerMine[ROW][COL], int x, int y)
{
	int count = 0;
	if (DesignerMine[x - 1][y - 1] == '1')  //1表示该位置有雷
	{
		count++;
	}
	if (DesignerMine[x - 1][y] == '1')
	{
		count++;
	}
	if (DesignerMine[x - 1][y + 1] == '1')
	{
		count++;
	}
	if (DesignerMine[x][y - 1] == '1')
	{
		count++;
	}
	if (DesignerMine[x][y + 1] == '1')
	{
		count++;
	}
	if (DesignerMine[x + 1][y - 1] == '1')
	{
		count++;
	}
	if (DesignerMine[x + 1][y] == '1')
	{
		count++;
	}
	if (DesignerMine[x + 1][y + 1] == '1')
	{
		count++;
	}
	return count;
}


//周围非雷区域展开函数
void OpenMine(char PlayerMine[ROW][COL], char DesignerMine[ROW][COL], int x, int y)
{
	if (DesignerMine[x - 1][y - 1] == '0')  //如果该位置没有雷，则计算出其周围8个区域雷的个数并标记在玩家棋盘对应位置
	{
		PlayerMine[x - 1][y - 1] = CountMine(DesignerMine, x - 1, y - 1) + '0';  //CountMine()函数返回的是数字，而PlayerMine数组存的是字符，所以将数字加上字符零可得数字字符
	}
	if (DesignerMine[x - 1][y] == '0')
	{
		PlayerMine[x - 1][y] = CountMine(DesignerMine, x - 1, y) + '0';  
	}
	if (DesignerMine[x - 1][y + 1] == '0')
	{
		PlayerMine[x - 1][y + 1] = CountMine(DesignerMine, x - 1, y + 1) + '0'; 
	}
	if (DesignerMine[x][y - 1] == '0')
	{
		PlayerMine[x][y - 1] = CountMine(DesignerMine, x, y - 1) + '0';  
	}
	if (DesignerMine[x][y + 1] == '0')
	{
		PlayerMine[x][y + 1] = CountMine(DesignerMine, x, y + 1) + '0';  
	}
	if (DesignerMine[x + 1][y - 1] == '0')
	{
		PlayerMine[x + 1][y - 1] = CountMine(DesignerMine, x + 1, y - 1) + '0';  
	}
	if (DesignerMine[x + 1][y] == '0')
	{
		PlayerMine[x + 1][y] = CountMine(DesignerMine, x + 1, y) + '0';  
	}
	if (DesignerMine[x + 1][y + 1] == '0')
	{
		PlayerMine[x + 1][y + 1] = CountMine(DesignerMine, x + 1, y + 1) + '0';  
	}
}



//保证第一次不被炸死
void FirstMine(char PlayerMine[ROW][COL], char DesignerMine[ROW][COL])
{
	int x = 0, y = 0;
	while (1)
	{
		printf("请输入坐标：");
		scanf("%d %d", &x, &y);
		if ((x >= 1 && x <= 10) && (y >= 1 && y <= 10))   //保证输入坐标合法
		{
			if (DesignerMine[x][y] == '1')  //此位置如果有雷则将该位置改为0，保证第一次不被炸死（第一次踩到雷了）
			{
				DesignerMine[x][y] = '0';
				PlayerMine[x][y] = CountMine(DesignerMine, x, y) + '0';  //计算出其周围8个区域雷的个数并标记在玩家棋盘对应位置
				OpenMine(PlayerMine, DesignerMine, x, y);  //显示该位置周围非雷区域的8个区域雷的个数
				while (1)  //寻找一个非雷位置并将其改为有雷的位置
				{
					int a = rand() % 10 + 1;
					int b = rand() % 10 + 1;
					if (DesignerMine[a][b] == '0')
					{
						DesignerMine[a][b] = '1';
						break;
					}
				}
				break;
			}
			else  //第一次没有踩到雷
			{
				PlayerMine[x][y] = CountMine(DesignerMine, x, y) + '0';  //计算出其周围8个区域雷的个数并标记在玩家棋盘对应位置
				OpenMine(PlayerMine, DesignerMine, x, y);  //显示该位置周围非雷区域的8个区域雷的个数
				break;
			}
		}
		else
		{
			printf("坐标输入不合法！\n");
		}
	}
}
//玩家棋盘中'*'的剩余个数
int LeftMineCount(char PlayerMine[ROW][COL], int row, int col)
{
	int count = 0;
	int i = 0;
	for (i = 1; i < row - 1; i++)   //只计算10*10棋盘
	{
		int j = 0;
		for (j = 1; j < col - 1; j++)
		{
			if (PlayerMine[i][j] == '*')
			{
				count++;
			}
		}
	}
	return count;
}
//是否踩到雷，踩到返回1，没有踩到返回0
int IsSweeped(char PlayerMine[ROW][COL], char DesignerMine[ROW][COL], int row, int col)
{
	int x = 0, y = 0;
	printf("请输入坐标：");
	scanf("%d %d", &x, &y);
	if ((x >= 1 && x <= 10) && (y >= 1 && y <= 10))
	{
		if (DesignerMine[x][y] == '0')
		{
			PlayerMine[x][y] = CountMine(DesignerMine, x, y) + '0';   //计算出其周围8个区域雷的个数并标记在玩家棋盘对应位置
			OpenMine(PlayerMine, DesignerMine, x, y);  //显示该位置周围非雷区域的8个区域雷的个数
			return 0;
		}
		else
		{
			return 1;
		}
	}
	else
	{
		printf("坐标输入不合法！\n");
	}
	return 0;
}
