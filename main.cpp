// NOTA: si raccomanda di usare questo template anche se non lo si capisce completamente.

#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

long long risolvi(vector<int>& P, vector<int>& C, set<pair<int,int>>& L, int s, int e) {
    if (s == e) return P[s] * C[s];
    long long sum = 0;
    // prendiamo l'elemento di costo minore
    auto minC = *L.begin();
    erase_if(L, [minC](auto p) {
        return p.second >= minC.second;
    });
    for (int i = minC.second; i <= e; ++i) {
        sum += P[i] * minC.first;
        P[i] = 0;
    }
    if (!L.empty()) {
        sum += risolvi(P, C, L, 0, minC.second);
    }
    return sum;
}

int main() {
    FILE *fr = freopen("input.txt", "r", stdin);
    FILE *fw = freopen("output.txt", "w", stdout);

    int T;
    cin >> T;

    for (int test = 1; test <= T; ++test) {
        int N;
        cin >> N;

        vector<int> P(N);
        for (int i = 0; i < N; ++i)
            cin >> P[i];

        set<pair<int,int>> L;

        vector<int> C(N);
        for (int i = 0; i < N; ++i) {
            cin >> C[i];
            L.insert({C[i], i});
        }

        long long ris = risolvi(P, C, L, 0, N - 1);

        cout << "Case #" << test << ": " << ris << endl;
    }

    return 0;
}
