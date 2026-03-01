#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;

vector<int> parents;
int last_returned;

void inizia(int N) {
    last_returned = N;
    parents.resize(N);
    for (int i = 0; i < N; i++) {
        parents[i] = i;
    }
}

int find_parent(int x) {
    if (x == parents[x]) return x;
    parents[x] = find_parent(parents[x]);
    return parents[x];
}

int collega(int a, int b) {
    int A = find_parent(a);
    int B = find_parent(b);
    if (A == B) return last_returned;
    parents[B] = A;
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