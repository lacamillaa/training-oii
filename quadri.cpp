int quadri(int N, long long M, int V[]) {
    // risp. = [0, ..., N]
    int l = 0, r = N;
    int m = (l + r + 1) / 2;
    while (l != r) {
        long long s_m = 0;
        for (int i = 0; i < m; i++) {
            s_m += V[i];
        }
        long long max_s = s_m;
        for (int i = 1; i <= N - m; i++) {
            s_m -= V[i - 1];
            s_m += V[i + m - 1];
            if (s_m >= max_s) {
                max_s = s_m;
            }
        }
        if (max_s > M) {
            r = m - 1;
        }
        else {
            l = m;
        }
        m = (l + r + 1) / 2;
    }
    return m;
}