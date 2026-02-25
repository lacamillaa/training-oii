#include <algorithm>
#include <iostream>
#include <set>
#include <fstream>
#include <vector>

using namespace std;

vector<int> r(int pos, int N, set<int>& used, vector<char>& S, vector<vector<int>>& memo)
{
    if (pos == N - 1) {
        vector<int> res;
        for (int i = 1; i <= N; i++) {
            if (!used.count(i)) {
                res.push_back(i);
                break;
            }
        }
        return res;
    };

    vector<int> perm;

    for (int c = 1; c <= N; c++) {
        if (!used.count(c)) {
            if (pos == N - 1) {}
            set newUsed(used);
            newUsed.insert(c);
            vector res = r(pos + 1, N, newUsed, S, memo);
            if ((S[pos] == '>' && c > res[0]) || (S[pos] == '<' && c < res[0])) {
                perm.push_back(c);
                for (int i = 0; i < res.size(); i++) {
                    perm.push_back(res[i]);
                }
                break;
            }
        }
    }

    return perm;
}

vector<int> solve(int N, vector<char>& S) {
    vector<vector<int>> memo(N);
    set<int> used;
    return r(0, N, used, S, memo);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N;
    cin >> N;

    vector<char> S(N, 0);
    for (int i = 0; i < N - 1; i++) {
        cin >> S[i];
    }

    vector<int> res = solve(N, S);
    for (auto n : res) {
        cout << n << ' ';
    }

    return 0;
}