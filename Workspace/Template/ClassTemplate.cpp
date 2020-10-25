#include <iostream>

using namespace std;

template <typename T>

class MyVector
{
    T A[10];
    int size;

public:
    MyVector() : size(0) {}
    void push(T x) { A[size++] = x; }
    T get(int i) const { return A[i]; }
    int getSize() const { return size; }
    void print() const
    {
        for (int i = 0; i < size; i++)
            cout << A[i] << endl;
    }
    T operator[](int i) const { return A[i]; }
};

int main()
{
    MyVector<int> V;

    V.push(1);
    V.push(2);
    V.push(3);

    V.print();
    cout << V[1];
}