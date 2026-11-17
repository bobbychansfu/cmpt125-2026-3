class queue {
  private:
    int *data;
  public:
    queue()  { data = new int[100]; }
    ~queue() { delete[] data; }
};

int main() {
    queue Q1;
    queue Q2 = Q1;     // copies the POINTER data, not the array
    return 0;
}                      // ~queue runs twice on the same array
