#include <iostream>

using namespace std;

template <typename T>
class iterador {
    T* x;

public:
    iterador() : x(nullptr) {}

    iterador(T* p) : x(p) {}

    void operator=(T* p) {
        x = p;
    }

    void operator=(T p) {
        *x = p;
    }

    bool operator<(T* p) const {
        return x < p;
    }

    iterador operator++(int) {
        iterador temp = *this;
        x++;
        return temp;
    }

    friend ostream& operator<<(ostream& out, const iterador& it) {
        out << *(it.x);
        return out;
    }
};

int main() {
    iterador<int> it;
    int A[10] = {1,2,3,4,5,6,7,8,9,10};

    for (it = A; it < A + 10; it++)
        cout << it << " ";

    int b = 100;
    for (it = A; it < A + 10; it++) {
        it = b;
        b += 10;
    }

    cout << " " << endl;

    for (it = A; it < A + 10; it++)
        cout << it << " ";

    return 0;
}
