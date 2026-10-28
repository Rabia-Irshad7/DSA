#include <iostream>
#include <string>
using namespace std;

int main() {
    const int numStudents = 5;
    string names[numStudents] = {"Ali", "Hiba", "Asma", "Zain", "Faisal"};
    int numCourses[numStudents] = {5, 4, 3, 3, 5};
    float **grades = new float*[numStudents];

    grades[0] = new float[5]{3.66f, 3.33f, 4.0f, 3.0f, 2.66f};   
    grades[1] = new float[4]{3.33f, 3.0f,  3.66f, 3.0f};         
    grades[2] = new float[3]{4.0f,  3.66f, 2.66f};               
    grades[3] = new float[3]{2.66f, 2.33f, 4.0f};                
    grades[4] = new float[5]{3.33f, 3.66f, 4.0f, 3.0f, 3.33f};   

    const float creditHours = 3.0f;

    cout << "Student\t\tCredits Taken\tGPA\n";
    cout << "---------------------------------------------\n";

    for (int i = 0; i < numStudents; i++) 
    {
        float totalPoints = 0;
        float totalCredits = 0;
        for (int j = 0; j < numCourses[i]; j++) 
        {
            totalPoints += grades[i][j] * creditHours;
            totalCredits += creditHours;
        }
        float gpa = totalPoints / totalCredits;
        cout << names[i] << "\t\t" << totalCredits << "\t\t" << gpa << endl;
    }
    for (int i = 0; i < numStudents; i++)
    {
        delete grades[i];
    }
    delete[] grades;

    return 0;
}