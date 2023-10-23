#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define  N 4
int c[][N] = {
	2, 10, 9, 7,
	15, 4, 14, 8,
	13, 14, 16, 11,
	4, 15, 13, 9
};
int Time = 65535;//搜索深度为k时的花费下界，深度为k有N-k个节点的下界，取最小值给minCostInk
int mintime = 65535;//搜索深度为k时的最小下界
int minline = 0;//记录最小下界节点所在的行
int ex[N];//存放被扩展节点的顺序
vector<int> minTime;//存放搜索深度为k时的花费下界，即costBoundInK

int min_exceptiInRow(int i, int row)
{
	int min = 65535;
	for (int line = 0; line < N; line++)
	{
		bool currExpanded = false;
		for (int m = 0; m < N; m++)
		{
			if (ex[m] == line)//line行的某一节点已经之前被扩展过，故这一行的节点不能再扩展
			{
				currExpanded = true;
				break;
			}
		}
		//功能：除去当前行和之前被扩展的节点所在行之后，通过循环找出row这列的最小值
		if (line != i && !currExpanded && c[line][row] < min)//与i不在同一行，同时节点未被扩展，且是这一列中的最小值
		{
			min = c[line][row];
		}
	}
	return min;
}

/************************************************************************
**功能：求出最小的花费
**参数：k为作业编号
		mincost为最终返回的最小花费
************************************************************************/
void branchBound(int k, int& mincost)
{
	while (true)
	{
		if (k < N)//未到叶子节点
		{
			bool currExpanded = false;
			mintime = 65535;
			for (int i = 0; i < N; i++)
			{
				for (int m = 0; m < N; m++)
				{
					if (ex[m] == i)//查看当前行的某一节点是否已经被扩展过，若扩展过，则当前行的所有节点都不能再扩展
					{
						currExpanded = true;
						break;
					}
				}
				if (!currExpanded)//当前行未被扩展
				{
					Time = c[i][k];//costBoundInK表示在某个搜索深度k下，把作业k分配给工人i时的时间下界
					for (int j = k + 1; j < N; j++)
					{
						Time += min_exceptiInRow(i, j);//深度k下的花费下界，即在未扩展节点所在列均取花费的最小值，并累加
					}
					if (Time < mintime)
					{
						mintime = Time;
						minline = i;		//记录要扩展节点的行号
						ex[k] = i;		//expanded[k]记录花费矩阵中节点被扩展的顺序，k为列，代表作业编号，依次为0,1...N
						//对应的i为行，代表工人编号，即分配方案为工人i完成作业k
					}
					minTime.push_back(Time);//不同深度k下计算的花费下界存入vectors容器；深度为k时，需要计算N-k次下界，取最小值为扩展节点
				}
				currExpanded = false;
				ex[k] = -1;//同级节点扩展，恢复当前节点为未扩展
			}
			ex[k] = minline;//选取当前搜索深度k下，花费最少的为扩展节点c[minCostLine][k]
			k++;
		}
		else{
			for (int i = 0; i < N; i++){
				mincost += c[ex[i]][i];
			}
			break;
		}
	}
}

int main()
{
	memset(ex, -1, N * sizeof(int));//给数组置-1

	int mintime = 0;
	branchBound(0, mintime);

	for (int i = 0; i < N; i++)
	{
		cout << "作业:" << i << " --> 由工人" << ex[i] << "完成. " << " 花费为：" << c[ex[i]][i] << " " << endl;
	}

	cout << "总花费为：" << mintime << endl;
	return 0;
}