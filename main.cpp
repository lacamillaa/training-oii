#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <map>
#include <set>

using namespace std;

int main() {

    FILE *fr = fopen("input.txt", "r");
    FILE *fw = fopen("output.txt", "w");

    int T;
    fscanf(fr, "%d", &T);

    for (int t = 1; t <= T; t++) {
        int N, A, B;
        fscanf(fr, "%d %d %d", &N, &A, &B);

        map<int, vector<int>> adiacenza;

        for (int i = 0; i < A; i++) {
            int Z;
            fscanf(fr, "%d", &Z);
            adiacenza[-i-1].push_back(Z);
        }

        for (int i = 0; i < B; i++) {
            int X, Y;
            fscanf(fr, "%d %d", &X, &Y);
            adiacenza[X].push_back(Y);
            adiacenza[Y].push_back(X);
        }

        int x = 0, c = 0;

        set<int> visited;
        set<pair<int, int>> da_vis;
        map<int, int> distanze;

        for (int i = -A; i < N; i++) {
            if (i < 0) {
                distanze[i] = 0;
                da_vis.insert({0, i});
            }
            else distanze[i] = INT32_MAX;
        }

        while (!da_vis.empty()) {
            // estrai il nodo più vicino
            auto [dist, s] = *da_vis.begin();
            da_vis.erase({dist, s});
            visited.insert(s);
            for (auto y : adiacenza[s]) {
                if (!visited.count(y)) {
                    if (dist + 1 < distanze[y]) {
                        distanze[y] = dist + 1;
                        da_vis.insert({dist + 1, y});
                    }
                }
            }
        }

        for (int i = 0; i < N; i++) {
            if (distanze[i] > c) {
                c = distanze[i];
                x = i;
            }
        }

        fprintf(fw, "Case #%d: %d %d\n", t, x, c);
    }

    return 0;
}
