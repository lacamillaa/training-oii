#include <cstdio>
#include <cassert>
#include <cmath>

using namespace std;

bool is_cabala(long long n) {
    if (n < 10 && n % 3 == 0) return true;
    int ultima = n % 10;
    int penultima = n % 100 / 10;
    if (penultima != ultima && ultima % 3 == 0 && is_cabala(n / 10)) return true;
    return false;
}

long long occulta(int N, int M) {
    // N => numero massimo di cifre
    long long R = 0;
    for (int m = M - 1; m >= 0; m--) {
        // esplora ogni possibile resto
        for (int n = m; n < pow(10, N); n += M) {
            if (is_cabala(n)) return m;
        }
    }
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