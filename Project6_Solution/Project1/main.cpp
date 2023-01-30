#include <iostream>

using namespace std;

struct Rectangle
{
    int length;
    int width;
};

enum StudentName
{
    JACKJACK,     //0
    DASH,         //1
    VIOLET,       //2
    NUM_STUDENTS, //3
};

int main()
{
    //int student_scores[5];

    ////cout << sizeof(one_student_score) << endl;
    ////cout << sizeof(student_scores) << endl;
    //
    //student_scores[0] = 100;
    //student_scores[1] = 80;
    //student_scores[2] = 90;
    //student_scores[3] = 50;
    //student_scores[4] = 0;

    //cout << student_scores[0] << endl;
    //cout << student_scores[1] << endl;
    //cout << student_scores[2] << endl;
    //cout << student_scores[3] << endl;
    //cout << student_scores[4] << endl;


    //cout << sizeof(Rectangle) << endl;
    //Rectangle rect_arr[10];
    //cout << sizeof(rect_arr) << endl;

    //rect_arr[0].length = 1;
    //rect_arr[0].width = 2;
    
    //int my_array[]{ 1, 2, 3, 4, 5 };
    //int my_array[] = { 1, 2, 3, 4, 5 };

    //cout << my_array[JACKJACK] << endl;
    //cout << my_array[DASH] << endl;
    //cout << my_array[VIOLET] << endl;
    //cout << my_array[3] << endl;
    //cout << my_array[4] << endl;

    //int student_scores[NUM_STUDENTS];
    //student_scores[JACKJACK] = 0;
    //student_scores[DASH] = 100;
    //student_scores[VIOLET] = 1;

    const int num_students = 20;
    //cin >> num_students; 

    //브래킷 방식 배열은 컴파일 타임에 배열의 크기가 할당되어야 하므로
    //런타임 타임에 배열의 크기 할당 불가능
    int student_scores[num_students]; 
    return 0;
}