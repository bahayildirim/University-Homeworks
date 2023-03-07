#include <iostream>
using namespace std;
class Member;
class Hours {
public:
    int hours;
    int minutes;
    friend istream& operator>>(istream& input, Hours &obj) {
        input >> obj.hours >> obj.minutes;
        return input;
    }
    friend ostream& operator<<(ostream& output, Hours &obj) {
        output << obj.hours << ":" << obj.minutes;
        return output;
    }
};
class Member {
protected:
    string id;
    string member_name;
    Hours total;
    int total_minutes;
public:
    Member(string i, string m, int t_m) {
        id = i;
        member_name = m;
        total_minutes = t_m;
    }
    Member() {
        id = " ";
        member_name = " ";
        total_minutes = 0;
    }
    static int calcMin(Hours checkIn, Hours checkOut) {
        if (checkOut.hours < checkIn.hours) {
            return 0;
        }
        if ((checkOut.minutes < checkIn.minutes) && (checkOut.hours > checkIn.hours)) {
            return (checkOut.hours - 1 - checkIn.hours) * 60 + (checkOut.minutes + 60 - checkIn.minutes);
        }
        return (checkOut.hours - checkIn.hours) * 60 + (checkOut.minutes - checkIn.minutes);
    }
};
class Player : public Member {
protected:
    string specialty;
public:
    Player(string i, string m, string s) {
        specialty = s;
        id = i;
        member_name = m;
    }
    void print() {
        cout << "Id of the member is " << id << endl;
        cout << "Name of the member is " << member_name << endl;
        cout << "Specialty of the member is " << specialty << endl;
    }
};
int main()
{
    Player obj1("917537", "Stephen Curry", "Player");
    obj1.print();
    Hours time1;
    Hours time2;
    cout << "Enter the check in time of the member: \n";
    cin >> time1;
    cout << "Enter the check out time of the member: \n";
    cin >> time2;
    cout << "Check in and check out times are " << time1 << " and " << time2 << endl;
    int total_time = Member::calcMin(time1, time2);
    if (total_time == 0) {
        cout << "Please enter the time properly.";
        return 0;
    }
    cout << "The total time member stays in the sports center is " << total_time << " minutes.";
    return 0;
}