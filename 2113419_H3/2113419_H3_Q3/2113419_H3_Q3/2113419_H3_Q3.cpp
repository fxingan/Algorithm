#include <iostream>
#include <vector>
#define MAXN (int)1000
using namespace std;
vector<int> adj[MAXN]; // 邻接表
int color[MAXN]; // 顶点的颜色
bool dfs(int u, int c) {
    color[u] = c; 
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (color[v] == -1) { // 如果v还没有被染色
            if (!dfs(v, 1 - c)) return false; 
        }
        else if (color[v] == c) { // 如果v已经被染成了与u相同的颜色
            return false;
        }
    }
    return true;
}
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < n; i++) {
        color[i] = -1;
    }
    bool is = true;
    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            is = dfs(i, 0);
            if (!is) break; // 如果发现不是二分图，则立即退出
        }
    }
    if (is) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}
