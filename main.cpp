#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;

vector<set<int>> zone;
vector<int> nodi;
int last_returned;

void inizia(int N) {
    last_returned = N;
    zone.resize(N);
    nodi.resize(N);
    for (int i = 0; i < N; i++) {
        zone[i] = {i};
        nodi[i] = i;
    }
}

int collega(int a, int b) {
    int A = nodi[a];
    int B = nodi[b];
    if (A == B) {
        return last_returned;
    };
    for (auto n : zone[B]) {
        nodi[n] = A;
        zone[A].insert(n);
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