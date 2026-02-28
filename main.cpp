#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;

vector<set<int>> adj;
set<int> da_raggiungere;

void inizia(int N) {
    adj.resize(N);
    for (int i = 0; i < N; i++) {
        da_raggiungere.insert(i);
    }
}

int collega(int X, int Y) {
    adj[X].insert(Y);
    adj[Y].insert(X);
    int zone = 0;
    set<int> visitati = {};
    set dr2(da_raggiungere);
    queue<int> neighbours;
    while (!dr2.empty()) {
        auto start = dr2.begin();
        neighbours.push(*start);
        dr2.erase(start);
        while (!neighbours.empty()) {
            int u = neighbours.front();
            neighbours.pop();
            visitati.insert(u);
            for (int v : adj[u]) {
                if (!visitati.count(v)) {
                    neighbours.push(v);
                    dr2.erase(v);
                }
            }
        }
        zone++;
    }
    return zone;
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
} */