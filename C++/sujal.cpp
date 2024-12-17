#include<iostream>
using namespace std;
class Complex {
    private:
        int real, imag;

    public:
        Complex(int r , int i  ){
            real=r;
            imag=i;
        }

        // Friend function for overloading the '+' operator
       friend Complex operator+(Complex c1, Complex c2);
        
        void display() {
            cout << "Real: " << real << ", Imaginary: " << imag << endl;
        }
        
};

Complex operator+(Complex c1, Complex c2) {
    Complex temp(c1.real + c2.real, c1.imag + c2.imag);
    return temp;
}


int main() {
    Complex c1(1, 2), c2(3, 4);
    Complex c3 = c1 + c2; // Calls the friend function

    c3.display();
return 0;
}