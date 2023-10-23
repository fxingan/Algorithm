#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct lecture {
    int start;
    int finish;
};
bool compare(lecture lecture1, lecture lecture2) {
    return lecture1.start < lecture2.start;
}
int count(vector<lecture> a) {
    sort(a.begin(), a.end(), compare);
    priority_queue<int, vector<int>, greater<int>> finish;
    for (int i = 0; i < a.size(); i++) {
        if (!finish.empty() && finish.top() <= a[i].start) {
            finish.pop();
        }
        finish.push(a[i].finish);
    }
    return finish.size();
}
int main() {
    vector<lecture> j;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        j.push_back({ a,b });
    }
    int num = count(j);
    cout << "Size: " << num << endl;
    return 0;
}