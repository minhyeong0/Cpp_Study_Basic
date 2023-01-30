#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;


int main()
{
    //char myString[255];
    //
    ////cin >> myString;
    //cin.getline(myString, 255);

    ////cout << myString << endl;
    //int ix = 0;
    //while (true)
    //{ 
    //    if (myString[ix] == '\0') break;
    //    cout << myString[ix] << " " << (int)myString[ix] << endl;
    //    ++ix;
    //};

    char source[] = "Copy this!";
    char dest[50];
    strcpy_s(dest, 50, source); //문자열 복사

    //strcat() : 문자열 추가
    //strcmp() : 두 문자열이 같은지 확인, 같으면 0 리턴
    if(strcmp(source, dest) == 0)
        cout << strcmp(source, dest) << endl;
    strcat(dest, source);
    
    cout << source << endl;
    cout << dest << endl;

    return 0;
}