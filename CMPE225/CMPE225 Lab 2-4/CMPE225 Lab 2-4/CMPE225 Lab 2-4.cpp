#include <iostream>
using namespace std;

class courseName {
public:
    string name;

    courseName(string nameinput) {
        name = nameinput;
    }

    courseName(const courseName &copy) {
        cout << "Copy Constructor\n";
        name = copy.name + "copy";
    }

    string getName() {
        return name;
    }
};

void display(courseName obj) {
    cout << obj.getName() << "\n";
}

int main()
{
    courseName course("Cmpe225");
    courseName course2 = course;
    display(course2);
    display(course);
}