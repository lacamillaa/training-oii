// NOTE: it is recommended to use this even if you don't understand the following code.

#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solve(int x, int y, int s, int i, int w, int h, vector<int>& X, vector<int>& S, vector<int>& E) {
    if (y < 0 || y >= h) return false;
    if (x == w - 1) return true;
    if (x == X[i] && (y > E[i] || y < S[i])) return false;
    if (x == X[i]) return solve(x, y, s, i + 1, w, h, X, S, E);
    vector<int> ds;
    if (y < S[i]) ds = {0, 1};
    else if (y > E[i]) ds = {0, -1};
    else ds = {0, 1, -1};
    bool res = false;
    for (auto d : ds) {
        res = res || solve(x + 1, y + s + d, s + d, i, w, h, X, S, E);
    }
    return res;
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


        bool s = solve(0, ceil(H / 2), 0, 0, N, H, x_wall, start_hole, end_hole);
        if (s) ans = "YES";
        else ans = "NO";


        cout << ans << endl;
    }

    return 0;
}
