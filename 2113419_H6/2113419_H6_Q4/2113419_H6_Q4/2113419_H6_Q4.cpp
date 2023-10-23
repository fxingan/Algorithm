#include <iostream>
#include <vector>
using namespace std;
int merge(vector<int>& a, int left, int mid, int right) {
    vector<int> b(right - left + 1); 
    int i = left, j = mid + 1, k = 0;
    int count = 0; //计算逆序对的数量
    while (i <= mid && j <= right) {
        if (a[i] <= a[j]) {
            b[k++] = a[i++];
        }
        else {
            b[k++] = a[j++];
            count += mid - i + 1; 
        }
    }
    while (i <= mid) {
        b[k++] = a[i++];
    }
    while (j <= right) {
        b[k++] = a[j++];
    }
    for (k = 0, i = left; i <= right; ++i, ++k) {
        a[i] = b[k];
    }
    return count;
}
int count(vector<int>& a, int left, int right) {
    if (left >= right) {
        return 0;
    }
    int mid = (left + right) / 2;
    int left_count = count(a, left, mid);
    int right_count = count(a, mid + 1, right);
    int merge_count = merge(a, left, mid, right);
    int c = left_count + right_count + merge_count;
    return c;
}
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int c = count(a, 0, n - 1);
    cout << c;
    return 0;
}