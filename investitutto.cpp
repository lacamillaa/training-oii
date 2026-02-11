#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int N;
        cin >> N;

        vector<int> V(N);
        for (int i = 0; i < N; ++i) {
            cin >> V[i];
        }

        vector<int> G(N);
        for (int i = 0; i < N; ++i) {
            cin >> G[i];
        }

        int val_previsto = 0;

        for (int i = 0; i < N; i++) {
            int v_p = V[i] + G[i] * (N - i);
            bool att = false;
            for (int j = 0; j < i; j++) {
                if (V[i] <= V[j] + G[j] * (i - j)) {
                    att = true;
                    break;
                }
            }
            if (att && v_p >= val_previsto) {
                val_previsto = v_p;
            }
        }

        cout << "Case #" << test << ": " << val_previsto << endl;
    }

    return 0;
}