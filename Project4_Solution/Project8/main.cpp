#include <iostream>
#include <string>
#include <limits>

using namespace std;


int main()
{
    //const char my_strs[] = "Hello, World";
    //const string my_hello{ "Hello, World" };

    //string my_ID = "123";

    //cout << my_hello << endl;


    //cout << "Your Age ? :";
    //int age;
    //cin >> age; 
    //
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    ////최대 32767(int 최대 크기) 길이의 글자 무시해라
    ////std::cin.ignore(32767, '\n');

    //cout << "Your Name ? :";
    //string name;
    ////cin >> name;
    //std::getline(std::cin, name); //한줄씩 입력받기

    //cout << name << " " << age << endl;

    string a("Hello, World");

    cout << a.length() << endl;

    return 0;
}