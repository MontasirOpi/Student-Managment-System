#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_STUDENTS = 20;
const string ADMIN_PASSWORD = "admin123";

struct Student {
    string name;
    string roll;
    string semester;
    string technology;
    string phoneNumber;
};

Student students[MAX_STUDENTS];
int totalStudents = 0;

struct Registration {
    string username;
    string password;
};

Registration registrationInfo[MAX_STUDENTS];
int totalRegistrations = 0;

void enter()
{
    int choice;
    cout << "How many students do you want to enter? ";
    cin >> choice;

    if (totalStudents + choice > MAX_STUDENTS) {
        cout << "Maximum number of students exceeded." << endl;
        return;
    }

    for (int i = totalStudents; i < totalStudents + choice; i++) {
        cout << "\nEnter data of student " << i + 1 << endl;
        Student newStudent;
        cout << "Enter name: ";
        cin >> newStudent.name;
        cout << "Enter roll: ";
        cin >> newStudent.roll;
        cout << "Enter semester: ";
        cin >> newStudent.semester;
        cout << "Enter technology: ";
        cin >> newStudent.technology;
        cout << "Enter phone number: ";
        cin >> newStudent.phoneNumber;
        students[i] = newStudent;
    }

    totalStudents += choice;
    cout << "\nData entered successfully." << endl;
}

void show()
{
    if (totalStudents == 0) {
        cout << "No student records found." << endl;
        return;
    }

    cout << "\n-------------------------------------------------------------" << endl;
    cout << setw(10) << "Student" << setw(15) << "Name" << setw(10) << "Roll" << setw(15) << "Semester" << setw(15) << "Technology" << setw(15) << "Phone Number" << endl;
    cout << "-------------------------------------------------------------" << endl;

    for (int i = 0; i < totalStudents; i++) {
        cout << setw(10) << "Student " << i + 1 << setw(15) << students[i].name << setw(10) << students[i].roll << setw(15) << students[i].semester << setw(15) << students[i].technology << setw(15) << students[i].phoneNumber << endl;
    }
    cout << "-------------------------------------------------------------" << endl;
}

void searchrecord()
{
    if (totalStudents == 0) {
        cout << "No student records found." << endl;
        return;
    }

    string rollno;
    cout << "\nEnter roll of student you want to search: ";
    cin >> rollno;

    for (int i = 0; i < totalStudents; i++) {
        if (rollno == students[i].roll) {
            cout << "\nData of student " << i + 1 << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "Roll: " << students[i].roll << endl;
            cout << "Semester: " << students[i].semester << endl;
            cout << "Technology: " << students[i].technology << endl;
            cout << "Phone Number: " << students[i].phoneNumber << endl;
            return;
        }
    }

    cout << "Student with roll number " << rollno << " not found." << endl;
}

void update()
{
    if (totalStudents == 0) {
        cout << "No student records found." << endl;
        return;
    }

    string rollno;
    cout << "\nEnter roll of student you want to update: ";
    cin >> rollno;

    for (int i = 0; i < totalStudents; i++) {
        if (rollno == students[i].roll) {
            cout << "\nPrevious Data" << endl;
            cout << "Data of student " << i + 1 << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "Roll: " << students[i].roll << endl;
            cout << "Semester: " << students[i].semester << endl;
            cout << "Technology: " << students[i].technology << endl;
            cout << "Phone Number: " << students[i].phoneNumber << endl;

            cout << "\nEnter new data" << endl;
            cout << "Enter Name: ";
            cin >> students[i].name;
            cout << "Enter roll: ";
            cin >> students[i].roll;
            cout << "Enter semester: ";
            cin >> students[i].semester;
            cout << "Enter technology: ";
            cin >> students[i].technology;
            cout << "Enter phone number: ";
            cin >> students[i].phoneNumber;

            cout << "\nData updated successfully." << endl;
            return;
        }
    }

    cout << "Student with roll number " << rollno << " not found." << endl;
}

void deleterecord()
{
    if (totalStudents == 0) {
        cout << "No student records found." << endl;
        return;
    }

    int choice;
    cout << "\nPress 1 to delete full record" << endl;
    cout << "Press 2 to delete specific record" << endl;
    cin >> choice;

    if (choice == 1) {
        totalStudents = 0;
        cout << "\nAll records have been deleted." << endl;
    }
    else if (choice == 2) {
        string rollno;
        cout << "Enter roll number of student you want to delete: ";
        cin >> rollno;

        for (int i = 0; i < totalStudents; i++) {
            if (rollno == students[i].roll) {
                for (int j = i; j < totalStudents - 1; j++) {
                    students[j] = students[j + 1];
                }
                totalStudents--;
                cout << "\nThe required record has been deleted." << endl;
                return;
            }
        }

        cout << "Student with roll number " << rollno << " not found." << endl;
    }
}

void registration()
{
    int choice;
    cout << "\nHow many students do you want to register? ";
    cin >> choice;

    if (choice <= 0) {
        cout << "Invalid number of students." << endl;
        return;
    }

    for (int i = 0; i < choice; i++) {
        string username, password;
        cout << "\nRegistration for student " << i + 1 << endl;
        cout << "Enter name: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        registrationInfo[totalRegistrations].username = username;
        registrationInfo[totalRegistrations].password = password;
        totalRegistrations++;
    }

    cout << "\nRegistration successful!" << endl;
}

void showRegistrationDetails()
{
    string password;
    cout << "\nEnter the password to view registration details: ";
    cin >> password;

    if (password == ADMIN_PASSWORD) {
        cout << "\nRegistration Details" << endl;
        cout << "\n-------------------------------------------" << endl;
        cout << "Total Registrations: " << totalRegistrations << endl;
        cout << "\nStudent\tUsername\tPassword" << endl;
        cout << "-------------------------------------------" << endl;
        for (int i = 0; i < totalRegistrations; i++) {
            cout << i + 1 << "\t" << registrationInfo[i].username << "\t\t" << registrationInfo[i].password << endl;
        }
        cout << "-------------------------------------------" << endl;
    }
    else {
        cout << "Incorrect password. Access denied." << endl;
    }
}

void clearConsole()
{
    cout << "\033[2J\033[1;1H"; // ANSI escape sequence to clear console
}

void printCenter(string text)
{
    int width = 80;
    int length = text.length();
    int startPos = (width - length) / 2;
    cout << setw(startPos + length) << text << endl;
}

int main()
{
    int value;

    clearConsole();

    cout << "-----------------------------------" << endl;
    printCenter("Student Information System");
    cout << "-----------------------------------" << endl;

    while (true) {
        cout << "\nPress 1 to enter data" << endl;
        cout << "Press 2 to show data" << endl;
        cout << "Press 3 to search data" << endl;
        cout << "Press 4 to update data" << endl;
        cout << "Press 5 to delete data" << endl;
        cout << "Press 6 to register" << endl;
        cout << "Press 7 to show registration details" << endl;
        cout << "Press 8 to exit" << endl;

        cout << "\nEnter your choice: ";
        cin >> value;

        clearConsole();

        cout << "-----------------------------------" << endl;
        printCenter("Student Information System");
        cout << "-----------------------------------" << endl;

        switch (value) {
            case 1:
                enter();
                break;
            case 2:
                show();
                break;
            case 3:
                searchrecord();
                break;
            case 4:
                update();
                break;
            case 5:
                deleterecord();
                break;
            case 6:
                registration();
                break;
            case 7:
                showRegistrationDetails();
                break;
            case 8:
                clearConsole();
                exit(0);
                break;
            default:
                cout << "Invalid keyword" << endl;
                break;
        }
    }

    return 0;
}
