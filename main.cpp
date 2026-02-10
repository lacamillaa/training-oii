// NOTE: it is recommended to use this even if you don't understand the following code.

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
    // uncomment the two following lines if you want to read/write from files
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    map<int, int> m;
    // coppie <dolcezza, conteggio> (frutto = P)

    int N, P;
    cin >> N >> P;

    vector<int> S(N);
    for (int i = 0; i < N; ++i) {
        cin >> S[i];
    }

    vector<int> F(N);
    for (int i = 0; i < N; ++i) {
        cin >> F[i];
        if (F[i] == P) {
            m[S[i]]++;
        }
    }

    int Q;
    cin >> Q;

    vector<string> answer(Q);

    vector<int> l(Q), r(Q), k(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> l[i] >> r[i] >> k[i];
        auto ptrS = m.lower_bound(l[i]);
        auto ptrF = m.upper_bound(r[i]);
        long long count = 0;
        while (ptrS != ptrF) {
            count += ptrS->second;
            ++ptrS;
        }
        if (count >= k[i]) answer[i] = "YES";
        else answer[i] = "NO";
    }


    for (int i = 0; i < Q; ++i)
        cout << answer[i] << endl;

    return 0;
}
