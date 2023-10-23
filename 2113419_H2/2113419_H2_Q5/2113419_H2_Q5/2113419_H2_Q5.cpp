#include <iostream>
#define target (int)2
using namespace std;
int bs(int a[], int x, int n) {//二分算法
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (a[mid] < x) {
            l = mid + 1;
        }
        else {
            r = mid;
        }
    }
    return l;
}
void threeSum1(int arr[], int n) {//时间复杂度为n^3
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (arr[i] + arr[j] + arr[k] == target) {
                    cout << i << " " << j << " " << k << "    ";
                }
            }
        }
    }
}
void threeSum2(int arr[], int n) {//时间复杂度为nlog(n)
    int l = 0;
    int r = n - 1;
    while (l < r) {
        int i = target - arr[l] - arr[r];
        int d = bs(arr, i, n);
        if (arr[d] == i) {
            cout << l << " " << r << " " << d << "    ";
        }
        l++;
        r--;
    }
}
void threeSum3(int arr[], int n) {//时间复杂度为n^2
    for (int i = 0; i < n - 2; i++) {
        int l = i + 1;
        int r = n - 1;
        while (l < r) {
            int sum = arr[i] + arr[l] + arr[r];
            if (sum == target) {
                cout << i << " " << l << " " << r << "    ";
                l++;
                r--;
            }
            else if (sum < target) {
                l++;
            }
            else {
                r--;
            }
        }
    }
}
int main() {
    int arr[] = { -4, -1, 0, 0, 1, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    threeSum1(arr, n);
    cout << endl;
    threeSum2(arr, n);
    cout << endl;
    threeSum3(arr, n);
    return 0;
}
