#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main()
{
    string my_str("abcdefg");

    //cout << my_str[0] << endl;
    //cout << my_str[3] << endl;

    //my_str[3] = 'Z';
    //cout << my_str << endl;

    //try
    //{
    //    //string에서 대괄호 연산자는 성능 때문에 예외처리 안해줌
    //    //my_str[100] = 'X';

    //    my_str.at(100) = 'X';
    //}
    //catch (std::exception& e)
    //{
    //    cout << e.what() << endl;
    //}

    ////string를 c 스타일 문자열로 변경해줌, 변경할때 끝에 \0 붙여줌
    //const char* arr = my_str.c_str();
    //const char* arr = my_str.data();

    //cout << my_str.c_str() << endl;
    //cout << (int)arr[6] << endl;
    //cout << (int)arr[7] << endl;
    
    //string를 c 스타일 문자열로 변경하기
    char buf[20];
    my_str.copy(buf, 5, 0); // \0 안넣어줌
    buf[5] = '\0';

    cout << buf << endl;

    return 0;
}