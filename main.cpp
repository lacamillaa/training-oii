#include <cstdio>
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

void gen_cabala(long long *R, int M, vector<long long>& res, long long I, int p, int P) {
    if (p == P) return;
    for (int i = 3; i < 10; i += 3) {
        if (I % 10 != i) {
            long long n = I * 10 + i;
            res.push_back(n);
            gen_cabala(R, M, res, n, p + 1, P);
            *R = max(*R, n % M);
        }
    }
}

long long occulta(int N, int M) {
    long long R = 0;
    vector<long long> res;
    gen_cabala(&R, M, res, 0, 0, N);
    return R;
}

int main() {
    FILE *fr = fopen("input.txt", "r");
    FILE *fw = fopen("output.txt", "w");

    int T, N, M;
    assert(1 == fscanf(fr, "%d", &T));
    for (int i=0; i<T; i++) {
        assert(2 == fscanf(fr, "%d %d", &N, &M));
        fprintf(fw, "%lld ", occulta(N, M));
    }

    fprintf(fw, "\n");
    fclose(fr);
    fclose(fw);
    return 0;
}