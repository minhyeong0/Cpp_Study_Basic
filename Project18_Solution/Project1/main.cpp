#include <iostream>
#include <string>
#include <iomanip> //input/output manipulators

using namespace std;


int main()
{
    //char buf[5];

    ////5글자만 받도록 제한
    //cin >> setw(5) >> buf; //abcdefghijk
    //cout << buf << endl; //a b c d \0

    ////버퍼에 남아있는 글자 가져오기
    //cin >> setw(5) >> buf;
    //cout << buf << endl; //e f g h \0

    //cin >> setw(5) >> buf;
    //cout << buf << endl; //i j k \0


    //int i;
    //float f;
    //
    ////cin으로 가져올때 빈칸 없앰
    //cin >> i >> f;
    //cout << i << " " << f << endl;


    //char ch;

    //while (cin.get(ch))
    //    cout << ch; //공백까지 읽을 때

    
    //char buff[100];
    ////한글자씩 읽고 버퍼에 저장함 \n은 버퍼에 저장 안함
    ////cin.get(buff, 5); 
    //
    ////한줄을 다 읽고 버퍼 비움, \n도 버퍼에 저장함
    //cin.getline(buff, 100);
    //
    ////gcount() : 몇글자 읽었는지 출력
    //cout << cin.gcount() << " " << buff << endl;

    ////버퍼에 남아있는 내용 읽기
    ////cin.get(buff, 5);
    //cin.getline(buff, 100);
    //cout << cin.gcount() << " " << buff << endl;

    
    ////string 입력 받기
    //string buf;
    //getline(cin, buf);
    //cout << cin.gcount() << " " << buf << endl;
        

    char buf[1024];
    //cin.ignore(2); //n글자 무시

    //버퍼에서 다음에 출력될 문자 확인
    //cout << (char)cin.peek() << endl; 
    
    cin >> buf;
    cout << buf << endl;

    //cin.unget(); ///마지막에 읽은 문자 다시 버퍼에 넣기
    cin.putback('A'); //버퍼에 원하는 글자 넣기

    cin >> buf;
    cout << buf << endl;

    return 0;
}