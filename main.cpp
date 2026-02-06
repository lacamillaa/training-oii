#include <iostream>
#include <stdint.h>
#include <vector>

using namespace std;

int solve(int t) {
    int N, M, K, A, B;
    cin >> N >> M >> K >> A >> B;

    vector campo(N, vector<int>(M));
    // campo[x][y] => 0 <= x < N, 0 <= y < M
    vector<int> c_righe(N);

    for (int i = 0; i < K; i++) {
        int X, Y;
        cin >> X >> Y;
        campo[X][Y]++;
        c_righe[X]++;
    }

    if (A == N && B == M) {
        return K;
    }

    int somma_m = 0;
    for (int r = 0; r < A; r++) {
        somma_m += c_righe[r];
    }
    int somma_p = somma_m;
    pair<int, int> range = {0, A}; // [0...A)
    for (int r = 1; r <= N - A; r++) {
        somma_p -= c_righe[r - 1];
        somma_p += c_righe[r + A - 1];
        if (somma_p < somma_m) {
            somma_m = somma_p;
            range = {r, r + A};
        }
    }

    vector<int> c_colonne(M);
    for (int r = range.first; r < range.second; r++) {
        for (int c = 0; c < M; c++) {
            c_colonne[c] += campo[r][c];
        }
    }
    int c_somma = 0;
    for (int c = 0; c < B; c++) {
        c_somma += c_colonne[c];
    }
    int c_somma_p = c_somma;
    int c_somma_min = c_somma_p;
    for (int c = 1; c <= M - B; c++) {
        c_somma_p -= c_colonne[c - 1];
        c_somma_p += c_colonne[c + B - 1];
        if (c_somma_p < c_somma_min) {
            c_somma_min = c_somma_p;
        }
    }

    return c_somma_min;
}

int main() {
    // se preferisci leggere e scrivere da file
    // ti basta decommentare le seguenti due righe:

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": " << solve(t) << "\n";
    }
    return 0;
}
