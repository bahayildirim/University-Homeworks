#include <iostream>
using namespace std;

int manip(int , int );
int manip(int , int , int );

int main()
{
    int a = 2, b = 3, c = 4;
    cout << "First result: " + manip(a,b) << endl;
    cout << "Second result: " + manip(a, b, c) << endl;
    return 0;
}

int manip(int x, int y) {
    return x * y;
}

int manip(int x, int y, int z) {
    return x * y * z;
}