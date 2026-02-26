#include <cstdio>
#include <cassert>
#include <algorithm>

#define MAXN 100000

using namespace std;

int sfangate(int N, int V[]) {
    sort(V, V + N);
    int sum = 0;
    for (int i = 0; i < N; i++) sum += V[i];
    if (sum > 0) return 0;
    int c = 0;
    for (int i = 0; V[i] < 0 && sum <= 0; i++) {
        sum += -2 * V[i];
        c++;
    }
    return c;
}


int V[MAXN];

int main() {
    int N, i;

    FILE *fr = fopen("input.txt", "r");
    FILE *fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &V[i]));

    fprintf(fw, "%d\n", sfangate(N, V));
    fclose(fr);
    fclose(fw);
    return 0;
}