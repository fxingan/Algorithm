#include <iostream>
#include <vector>
using namespace std;
void back(vector<int>& num, vector<bool>& used, vector<int>& ma, vector<vector<int>>& res) {
    if (ma.size() == num.size()) {
        res.push_back(ma);
        return;
    }
    for (int i = 0; i < num.size(); i++) {
        if (!used[i]) {
            used[i] = true;  // 标记
            ma.push_back(num[i]);  // 把数字加入当前排列
            back(num, used, ma, res);  // 继续递归
            ma.pop_back();  // 恢复状态
            used[i] = false;  // 恢复
        }
    }
}
vector<vector<int>> make(int n) {
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        nums[i] = i + 1;
    }
    vector<vector<int>> res;
    vector<int> ma;
    vector<bool> used(n, false);//初始化
    back(nums, used, ma, res);
    return res;
}
int main() {
    int n, m;
    cout << "请输入n: ";
    cin >> n;
    m = 0;
    vector<vector<int>> res = make(n);
    for (vector<int>& ma : res) {
        for (int num : ma) {
            cout << num << " ";
        }
        m++;
        cout << endl;
    }
    cout << "共有" << m << "个序列";
    return 0;
}