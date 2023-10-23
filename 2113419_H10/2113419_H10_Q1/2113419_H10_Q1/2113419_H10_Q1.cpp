#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int a[4][4] = {
	2, 10, 9, 7,
	15, 4, 14, 8,
	13, 14, 16, 11,
	4, 15, 13, 9
};
int Time = 99999;//时间下界
int mintime = 99999;//最小下界
int minline = 0;//最小下界节点的行
int ex[4];
vector<int> minTime;
int min_ex(int l, int r){
	int min = 99999;
	for (int i = 0; i < 4; i++){
		bool Isex = false;
		for (int m = 0; m < 4; m++){
			if (ex[m] == i){
				Isex = true;
				break;
			}
		}
		//除去当前行和之前被扩展的节点所在行r这列的最小值
		if (i != l && !Isex && a[i][r] < min){
			min = a[i][r];
		}
	}
	return min;
}
void branch(int k, int& m){
	while (true){
		if (k < 4){
			bool Isex = false;
			mintime = 99999;
			for (int i = 0; i < 4; i++){
				for (int m = 0; m < 4; m++){
					if (ex[m] == i){
						Isex = true;
						break;
					}
				}
				if (!Isex){
					Time = a[i][k];
					for (int j = k + 1; j < 4; j++){
						Time += min_ex(i, j);
					}
					if (Time < mintime){
						mintime = Time;
						minline = i;		
						ex[k] = i;			
					}
					minTime.push_back(Time);
				}
				Isex = false;
				ex[k] = -1;//恢复当前节点为未扩展
			}
			ex[k] = minline;
			k++;
		}
		else{//叶节点
			for (int i = 0; i < 4; i++){
				m += a[ex[i]][i];
			}
			break;
		}
	}
}
int main(){
	memset(ex, -1, 4 * sizeof(int));
	int mintime = 0;
	branch(0, mintime);
	for (int i = 0; i < 4; i++){
		cout << "课程" << i + 1 << "由教师" << ex[i] + 1 << "教授" << " 备课时间为：" << a[ex[i]][i] << " " << endl;
	}
	cout << "总备课时间为" << mintime << endl;
	return 0;
}