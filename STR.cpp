#include <iostream>
#include <fstream>  // For file input/output
using namespace std;

// Define a struct for student data
struct Student {
    int id;
    char name[50];
    float score;
};

int main() {
    const int MAX_STUDENTS = 100; // Maximum records
    Student students[MAX_STUDENTS]; // Array to store student records
    int count = 0; // Number of students read

    // Open the file for reading
    ifstream file("students.txt");
    if (!file) {
        cerr << "Error opening file.\n";
        return 1;
    }

    // Read data from file into array
    while (file >> students[count].id >> students[count].name >> students[count].score) {
        count++;
        if (count >= MAX_STUDENTS) break;  // Prevent overflow
    }

    file.close(); // Close the file

    // Display student records
    cout << "Student Records:\n";
    for (int i = 0; i < count; i++) {
        cout << "ID: " << students[i].id << ", Name: " << students[i].name
            << ", Score: " << students[i].score << endl;
    }

    return 0;
}
