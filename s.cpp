#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Student {
    int roll;
    char name[50];
    int age;
    int math, science, cs;
};

void encrypt(char *text) {
    for(int i = 0; text[i] != '\0'; i++)
        text[i] += 2;
}

void decrypt(char *text) {
    for(int i = 0; text[i] != '\0'; i++)
        text[i] -= 2;
}

void addStudent() {
    Student s;
    ofstream file("data.txt", ios::app);
    cout << "Enter Roll Name Age Math Science CS:\n";
    cin >> s.roll >> s.name >> s.age >> s.math >> s.science >> s.cs;
    encrypt(s.name);
    file << s.roll << " " << s.name << " " << s.age << " "
         << s.math << " " << s.science << " " << s.cs << endl;
    file.close();
    cout << "Student Added Successfully!\n";
}

void viewAll() {
    Student s;
    ifstream file("data.txt");
    cout << "\nRoll\tName\tAge\tMath\tScience\tCS\n";
    while(file >> s.roll >> s.name >> s.age >> s.math >> s.science >> s.cs) {
        decrypt(s.name);
        cout << s.roll << "\t" << s.name << "\t" << s.age << "\t"
             << s.math << "\t" << s.science << "\t" << s.cs << endl;
    }
    file.close();
}

void viewOne() {
    char search[50];
    Student s;
    bool found = false;
    cout << "Enter Name: ";
    cin >> search;
    encrypt(search);
    ifstream file("data.txt");
    while(file >> s.roll >> s.name >> s.age >> s.math >> s.science >> s.cs) {
        if(strcmp(s.name, search) == 0) {
            decrypt(s.name);
            cout << "\nFound Student:\n";
            cout << "Roll: " << s.roll << endl;
            cout << "Name: " << s.name << endl;
            cout << "Age: " << s.age << endl;
            cout << "Math: " << s.math << endl;
            cout << "Science: " << s.science << endl;
            cout << "CS: " << s.cs << endl;
            found = true;
            break;
        }
    }
    if(!found)
        cout << "Student not found!\n";
    file.close();
}

int main() {
    int choice;
    while(true) {
        cout << "\n===== MENU =====\n";
        cout << "1. Add Student\n";
        cout << "2. View All Students\n";
        cout << "3. View One Student\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch(choice) {
            case 1: addStudent(); break;
            case 2: viewAll(); break;
            case 3: viewOne(); break;
            case 4: cout << "Exit\n"; return 0;
            default: cout << "Invalid choice!\n";
        }
    }
}
