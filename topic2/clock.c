#include <stdio.h>
#include <stdlib.h>   // rand, srand
#include <time.h>     // clock, CLOCKS_PER_SEC

#define N 100000

int main(void) {
    static int A[N];

    srand(125);
    for (int i = 0; i < N; i++)
        A[i] = rand() % 1000;    // random int in 0..999

    clock_t start = clock();   // CPU time used so far, in "ticks"

    long long sum = 0;   // the work being timed
    for (int rep = 0; rep < 2000; rep++)
        for (int i = 0; i < N; i++)
            sum += A[i];

    clock_t end = clock();

    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("sum = %lld, time = %.3f seconds\n", sum, seconds);
    return 0;
}