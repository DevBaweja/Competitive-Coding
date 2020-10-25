#include <iostream>

using namespace std;

template <typename T>
T square(T x)
{
    return x * x;
}

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
};

template <typename T>
MyVector<T> operator*(const MyVector<T> &lhs, const MyVector<T> &rhs)
{
    MyVector<T> temp;
    for (int i = 0; i < lhs.getSize() || i < rhs.getSize(); i++)
    {
        temp.push(lhs.get(i) * rhs.get(i));
    }
    return temp;
}

int main()
{
    MyVector<int> V;

    V.push(1);
    V.push(2);
    V.push(3);

    V = square(V);

    V.print();
}