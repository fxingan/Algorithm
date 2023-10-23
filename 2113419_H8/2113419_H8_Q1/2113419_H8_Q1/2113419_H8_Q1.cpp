#include <iostream>
#include <cstring>
using namespace std;

int LCS(string A, string B) {
    int m = A.length(), n = B.length();
    int dp[50][50] = { 0 };
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (A[i - 1] == B[j - 1]) {  // 当A和B的当前字符相同时
                dp[i][j] = dp[i - 1][j - 1] + 1;  
            }
            else {  // 当A和B的当前字符不同时
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);  
            }
        }
    }
    return dp[m][n];  
}
int main() {
    string A, B;
    cin >> A >> B;  
    int ans = LCS(A, B); 
    cout << ans << endl;
    return 0;
}