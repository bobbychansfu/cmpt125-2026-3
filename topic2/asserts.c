#include <stdio.h>
#include <assert.h>

int main() {
    int x = 5;
    int y = 2;

    assert(y != 0); // This will trigger an assertion failure if y is zero
    int result = x/y;
    printf("Result: %d\n", result);
    return 0;

}