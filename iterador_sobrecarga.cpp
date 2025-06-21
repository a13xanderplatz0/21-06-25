#include <iostream>

using namespace std;

class iterador {
    int* x;

public:
    iterador() : x(nullptr) {}

    // Allow construction from int*
    iterador(int* p) : x(p) {}

    void operator=(int* p) {
        x = p;
    }

    void operator=(int p) {
        *x = p;
    }

    bool operator<(int* p) const {
        return x < p;
    }

    // Post-increment operator
    iterador operator++(int) {
        iterador temp = *this; // Save current state
        x++;                   // Move to next element
        return temp;
    }

    // Friend function to output the current value pointed by x
    friend ostream& operator<<(ostream& out, const iterador& it) {
        out << *(it.x);  // Dereference pointer to print value
        return out;
    }
};

int main() {
    iterador it;
    int A[10] = {1,2,3,4,5,6,7,8,9,10};
//igualo puntero 
    for (it = A; it < A + 10; it++)
        cout << it << " ";  // Outputs each element
        
        
    int b=100;
    for(it = A; it < A + 10; it++){
        
        it =b;//segunda sobrecarga 
        b+=10;}
        
        
        cout<<" "<<endl;
        
    for (it = A; it < A + 10; it++)
        cout << it << " ";  // Outputs each element

    return 0;
}
