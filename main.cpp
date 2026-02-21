#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int lds(int e, vector<int>& P, vector<int>& memo) {
    if (memo[e] != -1) return memo[e];
    int partial_result = 0;
    for (int pe = e - 1; pe >= 0; pe--) {
        if (P[pe] > P[e]) partial_result = max(partial_result, lds(pe, P, memo));
    }
    memo[e] = partial_result + 1;
    return memo[e];
}

int solve(vector<int>& P) {
    vector memo(P.size(), -1);
    memo[0] = 1;
    if (P[0] > P[1]) memo[1] = 2;
    else memo[1] = 1;
    for (int e = P.size() - 1; e > 0; e--) {
        lds(e, P, memo);
    }
    int m = memo[0];
    for (int i = 1; i < memo.size(); i++) {
        m = max(m, memo[i]);
    }
    return m;
}

int main() {
    FILE *fr = freopen("input.txt", "r", stdin);
    FILE *fw = freopen("output.txt", "w", stdout);

    int N;
    cin >> N;

    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    cout << solve(P) << endl;

    return 0;
}