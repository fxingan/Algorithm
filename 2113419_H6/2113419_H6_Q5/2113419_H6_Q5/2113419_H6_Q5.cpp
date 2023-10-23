#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const double MAX = 1e10;
struct Point {
    double x, y;
};
bool compare_x(Point a, Point b) {
    return a.x < b.x;
}
bool compare_y(Point a, Point b) {
    return a.y < b.y;
}
double dis(Point a, Point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return dx * dx + dy * dy;
}
double getdis(Point p[], int n) {
    double min = MAX;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double d = dis(p[i], p[j]);
            if (d < min) {
                min = d;
            }
        }
    }
    return min;
}
double closest(Point p[], int n) {
    if (n <= 1) {
        return MAX;
    }
    int mid = n / 2;
    double mid_x = p[mid].x;
    double l = closest(p, mid);
    double r = closest(p + mid, n - mid);
    double d = min(l, r);
    Point* s = new Point[n];
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (abs(p[i].x - mid_x) < d) {
            s[j] = p[i];
            j++;
        }
    }
    sort(s, s + j, compare_y);
    for (int i = 0; i < j; i++) {
        for (int k = i + 1; k < j && (s[k].y - s[i].y) < d; k++) {
            double dist = dis(s[i], s[k]);
            d = min(d, dist);
        }
    }
    return d;
}

int main() {
    int n;
    cin >> n;
    Point* p = new Point[n];
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
    }
    sort(p, p + n, compare_x);
    double min = closest(p, n);    
    cout << min;
    return 0;
}