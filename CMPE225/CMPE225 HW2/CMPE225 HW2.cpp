#include <iostream>
using namespace std;
class HealthCenterInfo {
protected:

    string name;
    string surname;
    int age;
    int starvationRate;
public:
    HealthCenterInfo() {}
    HealthCenterInfo(string n, string s, int a) {
        name = n;
        surname = s;
        age = a;
        starvationRate = 100;
    }
    string getName() {
        return name;
    }
    string getSurname() {
        return surname;
    }
    string getFullName() {
        return name + " " + surname;
    }
    int getStarvationRate() {
        return starvationRate;
    }
    void setStarvationRate(int sR) {
        starvationRate = sR;
    }
    bool checkStarvation() {
        if (starvationRate < 20)
            return true;
        else
            return false;
    }
    ~HealthCenterInfo() {
        cout << name + " " + surname + " has quit the health center.\n";
    }
    
};

class Patient : public HealthCenterInfo {
protected:
    string diseaseName;
public:
    Patient(){}
    Patient(string n, string s, int a, string dN) {
        name = n;
        surname = s;
        age = a;
        diseaseName = dN;
        starvationRate = 100;
    }
    void setDiseaseName(string dN) {
        diseaseName = dN;
    }
    bool checkStarvation() {
        if (starvationRate < 50)
            return true;
        else
            return false;
    }
    void takeACare() {
        starvationRate -= 15;
        if (checkStarvation() == true)
            cout << "Patient " + getName() + " is hungry!\n";
    }
    ~Patient() {
        cout << getFullName() + " was discharged.\n";
    }
};

class Employee : public HealthCenterInfo {
protected:
    int employeeId;
public:
    Employee(){}
    Employee(string n, string s, int a, int id) {
        name = n;
        surname = s;
        age = a;
        employeeId = id;
        starvationRate = 100;
    }
    int getEmployeeId() {
        return employeeId;
    }
    bool checkStarvation() {
        if (starvationRate < 20)
            return true;
        else
            return false;
    }
    void checkPatient(Patient patient) {
        starvationRate -= 5;
        cout << "The patient named " + patient.getName() + " is being checked.\n";
        if (checkStarvation() == true)
            cout << name + " is starving.\n";
    }
    ~Employee() {
        cout << getFullName() + " quits the job in the health center.\n";
    }
};

class Doctor : public Employee {
public:
    Doctor(string n, string s, int a, int id) {
        name = n;
        surname = s;
        age = a;
        employeeId = id;
        starvationRate = 100;
    }
    void checkPatient(Patient& patient) {
        starvationRate -= 5;
        cout << "The patient named " + patient.getName() + " is being checked.\n";
        cout << name + " gives medicine to patient.\n";
        patient.takeACare();
        if (checkStarvation() == true)
            cout << getFullName() + " is starving.\n";
    }
    ~Doctor() {
        cout << getFullName() + " quit being a doctor in this center.\n";
    }
};

class Nurse : public Employee {
public:
    Nurse(string n, string s, int a, int id) {
        name = n;
        surname = s;
        age = a;
        employeeId = id;
        starvationRate = 100;
    }
    void checkPatient(Patient& patient) {
        starvationRate -= 10;
        cout << "The patient named " + patient.getName() + " is being checked.\n";
        cout << getFullName() + " took care of the patient.\n";
        patient.takeACare();
        if (checkStarvation() == true)
            cout << getFullName() + " is starving.\n";
    }
    ~Nurse() {
        cout << getFullName() + " quit being a nurse in this center.\n";
    }
};

int main()
{
    Doctor doctor("David", "Tennant", 49, 181971);
    Nurse nurse("Jodie", "Whittaker", 38, 171982);
    Patient patient("Matt", "Smith", 37, "xyzxyz");
    cout << "All of the people in this health center:\n";
    cout << nurse.getFullName() << endl;
    cout << doctor.getFullName() << endl;
    cout << patient.getFullName() << endl;
    cout << endl;
    for (int i = 0; i < 5; i++) {
        cout << nurse.getFullName() << endl;
        nurse.checkPatient(patient);
        cout << endl;
        cout << doctor.getFullName() << endl;
        doctor.checkPatient(patient);
        cout << endl;
    }
    return 0;
}