#include <cstdio>
#include <cassert>
#include <iostream>

static FILE *fr, *fw;

// Declaring variables
static int N;
static long long M;
static int* V;
static int B;

// Declaring functions
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


int main() {
	fr = stdin;
	fw = stdout;

	// Iterators used in for loops
	int i0;

	// Reading input
	fscanf(fr, "%d %lld", &N, &M);
	V = (int*)malloc(N * sizeof(int));
	for (i0 = 0; i0 < N; i0++) {
	    fscanf(fr, "%d", &V[i0]);
	}

	// Calling functions
	B = quadri(N, M, V);

	// Writing output
	fprintf(fw, "%d\n", B);
	
	fclose(fr);
	fclose(fw);
	return 0;
}
