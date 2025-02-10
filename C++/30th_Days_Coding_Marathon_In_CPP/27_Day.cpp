// 1) Inheritance : BookCD bookmark_border
// Imagine a publishing company that markets both Book and CD's of its works. A class Publication is created that stores the title (a string) and price (type int) of a publication. From this class derive two classes:

// Book, which adds a page count and author, and a constructor having title, price, pages & writer as parameters.
// CD, which adds a playing time in minutes, and a constructor having title, price & length as parameters.
// Each of these two classes should have a putdata() function to display its data as shown in sample output.

#include <iostream>
#include <string>
using namespace std;

class Publication {
protected:
    string title;
    int price;
public:
    Publication(string t, int p) : title(t), price(p) {}
    void putdata() {
        cout << "Title: " << title << "\nPrice: " << price << endl;
    }
};

class Book : public Publication {
private:
    int pages;
    string author;
public:
    Book(string t, int p, int pg, string writer) 
        : Publication(t, p), pages(pg), author(writer) {}
    
    void putdata() {
        Publication::putdata();
        cout << "Pages: " << pages << "\nAuthor: " << author << endl;
    }
};

class CD : public Publication {
private:
    int length;
public:
    CD(string t, int p, int len) 
        : Publication(t, p), length(len) {}

    void putdata() {
        Publication::putdata();
        cout << "Playing Time: " << length << " minutes" << endl;
    }
};

int main() {
    string bookTitle, bookAuthor, cdTitle;
    int bookPrice, bookPages, cdPrice, cdLength;

    cin >> bookTitle >> bookPrice >> bookPages >> bookAuthor;
    cin >> cdTitle >> cdPrice >> cdLength;

    Book b(bookTitle, bookPrice, bookPages, bookAuthor);
    CD c(cdTitle, cdPrice, cdLength);

    cout << "Book Details:" << endl;
    b.putdata();
    
    cout << "\nCD Details:" << endl;
    c.putdata();

    return 0;
}





// 2) Diamond Problem bookmark_border
// A university system needs to manage individuals who can be both students and employees. The system should allow for storing and retrieving details of such individuals efficiently.
// The class structure is as follows:
// 1. Person (Base Class)
// Stores common attributes: name (string) and age (integer).
// Has a method display() to print the name and age.
// 2. Student (Derived from Person)
// Inherits name and age.
// Has an additional attribute studentID (integer).
// Has a method show_student() to print the student ID.
// 3. Employee (Derived from Person)
// Inherits name and age.
// Has an additional attribute empID (integer).
// Has a method show_employee() to print the employee ID.
// 4. WorkingStudent (Derived from Student and Employee)
// Represents a person who is both a student and an employee.
// Should be able to store name, age, studentID, and empID.
// Should have a method show_details() that displays all the attributes correctly.

// #include <iostream>
// #include <string>
// using namespace std;

// class Person {
// protected:
//     string name;
//     int age;
// public:
//     Person(string n, int a) : name(n), age(a) {}
//     void display() {
//         cout << "Name: " << name << "\nAge: " << age << endl;
//     }
// };

// class Student : virtual public Person {  // Virtual inheritance
// protected:
//     int studentID;
// public:
//     Student(string n, int a, int sid) : Person(n, a), studentID(sid) {}
//     void show_student() {
//         cout << "Student ID: " << studentID << endl;
//     }
// };

// class Employee : virtual public Person {  // Virtual inheritance
// protected:
//     int empID;
// public:
//     Employee(string n, int a, int eid) : Person(n, a), empID(eid) {}
//     void show_employee() {
//         cout << "Employee ID: " << empID << endl;
//     }
// };

// class WorkingStudent : public Student, public Employee {
// public:
//     WorkingStudent(string n, int a, int sid, int eid) 
//         : Person(n, a), Student(n, a, sid), Employee(n, a, eid) {} // Call Person once
    
//     void showDetails() {
//         display();  // Call Person's display() to avoid ambiguity
//         show_student();
//         show_employee();
//     }
// };

// int main() {
//     char name[100];
//     int age, stdId, empId;
//     cin >> name >> age >> stdId >> empId;

//     WorkingStudent ws(name, age, stdId, empId);
//     ws.showDetails(); 

//     return 0;
// }
