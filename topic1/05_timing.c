#include <stdio.h>

int main() {
    long n = 100000000;
    long long start = 0;

    for (long i = 0; i < n; i++) {
        start += i;
    }
    printf("start = %lld\n", start);
    return 0;
}