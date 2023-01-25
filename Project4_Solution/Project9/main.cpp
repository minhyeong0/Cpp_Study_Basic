#include <iostream>
#include <typeinfo>
#include <string>

enum Color
{
    COLOR_BLACK = -3, //1씩 증가함
    COLOR_RED, //-2
    COLOR_BLUE = 5,
    COLOR_GREEN = 5,
    COLOR_SKYBLUE, //6
    
    //열거형 속성은 전역변수처럼 작동하므로 다른 enum에서 같은 속성 이름 있으면 에러 발생
    //BLUE, 
};

enum Feeling
{
    HAPPY, //기본할당
    JOY,
    TIRED,
    //BLUE,
};

int main()
{
    using namespace std;

    //if (COLOR_BLUE == COLOR_GREEN)
    //    cout << "Equal" << endl;

    //Color my_color = COLOR_RED;
    //cout << my_color << " " << COLOR_RED << endl;

    //int color_id = COLOR_BLACK;
    ////my_color = color_id; //열거형 변수에 int 할당 불가능
    //
    //my_color = static_cast<Color>(-3);
    //cout << color_id << endl;

    ////cin >> my_color; //cin으로 열거형 상수에 입력 받기 불가능

    ////우회방법
    //int in_number;
    //cin >> in_number;
    //if (in_number == static_cast<Color>(-3)) my_color = static_cast<Color>(-3);

    string str_input;
    getline(cin, str_input);

    //권장안함 (오타, 대소문자 구분 등등 ...)
    if (str_input == "COLOR_BLACK") str_input = static_cast<Color>(-3);
    return 0;
}