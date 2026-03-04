#include <iostream>
#include <set>
#include <stdint.h>
#include <vector>

using namespace std;

int solve(int t) {
    int N, M, K, A, B;
    cin >> N >> M >> K >> A >> B;

    vector count(N, vector(M, 0));
    vector accumulated(N, vector(M, 0));

    for (int T = 0; T < K; T++) {
        int X, Y;
        cin >> X >> Y;
        count[X][Y]++;
    }

    for (int r = 0; r < N; r++) {
        accumulated[r][0] = count[r][0];
        for (int c = 1; c < M; c++) {
            accumulated[r][c] = accumulated[r][c - 1] + count[r][c];
        }
    }

    for (int r = 1; r < N; r++) {
        for (int c = 0; c < M; c++) {
            accumulated[r][c] += accumulated[r - 1][c];
        }
    }

    int min_tot = accumulated[A - 1][B - 1];

    for (int a = 0; a <= N - A; a++) {
        for (int b = 0; b <= M - B; b++) {
            int cA, cB = 0, cC = 0, cD;
            if (a == 0 || b == 0) {
                cD = 0;
                if (a == 0) {
                    cC = 0;
                }
                else {
                    cC = accumulated[a - 1][b + B - 1];
                }
                if (b == 0) {
                    cB = 0;
                }
                else {
                    cB = accumulated[a + A - 1][b - 1];
                }
            }
            else {
                cD = accumulated[a - 1][b - 1];
                cC = accumulated[a - 1][b + B - 1];
                cB = accumulated[a + A - 1][b - 1];
            }
            cA = accumulated[a + A - 1][b + B - 1];
            int s = cA + cD - cB - cC;
            if (s < min_tot) min_tot = s;
        }
    }

    return min_tot;
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
