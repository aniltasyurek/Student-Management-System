#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class temp {
    string rollNum, name, surname, address;
    fstream file;
public:
    void addStu();
    void viewStu();
    void searchStu();
};

int main() {
    char choice;
    temp obj;

    do {
        cout << "----------------" << endl;
        cout << "1- Add Student Record" << endl;
        cout << "2- View All Student Records" << endl;
        cout << "3- Search Student Record" << endl;
        cout << "4- Exit" << endl;
        cout << "----------------" << endl;
        cout << "Please enter a value: ";
        cin >> choice;
        cin.ignore();  

        switch (choice) {
        case '1':
            obj.addStu();
            break;
        case '2':
            obj.viewStu();
            break;
        case '3':
            obj.searchStu();
            break;
        case '4':
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != '4');

    return 0;
}

void temp::addStu() {
    cout << "Enter student roll number: ";
    getline(cin, rollNum);
    cout << "Enter student name: ";
    getline(cin, name);
    cout << "Enter student surname: ";
    getline(cin, surname);
    cout << "Enter student address: ";
    getline(cin, address);

    file.open("stuData.txt", ios::out | ios::app);
    if (!file.is_open()) {
        cout << "Failed to open file." << endl;
        return;
    }
    file << rollNum << "*";
    file << name << "*";
    file << surname << "*";
    file << address << "*" << endl;
    file.close();
}

void temp::viewStu() {
    file.open("stuData.txt", ios::in);
    if (!file.is_open()) {
        cout << "Failed to open file." << endl;
        return;
    }

    while (true) {
        if (!getline(file, rollNum, '*') ||
            !getline(file, name, '*') ||
            !getline(file, surname, '*') ||
            !getline(file, address)) {
            break;
        }

        cout << "\n";
        cout << "Student roll number: " << rollNum << endl;
        cout << "Student name: " << name << endl;
        cout << "Student surname: " << surname << endl;
        cout << "Student address: " << address << endl;
    }

    file.close();
}

void temp::searchStu() {
    cout << "Enter student roll number: ";
    string searchRollNum;
    getline(cin, searchRollNum);

    file.open("stuData.txt", ios::in);
    if (!file.is_open()) {
        cout << "Failed to open file." << endl;
        return;
    }

    while (true) {
        if (!getline(file, rollNum, '*') ||
            !getline(file, name, '*') ||
            !getline(file, surname, '*') ||
            !getline(file, address)) {
            break;
        }

        if (rollNum == searchRollNum) {
            cout << "\n";
            cout << "Student roll number: " << rollNum << endl;
            cout << "Student name: " << name << endl;
            cout << "Student surname: " << surname << endl;
            cout << "Student address: " << address << endl;
            break;
        }
    }

    file.close();
}
