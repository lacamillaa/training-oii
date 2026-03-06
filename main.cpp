#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int find_end_node(int start, vector<int>& greater, vector<int>& memo) {
    if (memo[start] != -1) return find_end_node(memo[start], greater, memo);
    if (greater[start] == start) {
        return greater[start];
    }
    int res = find_end_node(greater[start], greater, memo);
    memo[start] = res;
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N;
    cin >> N;

    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }
    vector<int> T(N);
    for (int i = 0; i < N; i++) {
        cin >> T[i];
    }

    vector<vector<int>> children(N + 1);
    for (int i = 0; i < N; i++) {
        int p = P[i];
        children[p].push_back(i + 1);
    }

    vector<int> greater(N + 1);
    vector memo(N + 1, -1);
    stack<int> v;
    v.push(0);
    while (!v.empty()) {
        int n = v.top();
        v.pop();
        int max = 0;
        int maxN = n;
        for (auto c : children[n]) {
            v.push(c);
            if (T[c - 1] > max) {
                max = T[c - 1];
                maxN = c;
            }
        }
        greater[n] = maxN;
    }

    int root = 0;
    int time = 0;
    while (greater[root] != root) {
        int new_parent = greater[root];
        int end_node = find_end_node(new_parent, greater, memo);
        auto it = children[root].begin();
        while (it != children[root].end()) {
            auto child = *it;
            if (child != new_parent) {
                time += T[child - 1];
                P[child - 1] = end_node;
                greater[end_node] = child;
                children[root].erase(it);
                children[end_node].push_back(child);
                end_node = find_end_node(end_node, greater, memo);
            } else ++it;
        }
        root = greater[root];
    }

    cout << time << endl;

    return 0;
}
