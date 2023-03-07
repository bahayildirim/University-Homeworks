#include <iostream>
using namespace std;

class Country {
    private:
        string c_name;
        int c_cities;
        int c_population;
    public:
        Country(string name){
            c_name = name;
            cout << name << " is created.\n";
        }

        Country(string name, int cities) {
            c_name = name;
            c_cities = cities;
            cout << name << " is created with " << cities << " number of cities.\n";
        }

        Country(string name, int cities, int population) {
            c_name = name;
            c_cities = cities;
            c_population = population;
            cout << name << " is created with " << cities << " number of cities and " << population << " populations.\n";
        }

        ~Country(){
            cout << c_name << " is deleted.\n";
        }
};

int main()
{
    Country c1("Turkey");
    Country c2("Ukraine", 24);
    Country c3("Japan", 20, 127000000);
    c1.~Country();
    c2.~Country();
    c3.~Country();
    system("pause");
    return(0);
}