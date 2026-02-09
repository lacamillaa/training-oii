#include <cstdio>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <set>
#include <utility>
#include <vector>

using namespace std;

void solve(int t) {
    int N, K;
    cin >> N >> K;

    vector<int> C(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }
    sort(C.begin(), C.end());

    if (K == 1) {
        cout << "Case #" << t << ": " << (*C.rbegin() - *C.begin()) << endl;
        return;
    }

    set<pair<int, int>> dist;
    for (int i = 0; i < N - 1; i++) {
        int d = C[i + 1] - C[i];
        dist.insert({d, i});
    }

    vector<int> B;
    for (int i = 0; i < K - 1; i++) {
        auto last = *dist.rbegin();
        B.push_back(last.second);
        dist.erase(last);
    }
    B.push_back(N - 1);
    sort(B.begin(), B.end());

    long long risposta = 0;
    risposta += C[B[0]] - C[0];
    for (int i = 1; i < B.size(); i++) {
        risposta += C[B[i]] - C[B[i - 1] + 1];
    }

    cout << "Case #" << t << ": " << risposta << "\n";
}

int main() {
    // se preferisci leggere e scrivere da file
    // ti basta decommentare le seguenti due righe:

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        solve(t);
    }

    return 0;
}
