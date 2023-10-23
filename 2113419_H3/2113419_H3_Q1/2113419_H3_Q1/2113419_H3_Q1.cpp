#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// 定义一个图类
class Graph {
private:
    int n;  // 节点个数
    vector<vector<int>> adj;  // 邻接表
public:
    Graph(int n) {
        this->n = n;
        adj.resize(n + 1);
    }
    // 添加边
    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // BFS算法
    vector<int> bfs(int start) {
        vector<int> layer(n + 1, -1);  // 初始化
        queue<int> q;
        q.push(start);
        layer[start] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = 0; i < adj[u].size(); i++) { // 遍历邻居
                int v = adj[u][i];
                // 如果节点未被访问过，则将其入队，并更新其层数
                if (layer[v] == -1) {
                    q.push(v);
                    layer[v] = layer[u] + 1;
                }
            }
        }
        return layer;
    }
};
int main() {
    int n, m, start;
    cin >> n >> m >> start;
    Graph g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.add_edge(u, v);
    }
    vector<int> layer = g.bfs(start);
    for (int i = 0; i < n; i++) {
        cout << layer[i] << " ";
    }
    return 0;
}
