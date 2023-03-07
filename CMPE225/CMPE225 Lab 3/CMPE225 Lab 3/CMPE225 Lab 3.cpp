using namespace std;
#include <iostream>

class Complex {
private:
    int real;
    int imag;
public:
    friend Complex operator+(Complex obj1, Complex obj2);
    friend Complex operator-(Complex obj1, Complex obj2);
    friend Complex operator*(Complex obj1, Complex obj2);
    friend istream& operator>>(istream &itest, Complex &obj);
    friend ostream& operator<<(ostream &otest, Complex &obj);
    Complex(int r=0, int i=0) {
        real = r;
        imag = i;
    }
    void getComplex() {
        cout << "Complex Number: " << real << " + " << imag << "i\n";
    }
    void setComplex(int r, int i) {
        real = r;
        imag = i;
    }
    void addComplex(Complex obj) {
        obj.real += 1;
        obj.imag += 1;
    }
};

istream& operator>>(istream &itest, Complex &obj) {
    itest >> obj.real >> obj.imag;
    return itest;
}

ostream& operator<<(ostream &otest, Complex &obj) {
    otest << "Complex Number: " << obj.real << " + " << obj.imag << "i\n";
    return otest;
}

Complex operator+(Complex obj1, Complex obj2) {
    Complex obj3;
    obj3.real = obj1.real + obj2.real;
    obj3.imag = obj1.imag + obj2.imag;
    return obj3;
}

Complex operator-(Complex obj1, Complex obj2) {
    Complex obj3;
    obj3.real = obj1.real - obj2.real;
    obj3.imag = obj1.imag - obj2.imag;
    return obj3;
}

Complex operator*(Complex obj1, Complex obj2) {
    Complex obj3;
    obj3.real = obj1.real * obj2.real;
    obj3.imag = obj1.imag * obj2.imag;
    return obj3;
}


int main()
{
    int r, i;
    Complex c1(10, 5);
    Complex c2(2, 4);
    Complex c3;
    cout << "Input c3 (r+i):\n";
    cin >> c3;
    cout << c3;
    c3 = (c1 + c2);
    cout << c3;
    c3 = (c1 - c2);
    cout << c3;
    c3 = (c1 * c2);
    cout << c3;
}

