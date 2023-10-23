#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 100000;
int n, m;
int dis[MAXN]; // 源点到每个点的最短距离
bool is[MAXN]; // 是否已经在集合中
vector<pair<int, int>> G[MAXN]; // 邻接表
int prim(int s) {
    for (int i = 1; i <= n; i++) {
        dis[i] = 1e10;
        is[i] = false;
    }
    dis[s] = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int k = -1;
        for (int j = 1; j <= n; j++) {  
            if (!is[j] && (k == -1 || dis[k] > dis[j])) {
                k = j;
            }
        }
        is[k] = true;
        ans = dis[k] + ans;
        for (const auto& g : G[k]) {   // 更新邻接点的距离
            int v = g.first;
            int w = g.second;
            if (!is[v] && dis[v] > w) {
                dis[v] = w;
            }
        }
    }
    return ans;
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back(make_pair(v, w));
        G[v].push_back(make_pair(u, w));
    }
    int ans = prim(1);
    cout << ans ;
    return 0;
}