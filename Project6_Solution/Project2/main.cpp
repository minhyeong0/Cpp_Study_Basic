#include <iostream>

using namespace std;

#define NUM_STUDENTS 100000

void doSomething(int student_scores[])
{
    cout << (int)&student_scores << endl;
    cout << (int)&student_scores[0] << endl;
    cout << student_scores[0] << endl;
    cout << student_scores[1] << endl;
    cout << student_scores[2] << endl;
    cout << "Size in doSomething " << sizeof(student_scores) << endl;
}

int main()
{
    const int num_students = 20;
    //cin >> num_students;

    int student_scores[num_students] = { 1, 2, 3, 4, 5, };

    cout << (int)& student_scores << endl;
    cout << (int)student_scores << endl;
    cout << student_scores[0] << endl;
    cout << student_scores[1] << endl;
    cout << student_scores[2] << endl;
    cout << "Size in main " << sizeof(student_scores) << endl;
    
    doSomething(student_scores);

    return 0;
}