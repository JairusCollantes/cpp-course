#include <iostream>
#include <string>
using namespace std;

int main() {
    int numStudents;

    cout << "Enter number of students (1-5): ";
    cin >> numStudents;

    while (numStudents < 1 || numStudents > 5) {
        cout << "Invalid input. Enter number of students (1-5): ";
        cin >> numStudents;
    }

    string names[5];
    int scores[5];

    for (int i = 0; i < numStudents; i++) {
        cout << "\nStudent " << i + 1 << " Name: ";
        cin >> names[i];

        cout << "Student " << i + 1 << " Score: ";
        cin >> scores[i];
    }

    int choice;

    do {
        cout << "\nMENU\n";
        cout << "1. Display Student Records\n";
        cout << "2. Update Student Score\n";
        cout << "3. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1) {

            cout << "\nSTUDENT RECORDS\n";

            for (int i = 0; i < numStudents; i++) {
                cout << i + 1 << ". "
                     << names[i] << " - "
                     << scores[i] << endl;
            }

        }
        else if (choice == 2) {

            int studentNumber;
            int newScore;

            cout << "\nEnter Student Number (1-" << numStudents << "): ";
            cin >> studentNumber;

            if (studentNumber >= 1 && studentNumber <= numStudents) {

                cout << "Enter New Score: ";
                cin >> newScore;

                scores[studentNumber - 1] = newScore;

                cout << "Score Updated Successfully!\n";

            } else {
                cout << "Invalid Student Number!\n";
            }

        }
        else if (choice == 3) {

            cout << "\nProgram Exited.\n";

        }
        else {
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 3);

    return 0;
}