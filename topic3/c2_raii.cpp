#include <iostream>

class queue {
  private:
    int *data;
    int count;

  public:
    queue() {
      data = new int[100];
      count = 0;
      std::cout << "constructor\n";
    }
    ~queue() {
      delete[] data;
      std::cout << "destructor\n";
    }
    void enqueue(int x) { 
      data[count++] = x; 
    }
};

int main() {
  {
    queue Q; // local object: no new, no delete
    Q.enqueue(5);
    std::cout << "using Q\n";
  } // Q goes out of scope -> destructor runs here
  std::cout << "after the block\n";
  return 0;
}
