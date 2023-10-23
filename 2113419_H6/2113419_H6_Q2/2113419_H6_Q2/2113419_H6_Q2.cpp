#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <numeric>
using namespace std;
struct node {
    int f;
    char c;
    node* left, * right;
    node(int f, char c) : f(f), c(c), left(nullptr), right(nullptr) {}
};
struct cp {
    bool operator()(node* left, node* right) {
        return left->f > right->f;
    }
};
node* build(priority_queue<node*, vector<node*>, cp>& pq) {
    while (pq.size() > 1) {
        node* left = pq.top(); pq.pop();
        node* right = pq.top(); pq.pop();
        int sum = left->f + right->f;
        node* parent = new node(sum, '#');
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }
    return pq.top();
}
void getcode(node* root, string code, vector<string>& h) {
    if (root == nullptr) return;
    if (root->left == nullptr && root->right == nullptr) {
        h[root->c] = code;
    }
    getcode(root->left, code + '0', h);
    getcode(root->right, code + '1', h);
}
double avg(vector<string>& h, vector<int>& f) {
    double total = 0.0;
    for (int i = 0; i < h.size(); ++i) {
        if (f[i] != 0) {
            total += h[i].length() * f[i];
        }
    }
    return total / accumulate(f.begin(), f.end(), 0);
}
int main() {
    int n;
    cin >> n;
    vector<int> f(n);
    for (int i = 0; i < n; ++i) {
        cin >> f[i];
    }
    priority_queue<node*, vector<node*>, cp> pq;
    for (int i = 0; i < n; ++i) {
        if (f[i] > 0) {
            pq.push(new node(f[i], i));
        }
    }
    node* root = build(pq);
    vector<string> h(n);
    getcode(root, "", h);
    double a = avg(h, f);
    cout << a << endl;
    return 0;
}