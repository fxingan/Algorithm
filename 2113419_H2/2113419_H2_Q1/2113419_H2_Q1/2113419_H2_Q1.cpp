#include <iostream>
using namespace std;
int bs(int a[], int x, int n) {//二分算法
	int l = 0, r = n - 1;
	while (l<=r) {
		int mid ;
		if ((l + r) % 2 == 0) {
			mid = (l + r) / 2;
		}
		else {
			mid = (l + r) / 2 + 1;
		}
		if (a[mid] < x) {
			l = mid;
		}
		if (a[mid] > x) {
			r = mid;
		}
		if (a[mid] == x) {
			return mid;
			break;
		}
	}
}
int main(){
	int a[100] = { 0 }, n, x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> x;
	cout << bs(a, x, n);
	return 0;
}