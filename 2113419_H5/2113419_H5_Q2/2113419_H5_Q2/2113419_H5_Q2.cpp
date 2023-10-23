#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 100000;
int n, m, s;
vector<pair<int, int>> G[MAXN];  // 图的邻接表
int dist[MAXN];                  
void di(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push(make_pair(0, s));    // 源点入队
    dist[s] = 0;                 
    while (!q.empty()) {
        int s = q.top().second;
        int f = q.top().first;
        q.pop();
        if (f > dist[s]) continue;   // 已经处理过
        for (auto& i : G[s]) {       
            int j = i.first;
            int k = i.second;
            if (dist[j] > dist[s] + k) {   
                dist[j] = dist[s] + k;
                q.push(make_pair(dist[j], j));
            }
        }
    }
}
int main() {
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back(make_pair(v, w));
    }
    fill(dist, dist + n + 1, MAXN);  // 初始化
    di(s);
    for (int i = 1; i <= n; i++) {
            cout << dist[i] << " ";  
    }
    return 0;
}