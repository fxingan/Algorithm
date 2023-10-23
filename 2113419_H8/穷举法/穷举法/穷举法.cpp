#include <iostream>
#include <string>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;
// 判断一个序列是否为另一个序列的子序列
bool isSubsequence(string sub, string str) {
    int i = 0, j = 0;
    while (i < sub.length() && j < str.length()) {
        if (sub[i] == str[j]) {
            i++;
        }
        j++;
    }
    return i == sub.length();
}

// 获取一个序列的所有子序列
vector<string> getSubsequences(string str) {
    vector<string> subs;
    for (int i = 0; i < (1 << str.length()); i++) {
        string sub = "";
        for (int j = 0; j < str.length(); j++) {
            if (i & (1 << j)) {
                sub += str[j];
            }
        }
        subs.push_back(sub);
    }
    return subs;
}

// 获取两个序列的最长公共子序列长度
int getLongestCommonSubsequenceLength(string str1, string str2) {
    vector<string> subs1 = getSubsequences(str1);
    vector<string> subs2 = getSubsequences(str2);
    int lcsLength = 0;
    for (string sub1 : subs1) {
        if (sub1.length() <= lcsLength) {
            continue;
        }
        for (string sub2 : subs2) {
            if (isSubsequence(sub1, str1) && isSubsequence(sub1, str2) &&
                sub1.length() > lcsLength && isSubsequence(sub1, sub2)) {
                lcsLength = sub1.length();
            }
        }
    }
    return lcsLength;
}

int main() {
    auto start = high_resolution_clock::now(); // 获取开始时间点

    string str1, str2;
    str1 = "zhang56210ni";
    str2 = "fanaonishiw2";
    // 计算序列A和序列B的最长公共子序列长度
    int lcsLength = getLongestCommonSubsequenceLength(str1, str2);


    auto end = high_resolution_clock::now(); // 获取结束时间点

    cout << "程序运行时间为： " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " 微秒" << endl;

    return 0;
}