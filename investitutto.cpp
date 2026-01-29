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

        int scelta = 0;
        int val_attuale = V[0];
        int obiettivo = val_attuale + N * G[0];

        for (int i = 1; i < N; i++) {
            val_attuale += G[scelta];
            // val_previsto = valore previsto con l'investimento del giorno i
            int val_previsto = V[i] + (N - i) * G[i];
            if (val_attuale >= V[i] && val_previsto > obiettivo) {
                // effettua la tua scelta
                val_attuale = V[i];
                scelta = i;
                obiettivo = val_previsto;
            }
        }


        cout << "Case #" << test << ": ";
        cout << obiettivo << endl;
    }

    return 0;
}
