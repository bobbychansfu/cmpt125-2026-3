#include <iostream>

void swapC(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
} // C style
void swapCpp(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
} // C++ reference

int main()
{
    int x = 1, y = 2;
    swapC(&x, &y);
    std::cout << x << " " << y << '\n';
    swapCpp(x, y); // no & at the call
    std::cout << x << " " << y << '\n';
    return 0;
}
