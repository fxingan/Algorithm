#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Processor {
    int t1, t2, k1, k2;
    int index;
    int state;  // 0-待机状态，1-A类状态，2-B类状态
    int timestamp;  // 完成任务的时间戳

    bool operator<(const Processor& other) const {
        // 根据计算能力排序
        return k1 * t1 + k2 * t2 > other.k1 * other.t1 + other.k2 * other.t2;
    }
};

int main() {
    // 读入输入数据
    int n, m, p;
    cin >> n >> m >> p;
    vector<Processor> processors(p);
    for (int i = 0; i < p; i++) {
        cin >> processors[i].t1 >> processors[i].t2 >> processors[i].k1 >> processors[i].k2;
        processors[i].index = i;
        processors[i].state = 0;
        processors[i].timestamp = 0;
    }

    // 对处理器按照计算能力排序
    sort(processors.begin(), processors.end());

    // 分配任务
    int cur_a = 0, cur_b = 0;  // 当前未分配的 A 类任务和 B 类任务的数量
    while (cur_a < n || cur_b < m) {
        for (int i = 0; i < p; i++) {
            if (cur_a < n && processors[i].state != 1) {
                // 分配 A 类任务
                int start_time = max(processors[i].timestamp, processors[i].state == 0 ? 0 : processors[i].t2);
                processors[i].timestamp = start_time + processors[i].t1;
                processors[i].state = 1;
                cur_a++;
            }
            else if (cur_b < m && processors[i].state != 2) {
                // 分配 B 类任务
                int start_time = max(processors[i].timestamp, processors[i].state == 0 ? 0 : processors[i].t1);
                processors[i].timestamp = start_time + processors[i].t2;
                processors[i].state = 2;
                cur_b++;
            }
        }
    }

    // 输出结果
    int last_timestamp = 0;
    for (int i = 0; i < p; i++) {
        last_timestamp = max(last_timestamp, processors[i].timestamp);
    }
    cout << last_timestamp << endl;

    return 0;
}