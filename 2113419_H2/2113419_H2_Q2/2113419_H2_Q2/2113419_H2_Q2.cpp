#include <iostream>
using namespace std;
void merge(int a[], int b[], int n, int m) {
    int c[200] = { 0 };
    int l = 0, r = 0, q = 0;
    while (l < n && r < m) {
        if (a[l] < b[r]) {
            c[q] = a[l];
            l++;
            q++;
        }
        else {
            c[q] = b[r];
            r++;
            q++;
        }
    }
    for (l; l < n; l++) {
        c[q] = a[l];
        q++;
    }
    for (r; r < m; r++) {
        c[q] = b[r];
        q++;
    }
    for (int i = 0; i < q; i++) {
        cout << c[i] << " ";
    }
}
int main(){
    int a[100] = { 0 }, b[100] = { 0 }, n, m;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    merge(a, b, n, m);
    return 0;
}