#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Student 
{
private:
    string name;
    int rollNo;
    float marks;

public:
    void inputFromFile() {
        ifstream inputFile("student_data.txt");
        if (!inputFile) {
            cout << "Error: Could not open student_data.txt!" << endl;
            return;
        }
        getline(inputFile,name);
        inputFile >> rollNo;
        inputFile >> marks;
        inputFile.close();
    }

    void displayDetails() const {
        cout << "\n----- Student Details -----\n";
        cout << "Name      : " << name << endl;
        cout << "Roll No.  : " << rollNo << endl;
        cout << "Marks     : " << marks << endl;
    }
};
int main() 
{
    Student s;
    s.inputFromFile(); 
    s.displayDetails();
    return 0;
}
