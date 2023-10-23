#include <iostream>
#define T (int)6
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
void search1(int array[ ], int n) {//时间复杂度为n^2
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (array[i] + array[j] == T) {
                cout << i << ' ' << j << ' ';
            }
        }
    }
}
void search2(int array[], int n) {//时间复杂度为nlogn
    for (int i = 0; i < n; i++) {
        int j = T - array[i];
        int d = bs(array, j, n);
        if (array[d] == j) {
            cout << i << ' ' << d << ' ';
        }
    }
}
void search3(int array[], int n) {//时间复杂度为n
    int l = 0, r = n - 1;
    while (l <= r) {
        if (array[l] + array[r] < T) {
            l++;
        }
        if (array[l] + array[r] > T) {
            r--;
        }
        if (array[l] + array[r] == T) {
            cout << l << ' ' << r << ' ';
            l++;
            r--;
        }
    }
}
int main(){
    int n;
    cin >> n;
    int array[100] = { 0 };
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    search1(array, n);
    cout << endl;
    search2(array, n);
    cout << endl;
    search3(array, n);
}