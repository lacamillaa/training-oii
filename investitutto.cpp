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

        int ris = 0;

        for (int i = 0; i < N; i++) {
            int val_previsto = V[i] + (N - i) * G[i];
            if (val_previsto > ris) ris = val_previsto;
        }


        cout << "Case #" << test << ": ";
        cout << ris << endl;
    }

    return 0;
}
