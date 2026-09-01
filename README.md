# C++ Programming Assignments

A structured repository containing academic programming assignments, practical lab exercises, and algorithmic problem-solving implementations using C++.

## 🛠️ Language & Core Focus

<p align="left">
  <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/cplusplus/cplusplus-original.svg" alt="C++" width="60" height="60"/>
</p>

* **Object-Oriented Programming (OOP):** Encapsulation, Inheritance, Polymorphism, and Abstraction.
* **Memory Management:** Pointers, dynamic allocation, and resource safety.
* **Data Structures & STL:** Utilizing the Standard Template Library (Vectors, Lists, Maps, and Algorithms).

---

## 🚀 Repository Structure

Programs will be organized systematically as they are implemented:

```text
cpp-assignments/
├── Basic-Syntax/        # Control flow, functions, and arrays
├── OOP-Concepts/        # Classes, inheritance, and polymorphism
├── Data-Structures/     # Stacks, queues, linked lists, and STL
└── Lab-Journals/        # Official college lab submissions
```

---

## 📖 C++ Quick Reference Guide

A handy cheat sheet for basic syntax, variables, and standard I/O functions to speed up assignment development.

### 1. Basic Boilerplate
Every C++ program requires a starting structure, importing the Input/Output stream, and a `main()` function where execution begins.

```cpp
#include <iostream>   // Preprocessor directive for I/O functions

using namespace std;  // Allows usage of standard library objects without "std::" prefix

int main() {
    // Code goes here
    return 0;         // Indicates the program ended successfully
}
```

### 2. Standard Input & Output (`cin` and `cout`)
C++ uses streams for input and output, primarily utilizing the `<iostream>` library.

* **`cout <<`** : Used to print output to the console. (Think: "Console OUT")
* **`cin >>`** : Used to take input from the keyboard. (Think: "Console IN")
* **`endl`** or **`\n`** : Used to insert a new line.

```cpp
#include <iostream>
using namespace std;

int main() {
    int age;
    
    // Outputting text
    cout << "Enter your age: "; 
    
    // Taking input and storing it in the 'age' variable
    cin >> age; 
    
    // Chaining outputs
    cout << "You are " << age << " years old!" << endl; 
    
    return 0;
}
```

### 3. Core Data Types & Variables
C++ is statically typed, meaning you must declare the data type before using a variable.

```cpp
// Numeric Types
int count = 10;                // Integer (whole numbers)
float price = 99.99f;          // Floating-point number (add 'f' suffix)
double pi = 3.1415926535;      // Double-precision floating point (more accurate)

// Character & Text Types
char grade = 'A';              // Single character (use single quotes)
string name = "Hello World";   // Text string (requires #include <string>, use double quotes)

// Boolean Type
bool isValid = true;           // Can only be true (1) or false (0)
```

### 4. Core C/C++ Basics (Control Flow)
These foundational structures carry over from C and are essential for controlling how your program runs.

**If/Else Statements:**
```cpp
if (grade >= 40) {
    cout << "Passed!";
} else if (grade == 39) {
    cout << "Grace marks needed.";
} else {
    cout << "Failed.";
}
```

**Loops (For & While):**
```cpp
// For Loop - best when you know the exact number of iterations
for (int i = 0; i < 5; i++) {
    cout << i << " ";
}

// While Loop - best when looping based on a condition
int count = 0;
while (count < 5) {
    cout << count << " ";
    count++;
}
```

**Arrays:**
```cpp
// Declaring an array of 5 integers
int numbers[5] = {10, 20, 30, 40, 50};

// Accessing an element (0-indexed)
cout << "First element: " << numbers[0]; // Outputs 10
```

### 5. Compiling & Running (CLI)
If you are using a terminal (Linux/WSL/Termux) to run your code, use the GCC compiler (`g++`):

```bash
# 1. Compile the C++ file
g++ filename.cpp -o output_name

# 2. Run the compiled executable
./output_name
```

### 6. Common Errors & How to Fix Them

When C++ throws an error, read the terminal output carefully. It usually tells you the **line number** where the issue occurred.

**Compile-Time Errors (Code won't run):**
* `error: expected ';' before...`
  * **Fix:** You forgot a semicolon `;` at the end of the previous line.
* `error: 'variable_name' was not declared in this scope`
  * **Fix:** You are trying to use a variable before declaring it, or you misspelled its name. Check for typos and ensure the data type (e.g., `int`) is declared.
* `error: 'cout' / 'cin' / 'string' was not declared`
  * **Fix:** Ensure you have included the required libraries (`#include <iostream>` or `#include <string>`) and added `using namespace std;` at the top.

**Run-Time Errors (Code crashes while running):**
* **Segmentation Fault (Core Dumped)**
  * **Fix:** This is a memory error. You are likely trying to access an array index that doesn't exist (e.g., accessing `numbers[10]` in an array of size 5) or using an uninitialized pointer.
* **Infinite Loop**
  * **Fix:** If your program never stops printing or freezes, your `while` or `for` loop condition is never becoming `false`. Press `Ctrl + C` in the terminal to kill the program, then check your loop update statement (like `i++`).
* **Garbage Values**
  * **Fix:** If a variable prints a random massive number, you forgot to assign it a starting value before using it (e.g., `int count;` instead of `int count = 0;`).