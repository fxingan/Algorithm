#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int> optimal_caching(int k, vector<int>& n, vector<int>& s) {
    vector<int> ca; 
    vector<int> schedule; 
    unordered_map<int, int> lu; // 记录下次出现
    for (int i = 0; i < s.size(); i++) {
        if (find(ca.begin(), ca.end(), s[i]) != ca.end()) { // 已经存在
            lu[s[i]] = i; 
            continue;
        }
        if (ca.size() < k) { // 没满
            ca.push_back(s[i]);
            lu[s[i]] = i;
        }
        else {
            int t = -1;
            int eblock = 0;
            for (int j = 0; j < ca.size(); j++) {
                int block = ca[j];
                if (lu.find(block) == lu.end()) {                 
                    eblock = block;
                    lu[block] = i;
                    break;
                }
                if (i - lu[block] > t) {
                    t = i - lu[block];
                    eblock = block;
                }
            }
            ca.erase(find(ca.begin(), ca.end(), eblock));
            ca.push_back(s[i]);
            lu[s[i]] = i;
            schedule.push_back(eblock);
        }
    }
    return schedule;
}
int main() {
    int k, n, s;
    cin >> k >> n >> s;
    vector<int> list(s);
    vector<int> ini(n);
    for (int i = 0; i < n; i++) {
        cin >> ini[i];
    }
    for (int i = 0; i < s; i++) {
        cin >> list[i];
    }
    vector<int> schedule = optimal_caching(k, ini, list);
    for (int i = 1; i < schedule.size(); i++) {
        cout << schedule[i] << " ";
    }
    return 0;
}