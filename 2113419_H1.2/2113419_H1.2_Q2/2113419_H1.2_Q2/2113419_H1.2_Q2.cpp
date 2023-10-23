#include <iostream>
using namespace std;
int main()
{
    float n, m, a, b;
    cin >> n >> m >> a >> b;
    float p = m / b;
    if (m / b <= a) {
        int t;
        t = n / m;
        cout << t * b + a * (n - m * t);
    }
    else {
        cout << n * a;
    }
    return 0;
}