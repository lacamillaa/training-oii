#include <algorithm>
#include <iostream>
#include <set>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

void solve(int N, vector<char>& S) {
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        A[i] = i + 1;
    }
    vector<int> map(N);
    int i = 0;
    while (i < N && S[i] == '<') i++;
    // partiamo dalla posizione del primo segno >
    int mp = 0;
    for (int pos = i; pos < N - 1; pos++) {
        // se il segno è diverso cambiamo slot
        if (pos > i && S[pos] != S[pos - 1]) {
            mp++;
            map[mp] = 1;
        }
        else {
            map[mp]++;
        }
    }
    // costruzione della mappa terminata
    int mapPos = 0;
    int pos = i;
    while (pos < N - 1) {
        reverse(A.begin() + pos, A.begin() + pos + map[mapPos] + 1);
        pos += map[mapPos] + map[mapPos + 1];
        mapPos += 2;
    }
    for (auto a : A) {
        cout << a << ' ';
    }
    cout << endl;
}


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N;
    cin >> N;

    vector<char> S(N - 1);
    for (int i = 0; i < N - 1; i++) {
        cin >> S[i];
    }

    solve(N, S);

    return 0;
}