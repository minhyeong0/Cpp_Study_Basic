#include <iostream>
#include <limits>


int main()
{
    using namespace std;
    
    //char c1(65);
    //char c2('A');

    ////c style 형변환
    //cout << (char)65 << endl;
    //cout << (int)'A' << endl;

    ////c++ style 형변환
    //cout << char(65) << endl;
    //cout << int('A') << endl;

    ////static_cast를 이용한 형변환
    //cout << static_cast<char>(65) << endl;
    //cout << static_cast<int>('A') << endl;


    //char ch(97);
    //cout << ch << endl;
    //cout << static_cast<int>(ch) << endl;
    //cout << ch << endl;

    //char c1(65);

    //cin >> c1;
    //cout << c1 << " " << static_cast<int>(c1) << endl;

    //cin >> c1;
    //cout << c1 << " " << static_cast<int>(c1) << endl;

    //cin >> c1;
    //cout << c1 << " " << static_cast<int>(c1) << endl;

    //char c1(65);

    //cout << sizeof(unsigned char) << endl;
    //cout << (int)std::numeric_limits<unsigned char>::max() << endl;
    //cout << (int)std::numeric_limits<unsigned char>::lowest() << endl;


    char c1(65);
    // \n과 endl의 차이점
    // \n은 그냥 줄바꿈이지만, endl은 줄바꿈과 동시에 버퍼의 내용 전부 출력한다
    cout << int('\n') << endl;
    cout << "This is first line\nsecond line\n";
    cout << "This is first line" << endl;
    cout << "second line" << std::flush; //줄바꿈 안하고 버퍼의 내용을 전부 출력한다

    wchar_t c; //window 용 char
    char32_t c1; //유니코드용
    return 0;
}