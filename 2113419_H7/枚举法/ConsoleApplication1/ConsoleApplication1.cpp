#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int weight;
    int value;
    int index;
};

bool cmp(Item i1, Item i2) {
    return i1.weight < i2.weight;
}

int main() {
    int capacity, n;
    cin >> capacity >> n;

    vector<Item> items(n);
    for (int i = 0; i < n; i++) {
        cin >> items[i].weight >> items[i].value;
        items[i].index = i;
    }

    sort(items.begin(), items.end(), cmp);

    vector<int> best_choice(n, 0); // 用于存储当前最优解对应的选择方案
    int best_value = 0; // 用于存储当前最优解的价值
    for (int i = 0; i < (1 << n); i++) {
        int current_weight = 0, current_value = 0;
        vector<int> current_choice(n, 0); // 用于存储当前枚举到的选择方案
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                current_weight += items[j].weight;
                current_value += items[j].value;
                current_choice[items[j].index] = 1;
            }
        }

        if (current_weight <= capacity && current_value > best_value) {
            best_value = current_value;
            best_choice = current_choice;
        }
    }

    cout << "物品列表：" << endl;
    for (int i = 0; i < n; i++) {
        if (best_choice[i]) {
            cout << "物品 " << i << "：" << items[i].weight << " " << items[i].value << endl;
        }
    }

    cout << "最大价值：" << best_value << endl;

    return 0;
}
