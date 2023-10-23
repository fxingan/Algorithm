#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
vector<vector<int>> adj; // 图的邻接表
vector<bool> visited; // 是否已经访问过
vector<int> bfs(int start){// BFS
    vector<int> connectedComponent; // 连通分量
    queue<int> q;
    visited[start] = true;
    q.push(start);
    while (!q.empty()){
        int u = q.front();
        q.pop();
        connectedComponent.push_back(u);
        for (int v : adj[u]){
            if (!visited[v]){
                visited[v] = true;
                q.push(v);
            }
        }
    }
    return connectedComponent;
}
vector<int> dfs(int start){// DFS
    vector<int> c; // 连通分量
    stack<int> s;
    visited[start] = true;
    s.push(start);
    while (!s.empty()){
        int u = s.top();
        s.pop();
        c.push_back(u);
        for (int v : adj[u]){
            if (!visited[v]){
                visited[v] = true;
                s.push(v);
            }
        }
    }
    return c;
}
int main(){
    int n, m, start;
    cin >> n >> m >> start;
    adj.resize(n + 1); 
    visited.resize(n + 1, false);
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> bfsCC = bfs(start); // BFS
    for (int u : bfsCC){
        cout << u << " ";
    }
    cout << endl;
    visited.assign(n + 1, false); // 重置
    vector<int> dfsCC = dfs(start); // DFS
    for (int u : dfsCC){
        cout << u << " ";
    }
    return 0;
}
