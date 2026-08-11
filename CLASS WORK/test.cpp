#include <iostream>
using namespace std;

// ==========================================
// STEP 1: DEFINING THE CLASS (The Blueprint)
// ==========================================
class Robot {
public:
    string name; // Variable

    void introduce() { // Function
        cout << "Hello, I am " << name << "!" << endl;
    }
};

int main() {
    // ==========================================
    // STEP 2: CREATING THE OBJECT (The Instance)
    // ==========================================
    Robot myRobot; 

    // ==========================================
    // STEP 3: CALLING / ACCESSING THE MEMBERS
    // ==========================================
    // Accessing the variable to give the robot a name
    myRobot.name = "Robo-1"; 

    // Calling the function using the object
    myRobot.introduce(); // This prints: Hello, I am Robo-1!

    return 0;
}
