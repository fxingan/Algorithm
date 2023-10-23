#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct job {
    int processing, deadline;
};
bool cmp(job a, job b) {
    return a.deadline < b.deadline;
}
int main() {
    int n;
    cin >> n;
    vector<job> jobs(n);
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].processing >> jobs[i].deadline;
    }
    sort(jobs.begin(), jobs.end(), cmp);//按截止时间排序
    int c = 0, l = 0;
    for (int i = 0; i < n; i++) {
        c += jobs[i].processing;
        l = max(l, c - jobs[i].deadline);
    }
    cout << l ;
    return 0;
}