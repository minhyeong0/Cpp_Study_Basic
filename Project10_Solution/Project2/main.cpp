#include <iostream>
#include <vector>
#include <string>
#include "Lecture.h"


int main()
{
    using namespace std;

    Student* std1 = new Student("Jack Jack", 0);
    Student *std2 = new Student("Dash", 1);
    Student *std3 = new Student("Violet", 2);

    Teacher *teacher1 = new Teacher("Prof. Hong");
    Teacher *teacher2 = new Teacher("Prof. Good");

    //Composition Relationship
    //Lecture lec1("Introduction to Computer Programming");
    //lec1.assignTeacher(teacher1);
    //lec1.registerStudent(std1);
    //lec1.registerStudent(std2);
    //lec1.registerStudent(std3);

    //Lecture lec2("Computational Thinking");
    //lec2.assignTeacher(teacher2);
    //lec2.registerStudent(std1);



    //implement Aggregation Relationship
    Lecture lec1("Introduction to Computer Programming");
    lec1.assignTeacher(teacher1);
    lec1.registerStudent(std1);
    lec1.registerStudent(std2);
    lec1.registerStudent(std3);

    Lecture lec2("Computational Thinking");
    lec2.assignTeacher(teacher2);
    lec2.registerStudent(std1);

    //test
    {
        cout << lec1 << endl;
        cout << lec2 << endl;

        lec2.study();

        //lec1의 값이 안증가한 이유 : vector에 push_back 할때
        //주소복사가 아닌 값을 복사해서 저장하므로 증가안함
        cout << lec1 << endl;
        cout << lec2 << endl;
    }

    delete std1;
    delete std2;
    delete std3;
    delete teacher1;
    delete teacher2;

    return 0;
}