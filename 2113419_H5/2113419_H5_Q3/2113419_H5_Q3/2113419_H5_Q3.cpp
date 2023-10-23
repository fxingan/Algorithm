#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 100000;
int n, m;
int father[MAXN];  
struct edge {
    int u, v, w;
    bool operator<(const edge& e) const {   
        return w < e.w;
    }
};
vector<edge> edges;    // 存储边的数组
int find(int x) {   // 查找
    if (father[x] != x) father[x] = find(father[x]);
    return father[x];
}
void hebing(int x, int y) {   // 合并
    father[find(x)] = find(y);
}
int cz() {
    int ans = 0;
    sort(edges.begin(), edges.end());   // 按权值排序
    for (int i = 1; i <= n; ++i) {
        father[i] = i;   // 初始化
    }
    for (const auto& e : edges) {
        if (find(e.u) != find(e.v)) {   // 如果不在同一连通块
            hebing(e.u, e.v);   
            ans += e.w;   
        }
    }
    return ans;
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({ u, v, w });
    }
    int ans = cz();
    cout << ans << endl;
    return 0;
}