#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int>& num, int left, int mid, int right) {// 将两个有序子序列合并为一个有序序列
    vector<int> temp(num.size());
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right) {
        if (num[i] <= num[j]) {
            temp[k++] = num[i++];
        }
        else {
            temp[k++] = num[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = num[i++];
    }
    while (j <= right) {
        temp[k++] = num[j++];
    }
    for (int p = left; p <= right; p++) {
        num[p] = temp[p];
    }
}
void sort(vector<int>& num, int left, int right) {// 将待排序数组分成左右两个子序列进行递归排序
    if (left >= right) {
        return;
    }
    int mid = left + (right - left) / 2;
    sort(num, left, mid);
    sort(num, mid + 1, right);
    merge(num, left, mid, right);
}
int main() {
    int n;
    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << num[i] << " ";
    }
    return 0;
}