#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct job {
    int start;
    int finish;
};
bool compare(job job1, job job2) {
    return job1.finish < job2.finish;
}
vector<job> sch(vector<job> a) {
    sort(a.begin(), a.end(), compare);
    vector<job> s;
    s.push_back(a[0]);
    for (int i = 1; i < a.size(); i++) {
        if (a[i].start >= s.back().finish) {
            s.push_back(a[i]);
        }
    }
    return s;
}
void print(vector<job> s) {
    for (int i = 0; i < s.size(); i++) {
        cout << "job " << i + 1 << ": start time = " << s[i].start << ", finish time = " << s[i].finish << endl;
    }
}

int main() {
    vector<job> j;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        j.push_back({ a,b });
    }
    vector<job> s = sch(j);
    cout << "Size:" << sch(j).size() << endl;
    print(s);
    return 0;
}