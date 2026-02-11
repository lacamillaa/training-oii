// NOTE: it is recommended to use this even if you don't understand the following code.

#include <algorithm>
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

    vector<int> S1;

    vector<int> F(N);
    for (int i = 0; i < N; ++i) {
        cin >> F[i];
        if (F[i] == P) {
            S1.push_back(S[i]);
        }
    }

    sort(S1.begin(), S1.end());

    int Q;
    cin >> Q;

    vector<string> answer(Q);

    vector<int> l(Q), r(Q), k(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> l[i] >> r[i] >> k[i];
        auto ptrS = lower_bound(S1.begin(), S1.end(), l[i]);
        auto ptrF = upper_bound(S1.begin(), S1.end(), r[i]);
        int diff = ptrF - ptrS;
        if (diff >= k[i]) answer[i] = "YES";
        else answer[i] = "NO";
    }



    for (int i = 0; i < Q; ++i)
        cout << answer[i] << endl;

    return 0;
}
