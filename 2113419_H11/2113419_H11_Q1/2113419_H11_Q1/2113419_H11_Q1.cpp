#include<iostream>
#include<string>

using namespace std;

void Rabin_Karp_search(const string& T, const string& P, int d, int q){
    int m = P.length();
    int n = T.length();
    int i, j;
    int p = 0; 
    int t = 0; 
    int h = 1;
    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;

    for (i = 0; i < m; i++){
        p = (d * p + P[i]) % q;
        t = (d * t + T[i]) % q;
    }

    for (i = 0; i <= n - m; i++){
        if (p == t){
            for (j = 0; j < m; j++)
                if (T[i + j] != P[j])
                    break;

            if (j == m) {
                cout <<  i + 1 << endl;
                break;
            }
        }
         
        if (i < n - m){
            t = (d * (t - T[i] * h) + T[i + m]) % q;

            if (t < 0)
                t = (t + q);
        }
    }
}

int main(){
    string T;
    string P;
    cin >> T >> P;
    int q = 101; 
    int d = 18;
    Rabin_Karp_search(T, P, d, q);
    return 0;
}