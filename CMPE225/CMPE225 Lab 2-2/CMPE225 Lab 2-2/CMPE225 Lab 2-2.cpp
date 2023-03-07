#include <iostream>
using namespace std;

class Line {
    private:
        int length;
public:
    Line(){
        cout << "Object is being created.\n";
    }

    ~Line(){
        cout << "Object is being deleted.\n";
    }

    void getLength() {
        cout << "Length of line: " << length << "\n";
    }

    void setLength(int new_length) {
        length = new_length;
    }
};
int main()
{
    Line line;
    line.setLength(7);
    line.getLength();
}