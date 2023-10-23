#include <iostream>
#include <vector>
using namespace std;
int DP(int V, int n, vector<int>& v, vector<int>& w) {
    vector<vector<int>> dp(n + 1, vector<int>(V + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= V; j++) {
            if (j < v[i - 1]) {
                dp[i][j] = dp[i - 1][j];
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i - 1]] + w[i - 1]);
            }
        }
    }
    return dp[n][V];
}

int main() {
    int V, n;
    cin >> V >> n;
    vector<int> v(n), w(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i] >> w[i];
   }
   int W = DP(V, n, v, w);
    cout << W;
    return 0;
}
