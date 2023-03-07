#include <iostream>
using namespace std;

class PlayerInformation {
    public:
        string name = "Stephen";
        string surname = "Curry";
        int age = 32;
};

int main()
{
    PlayerInformation player;
    cout << "Player Name: " << player.name << "\n";
    cout << "Player Surname: " << player.surname << "\n";
    cout << "Player Age: " << player.age << "\n";
}
