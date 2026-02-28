#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;

vector<int> nodi;
vector<set<int>> adj;
int last_returned;

void inizia(int N) {
    last_returned = N;
    nodi.resize(N);
    adj.resize(N);
    for (int i = 0; i < N; i++) {
        nodi[i] = i;
    }
}

int collega(int a, int b) {
    int A = nodi[a];
    int B = nodi[b];
    if (A == B) {
        return last_returned;
    }
    adj[a].insert(b);
    adj[b].insert(a);
    queue<int> neighbors;
    set<int> visited;
    neighbors.push(b);
    while (!neighbors.empty()) {
        int u = neighbors.front();
        neighbors.pop();
        nodi[u] = a;
        visited.insert(u);
        for (int v : adj[u]) {
            if (!visited.count(v)) {
                neighbors.push(v);
            }
        }
    }
    last_returned--;
    return last_returned;
}

/*
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N, Q;
    cin >> N >> Q;

    inizia(N);

    for (int i = 0; i < Q; i++) {
        int X, Y;
        cin >> X >> Y;
        cout << collega(X, Y) << endl;
    }

    return 0;
}*/