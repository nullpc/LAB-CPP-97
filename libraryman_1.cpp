/*
    ==============================================================
    LIBRARY MANAGEMENT SYSTEM
    ==============================================================
    A multi-class C++ OOP project demonstrating:
      - Encapsulation (private data + public methods)
      - Inheritance   (Person -> Member, Person -> Librarian)
      - Composition   (Book contains Author, Publisher, Category, Rack)
      - Polymorphism  (virtual displayPerson())
      - Multiple interacting objects managed by a controller class

    Classes used (15 total):
      1.  Address        6. Category       11. Fine
      2.  Person          7. Rack          12. IssueRecord
      3.  Author          8. Book          13. Reservation
      4.  Publisher       9. Member        14. Inventory
      5.  Librarian      10. LibraryCard   15. Library (controller)
    ==============================================================
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ================= 1. Address =================
class Address {
private:
    string street, city, pincode;
public:
    void inputAddress() {
        cout << "  Enter Street: "; getline(cin >> ws, street);
        cout << "  Enter City: ";   getline(cin >> ws, city);
        cout << "  Enter Pincode: "; getline(cin >> ws, pincode);
    }
    void displayAddress() const {
        cout << street << ", " << city << " - " << pincode;
    }
};

class Person {                       //Person Function used
protected:
    string name;
    int age;
    string phone;
public:
    void inputPerson() {
        cout << "Enter Name: "; getline(cin >> ws, name);
        cout << "Enter Age: "; cin >> age;
        cout << "Enter Phone No: "; cin >> phone;
    }
    virtual void displayPerson() const {
        cout << "Name  : " << name << endl;
        cout << "Age   : " << age << endl;
        cout << "Phone : " << phone << endl;
    }
    string getName() const { return name; }
    virtual ~Person() {}
};

class Author {                        //Author Funstion 
private:
    string name;
    string nationality;
public:
    void inputAuthor() {
        cout << "  Enter Author Name: "; getline(cin >> ws, name);
        cout << "  Enter Nationality: "; getline(cin >> ws, nationality);
    }
    void displayAuthor() const {
        cout << "Author     : " << name << " (" << nationality << ")";
    }
};

// ================= 4. Publisher =================
class Publisher {
private:
    string name;
    string city;
public:
    void inputPublisher() {
        cout << "  Enter Publisher Name: "; getline(cin >> ws, name);
        cout << "  Enter Publisher City: "; getline(cin >> ws, city);
    }
    void displayPublisher() const {
        cout << "Publisher  : " << name << ", " << city;
    }
};

// ================= 5. Librarian (inherits Person) =================
class Librarian : public Person {
private:
    int employeeID;
    string designation;
    float salary;
public:
    void inputLibrarian(int id) {
        employeeID = id;
        inputPerson();
        cout << "Enter Designation: "; getline(cin >> ws, designation);
        cout << "Enter Salary: "; cin >> salary;
    }
    void displayLibrarian() const {
        cout << "\n----- Librarian Details -----\n";
        cout << "Employee ID : " << employeeID << endl;
        displayPerson();
        cout << "Designation : " << designation << endl;
        cout << "Salary      : Rs. " << salary << endl;
    }
};

// ================= 6. Category =================
class Category {
private:
    string categoryName;
public:
    void inputCategory() {
        cout << "  Enter Category (Fiction/Science/History...): ";
        getline(cin >> ws, categoryName);
    }
    void displayCategory() const {
        cout << "Category   : " << categoryName;
    }
};

// ================= 7. Rack =================
class Rack {
private:
    int rackNo;
    string section;
public:
    void inputRack() {
        cout << "  Enter Rack No: "; cin >> rackNo;
        cout << "  Enter Section: "; getline(cin >> ws, section);
    }
    void displayRack() const {
        cout << "Location   : Rack " << rackNo << ", Section " << section;
    }
};

// ================= 8. Book (composition of 4,5,6,7) =================
class Book {
private:
    int bookID;
    string title;
    string ISBN;
    float price;
    int totalCopies;
    int availableCopies;
    Author author;
    Publisher publisher;
    Category category;
    Rack rack;
public:
    void inputBook(int id) {
        bookID = id;
        cout << "\nEnter Book Title: "; getline(cin >> ws, title);
        cout << "Enter ISBN: "; getline(cin >> ws, ISBN);
        cout << "Enter Price: "; cin >> price;
        cout << "Enter Total Copies: "; cin >> totalCopies;
        availableCopies = totalCopies;

        author.inputAuthor();
        publisher.inputPublisher();
        category.inputCategory();
        rack.inputRack();
    }
    void displayBook() const {
        cout << "\n-------------------------------------------\n";
        cout << "Book ID    : " << bookID << endl;
        cout << "Title      : " << title << endl;
        cout << "ISBN       : " << ISBN << endl;
        cout << "Price      : Rs. " << price << endl;
        cout << "Copies     : " << availableCopies << " / " << totalCopies << endl;
        author.displayAuthor();     cout << endl;
        publisher.displayPublisher(); cout << endl;
        category.displayCategory(); cout << endl;
        rack.displayRack();         cout << endl;
    }
    int getID() const { return bookID; }
    bool isAvailable() const { return availableCopies > 0; }
    void issueCopy() { if (availableCopies > 0) availableCopies--; }
    void returnCopy() { if (availableCopies < totalCopies) availableCopies++; }
};

// ================= 9. Member (inherits Person) =================
class Member : public Person {
private:
    int memberID;
    string membershipDate;
    int booksIssuedCount;
    static const int maxBooksAllowed = 3;
    Address address;
public:
    void inputMember(int id) {
        memberID = id;
        inputPerson();
        cout << "Enter Membership Date (dd-mm-yyyy): "; cin >> membershipDate;
        address.inputAddress();
        booksIssuedCount = 0;
    }
    void displayMember() const {
        cout << "\n----- Member Details -----\n";
        cout << "Member ID    : " << memberID << endl;
        displayPerson();
        cout << "Address      : "; address.displayAddress(); cout << endl;
        cout << "Joined On    : " << membershipDate << endl;
        cout << "Books Issued : " << booksIssuedCount << "/" << maxBooksAllowed << endl;
    }
    int getID() const { return memberID; }
    bool canIssueMore() const { return booksIssuedCount < maxBooksAllowed; }
    void incrementIssued() { booksIssuedCount++; }
    void decrementIssued() { if (booksIssuedCount > 0) booksIssuedCount--; }
};

// ================= 10. LibraryCard =================
class LibraryCard {
private:
    string cardNo;
    int memberID;
    string expiryDate;
public:
    void generateCard(int memID, int cardNum) {
        memberID = memID;
        cardNo = "LIB-" + to_string(cardNum);
        expiryDate = "31-12-2027";
    }
    void displayCard() const {
        cout << "Card No: " << cardNo << " | Member ID: " << memberID
             << " | Expiry: " << expiryDate << endl;
    }
};

// ================= 11. Fine =================
class Fine {
private:
    float amount;
    bool paid;
public:
    void calculateFine(int daysLate) {
        amount = (daysLate > 0) ? daysLate * 5.0f : 0.0f; // Rs. 5 per day late
        paid = false;
    }
    void displayFine() const {
        cout << "Fine Amount : Rs. " << amount
             << " | Status: " << (paid ? "Paid" : "Unpaid") << endl;
    }
};

// ================= 12. IssueRecord =================
class IssueRecord {
private:
    int issueID;
    int bookID;
    int memberID;
    string issueDate;
    string dueDate;
    bool returned;
    Fine fine;
public:
    void createRecord(int id, int bID, int mID, string iDate, string dDate) {
        issueID = id; bookID = bID; memberID = mID;
        issueDate = iDate; dueDate = dDate; returned = false;
    }
    void markReturned(int daysLate) {
        returned = true;
        fine.calculateFine(daysLate);
    }
    void displayRecord() const {
        cout << "Issue ID: " << issueID << " | Book ID: " << bookID
             << " | Member ID: " << memberID << " | Issue: " << issueDate
             << " | Due: " << dueDate << " | Status: "
             << (returned ? "Returned" : "Issued") << endl;
        if (returned) fine.displayFine();
    }
    int getIssueID() const { return issueID; }
    int getBookID() const { return bookID; }
    int getMemberID() const { return memberID; }
    bool isReturned() const { return returned; }
};

// ================= 13. Reservation =================
class Reservation {
private:
    int reservationID;
    int bookID;
    int memberID;
    string reservationDate;
    string status;
public:
    void createReservation(int id, int bID, int mID, string date) {
        reservationID = id; bookID = bID; memberID = mID;
        reservationDate = date; status = "Pending";
    }
    void displayReservation() const {
        cout << "Reservation ID: " << reservationID << " | Book ID: " << bookID
             << " | Member ID: " << memberID << " | Date: " << reservationDate
             << " | Status: " << status << endl;
    }
};

// ================= 14. Inventory =================
class Inventory {
private:
    vector<Book> books;
    int nextBookID;
public:
    Inventory() : nextBookID(1) {}

    void addBook() {
        Book b;
        b.inputBook(nextBookID++);
        books.push_back(b);
        cout << "Book added successfully!\n";
    }
    void displayAllBooks() const {
        if (books.empty()) { cout << "No books in inventory.\n"; return; }
        for (const auto &b : books) b.displayBook();
    }
    Book* findBookByID(int id) {
        for (auto &b : books) if (b.getID() == id) return &b;
        return nullptr;
    }
};

// ================= 15. Library (Controller class) =================
class Library {
private:
    Inventory inventory;
    vector<Member> members;
    vector<Librarian> librarians;
    vector<IssueRecord> issueRecords;
    vector<Reservation> reservations;
    vector<LibraryCard> cards;
    int nextMemberID, nextLibrarianID, nextIssueID, nextReservationID, nextCardNum;

public:
    Library() : nextMemberID(1), nextLibrarianID(1), nextIssueID(1),
                nextReservationID(1), nextCardNum(1) {}

    void addBook() { inventory.addBook(); }

    void addMember() {
        Member m;
        m.inputMember(nextMemberID);
        members.push_back(m);

        LibraryCard c;
        c.generateCard(nextMemberID, nextCardNum++);
        cards.push_back(c);

        cout << "Member registered! ";
        c.displayCard();
        nextMemberID++;
    }

    void addLibrarian() {
        Librarian l;
        l.inputLibrarian(nextLibrarianID++);
        librarians.push_back(l);
        cout << "Librarian added successfully!\n";
    }

    void issueBook() {
        int bID, mID;
        cout << "Enter Book ID to issue: "; cin >> bID;
        cout << "Enter Member ID: "; cin >> mID;

        Book* book = inventory.findBookByID(bID);
        Member* member = findMemberByID(mID);

        if (!book)   { cout << "Book not found!\n"; return; }
        if (!member) { cout << "Member not found!\n"; return; }
        if (!book->isAvailable()) { cout << "No copies available!\n"; return; }
        if (!member->canIssueMore()) { cout << "Member has reached max issue limit!\n"; return; }

        book->issueCopy();
        member->incrementIssued();

        IssueRecord rec;
        rec.createRecord(nextIssueID++, bID, mID, "10-08-2026", "24-08-2026");
        issueRecords.push_back(rec);
        cout << "Book issued successfully!\n";
    }

    void returnBook() {
        int issueID, daysLate;
        cout << "Enter Issue ID: "; cin >> issueID;
        cout << "Enter Days Late (0 if on time): "; cin >> daysLate;

        for (auto &rec : issueRecords) {
            if (rec.getIssueID() == issueID && !rec.isReturned()) {
                rec.markReturned(daysLate);
                Book* book = inventory.findBookByID(rec.getBookID());
                Member* member = findMemberByID(rec.getMemberID());
                if (book) book->returnCopy();
                if (member) member->decrementIssued();
                cout << "Book returned successfully!\n";
                rec.displayRecord();
                return;
            }
        }
        cout << "Issue record not found or already returned.\n";
    }

    void reserveBook() {
        int bID, mID;
        cout << "Enter Book ID to reserve: "; cin >> bID;
        cout << "Enter Member ID: "; cin >> mID;
        Reservation r;
        r.createReservation(nextReservationID++, bID, mID, "10-08-2026");
        reservations.push_back(r);
        cout << "Book reserved successfully!\n";
    }

    Member* findMemberByID(int id) {
        for (auto &m : members) if (m.getID() == id) return &m;
        return nullptr;
    }

    void displayAllBooks() const { inventory.displayAllBooks(); }

    void displayAllMembers() const {
        if (members.empty()) { cout << "No members registered.\n"; return; }
        for (const auto &m : members) m.displayMember();
    }

    void displayAllLibrarians() const {
        if (librarians.empty()) { cout << "No librarians added.\n"; return; }
        for (const auto &l : librarians) l.displayLibrarian();
    }

    void displayAllIssueRecords() const {
        if (issueRecords.empty()) { cout << "No issue records.\n"; return; }
        for (const auto &r : issueRecords) r.displayRecord();
    }

    void displayAllReservations() const {
        if (reservations.empty()) { cout << "No reservations.\n"; return; }
        for (const auto &r : reservations) r.displayReservation();
    }
};

// ================= Menu / main =================
void showMenu() {
    cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";
    cout << "1.  Add Book\n";
    cout << "2.  Add Member\n";
    cout << "3.  Add Librarian\n";
    cout << "4.  Issue Book\n";
    cout << "5.  Return Book\n";
    cout << "6.  Reserve Book\n";
    cout << "7.  Display All Books\n";
    cout << "8.  Display All Members\n";
    cout << "9.  Display All Librarians\n";
    cout << "10. Display Issue Records\n";
    cout << "11. Display Reservations\n";
    cout << "0.  Exit\n";
    cout << "Enter choice: ";
}

int main() {
    Library library;
    int choice;

    do {
        showMenu();
        cin >> choice;
        switch (choice) {
            case 1:  library.addBook(); break;
            case 2:  library.addMember(); break;
            case 3:  library.addLibrarian(); break;
            case 4:  library.issueBook(); break;
            case 5:  library.returnBook(); break;
            case 6:  library.reserveBook(); break;
            case 7:  library.displayAllBooks(); break;
            case 8:  library.displayAllMembers(); break;
            case 9:  library.displayAllLibrarians(); break;
            case 10: library.displayAllIssueRecords(); break;
            case 11: library.displayAllReservations(); break;
            case 0:  cout << "Exiting... Thank you!\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
