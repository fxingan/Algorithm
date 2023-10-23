#include <iostream>
using namespace std;
int min(int n, int m) {
    if (n < m) {
        return n;
    }
    else {
        return m;
    }
}
int main(){
    int n;
    cin >> n;
    if (n >= 0) {
        cout << n;
    }
    else {
        n = -n;
        cout << -min(n / 10, n / 100 * 10 + n % 10);
    }
    return 0;
}