#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;


int main()
{
    const string filename = "my_file.txt";

    //make a file
    {
        ofstream ofs(filename);

        for (char i = 'a'; i <= 'z'; i++)
            ofs << i;
        ofs << endl;
    }

    //read the file
    //{
    //    ifstream ifs(filename);
    //    
    //    //5byte 이동하기
    //    ifs.seekg(5); //ifs.seekg(5, ios::beg);
    //    cout << (char)ifs.get() << endl;
    //    
    //    //현재위치에서 다시 5byte 이동하기
    //    ifs.seekg(5, ios::cur);
    //    cout << (char)ifs.get() << endl;

    //    //끝에서 -5byte 이동한 글자 가져오기
    //    //ifs.seekg(-5, ios::end);
    //    //cout << (char)ifs.get() << endl;

    //    //끝에 있는 글자 가져오기
    //    //ifs.seekg(0, ios::end);
    //    //cout << ifs.tellg() << endl;

    //    string str;
    //    getline(ifs, str);
    //    cout << str << endl;
    //}

    //write, read;
    {
        //fstream iofs(filename, ios::in | ios::out);
        fstream iofs(filename);

        iofs.seekg(5);
        cout << (char)iofs.get() << endl;

        iofs.seekg(5);
        iofs.put('A');
    }

    return 0;
}