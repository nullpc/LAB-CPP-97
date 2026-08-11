#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

struct Student {
    int roll;
    string name;
    float marks;
    string branch;
};

// Function to add/write student data to file
void writeStudent() {
    ofstream fout("students.dat", ios::binary | ios::app); // append mode
    Student s;
    
    cout << "\n--- Enter Student Details ---\n";
    cout << "Roll No: ";
    cin >> s.roll;
    cin.ignore(); // to clear buffer
    cout << "Name: ";
    getline(cin, s.name);
    cout << "Marks: ";
    cin >> s.marks;
    cin.ignore();
    cout << "Branch: ";
    getline(cin, s.branch);

    fout.write((char*)&s, sizeof(s));
    fout.close();
    cout << "Record Saved Successfully!\n";
}

// Function to read/fetch all student records
void readAllStudents() {
    ifstream fin("students.dat", ios::binary);
    Student s;
    
    if(!fin) {
        cout << "File not found! No records yet.\n";
        return;
    }

    cout << "\n--- All Student Records ---\n";
    cout << left << setw(10) << "Roll" << setw(20) << "Name" 
         << setw(10) << "Marks" << setw(15) << "Branch" << endl;
    cout << "--------------------------------------------------------\n";

    while(fin.read((char*)&s, sizeof(s))) {
        cout << left << setw(10) << s.roll << setw(20) << s.name 
             << setw(10) << s.marks << setw(15) << s.branch << endl;
    }
    fin.close();
}

// Function to search student by roll no
void searchStudent() {
    ifstream fin("students.dat", ios::binary);
    Student s;
    int r, found = 0;
    
    cout << "Enter Roll No to Search: ";
    cin >> r;

    while(fin.read((char*)&s, sizeof(s))) {
        if(s.roll == r) {
            cout << "\nRecord Found:\n";
            cout << "Roll: " << s.roll << "\nName: " << s.name 
                 << "\nMarks: " << s.marks << "\nBranch: " << s.branch << endl;
            found = 1;
            break;
        }
    }
    if(!found) cout << "Record Not Found!\n";
    fin.close();
}

int main() {
    int choice;
    do {
        cout << "\n===== STUDENT RECORD SYSTEM =====\n";
        cout << "1. Add Student Record\n";
        cout << "2. Display All Records\n";
        cout << "3. Search Student by Roll\n";
        cout << "4. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice) {
            case 1: writeStudent(); break;
            case 2: readAllStudents(); break;
            case 3: searchStudent(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid Choice!\n";
        }
    } while(choice != 4);

    return 0;
}