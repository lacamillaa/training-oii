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
    for (long long i = 0; i < static_cast<long long>(pow(10, N)); i++) {
        if (is_cabala(i)) {
            R = max(R, i % M);
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