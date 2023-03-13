#include <iostream>
#include <iomanip>

using namespace std;


int main()
{
    ////flag 설정 : 양수 음수 구분
    ////cout.setf(std::ios::showpos);
    //
    ////10진수 모드 해제
    ////cout.unsetf(std::ios::dec);
    ////16진수 출력
    ////cout.setf(std::ios::hex);
    ////16진수 출력
    ////cout.setf(std::ios::hex, std::ios::basefield);
    ////16진수 대문자 출력
    ////cout.setf(std::ios::uppercase);
    ////16진수 출력
    //cout << std::hex;
    ////16진수 대문자 출력
    //cout << std::uppercase;

    //cout << 108 << endl;

    ////flag 해제
    ////cout.unsetf(std::ios::showpos);
    //cout.unsetf(std::ios::hex);
    //cout << std::dec;
    //cout << 108 << endl;


    //bool타입 문자로 출력
    //cout << std::boolalpha;
    //cout << true << " " << false << endl;


    ////cout << std::defaultfloat;
    ////cout << std::fixed;
    ////cout << std::scientific << std::uppercase;
    //cout << std::showpoint;
    //cout << std::setprecision(3) << 123.456 << endl;
    //cout << std::setprecision(4) << 123.456 << endl;
    //cout << std::setprecision(5) << 123.456 << endl;
    //cout << std::setprecision(6) << 123.456 << endl;
    //cout << std::setprecision(7) << 123.456 << endl;


    cout << -12345 << endl;
    cout.fill('*');
    cout << std::setw(10) << -12345 << endl;
    cout << std::setw(10) << std::left << -12345 << endl;
    cout << std::setw(10) << std::right << -12345 << endl;
    cout << std::setw(10) << std::internal << -12345 << endl;

    return 0;
}