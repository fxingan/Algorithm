#include <iostream>
#include <vector>
#include <queue>
#define MAXN (int)1000
using namespace std;
int n, m;
vector<int> adj[MAXN]; // 邻接表
int indeg[MAXN]; // 入度
vector<int> topological() {// 拓扑排序
    vector<int> o;
    queue<int> q;  
    for (int i = 0; i < n; i++) {// 将所有入度为0的顶点加入队列
        if (indeg[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        o.push_back(u);      
        for (int i = 0; i < adj[u].size(); i++) {// 将u的所有邻居的入度减1
            int v = adj[u][i];
            indeg[v]--;
            if (indeg[v] == 0) { // 如果v的入度变成了0，将v加入队列
                q.push(v);
            }
        }
    }
    return o;
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indeg[v]++;
    }
    vector<int> o = topological();
    for (int i = 0; i < o.size(); i++) {
        cout << o[i] << " ";
    }
    return 0;
}