#include <iostream>

int main() {
    int *p = nullptr;          // C++ spelling of NULL
    bool done = (p == nullptr);
    std::cout << "done = " << done << '\n';
    return 0;
}
