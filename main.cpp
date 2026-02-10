// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // uncomment the two following lines if you want to read/write from files
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int N, P;
    cin >> N >> P;

    vector<int> S(N);
    for (int i = 0; i < N; ++i)
        cin >> S[i];

    vector<int> F(N);
    for (int i = 0; i < N; ++i)
        cin >> F[i];

    int Q;
    cin >> Q;

    vector<int> l(Q), r(Q), k(Q);
    for (int i = 0; i < Q; ++i)
        cin >> l[i] >> r[i] >> k[i];

    vector<string> answer(Q);

    vector<int> valid_desserts;

    for (int q = 0; q < Q; q++) {
        int count = 0;
        for (int d = 0; d < N; d++) {
            if (S[d] >= l[q] && S[d] <= r[q] && F[d] == P) {
                count++;
            }
        }
        if (count >= k[q]) answer[q] = "YES";
        else answer[q] = "NO";
    }


    // INSERT YOUR CODE HERE


    for (int i = 0; i < Q; ++i)
        cout << answer[i] << endl;

    return 0;
}
