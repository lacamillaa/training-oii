// NOTE: it is recommended to use this even if you don't understand the following code.

#include <cmath>
#include <fstream>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

bool solve(int h, int w, vector<int>& X, vector<int>& S, vector<int>& E) {
    int x = 0;
    int y = floor(h / 2);
    // esegui un dfs sugli stati possibili { x, y, v }
    stack<tuple<int, int, int>> q;
    q.push(make_tuple(x, y, 0));
    while (!q.empty()) {
        // condizioni:
        auto t = q.top();
        q.pop();
        int x1 = get<0>(t);
        int y1 = get<1>(t);
        int v1 = get<2>(t);
        // condizioni:
        // non sia sul muro
        // non sia fuori dai limiti
        if (y1 < 0 || y1 >= h) continue;
        auto p = lower_bound(X.begin(), X.end(), x1);
        if (p != X.end() && *p == x1) {
            int pos = p - X.begin();
            if (y1 < S[pos] || y1 > E[pos]) continue;
        }
        if (x1 == w - 1) return true;
        for (auto delta : { -1, 0, 1 }) {
            q.push(make_tuple(x1 + 1, y1 + v1 + delta, v1 + delta));
        }
    }
    return false;
}

int main() {
    // uncomment the two following lines if you want to read/write from files
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int N, H, W;
        cin >> N >> H >> W;

        vector<int> x_wall(W);
        for (int i = 0; i < W; ++i)
            cin >> x_wall[i];

        vector<int> start_hole(W);
        for (int i = 0; i < W; ++i)
            cin >> start_hole[i];

        vector<int> end_hole(W);
        for (int i = 0; i < W; ++i)
            cin >> end_hole[i];

        string ans = "";


        bool s = solve(H, N, x_wall, start_hole, end_hole);
        if (s) ans = "YES";
        else ans = "NO";


        cout << ans << endl;
    }

    return 0;
}
