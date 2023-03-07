#include <iostream>
using namespace std;
class Distance {
private:
    int meter;
    int centimeter;
public:
    Distance() {
        meter = 0;
        centimeter = 0;
    }
    Distance(int m):meter(m) {}
    Distance(int m, int cm) {
        meter = m;
        centimeter = cm;
    }
    int getMeter() {
        return meter;
    }
    int getCentimeter() {
        return centimeter;
    }
    friend Distance mathMult(Distance obj);
    friend Distance operator+(Distance obj1, Distance obj2);
    friend Distance operator-(Distance obj1, Distance obj2);
};

Distance mathMult(Distance obj) {
    obj.meter *= 2;
    obj.centimeter *= 2;
    while(obj.centimeter > 100) {
        obj.centimeter -= 100;
        obj.meter += 1;
    }
    return obj;
}

Distance operator+(Distance obj1, Distance obj2) {
    Distance obj3;
    obj3.meter = obj1.meter + obj2.meter;
    obj3.centimeter = obj1.centimeter + obj2.centimeter;
    while (obj3.centimeter > 100) {
        obj3.centimeter -= 100;
        obj3.meter += 1;
    }
    return obj3;
}

Distance operator-(Distance obj1, Distance obj2) {
    Distance obj3;
    obj3.meter = obj1.meter - obj2.meter;
    obj3.centimeter = obj1.centimeter - obj2.centimeter;
    while (obj3.centimeter < 0) {
        obj3.centimeter += 100;
        obj3.meter -= 1;
    }
    return obj3;
}
int main()
{
    Distance obj(2, 60);
    obj = mathMult(obj);
    cout << "Result: " << obj.getMeter() << "." << obj.getCentimeter() << "m\n";
    Distance obj2(20, 98);
    Distance obj3(10, 99);
    obj = obj2 + obj3;
    cout << "Result: " << obj.getMeter() << "." << obj.getCentimeter() << "m\n";
    obj = obj2 - obj3;
    cout << "Result: " << obj.getMeter() << "." << obj.getCentimeter() << "m\n";
}