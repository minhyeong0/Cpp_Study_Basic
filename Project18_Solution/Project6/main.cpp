#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;


int main()
{
    //writting
    if (true)
    {
        ofstream ofs("my_first_file.dat"); //ios::app, ios::binary
        //ofs.open("my_first_file.dat");
        
        if (!ofs)
        {
            cerr << "couldn't open file" << endl;
            exit(1);
        }

        //ASCII 방식
        ////파일 쓰기
        //ofs << "Line 1" << endl;
        //ofs << "Line 2" << endl;


        //binary 방식
        //const unsigned num_data = 10;
        //ofs.write((char*)&num_data, sizeof(num_data));

        //for (int i = 0; i < num_data; i++)
        //    ofs.write((char*)&i, sizeof(i));


        //sstream에 담아서 쓰기
        stringstream ss;
        ss << "Line 1" << endl;
        ss << "Line 2" << endl;
        string str = ss.str();

        unsigned str_length = str.size();
        ofs.write((char*)&str_length, sizeof(str_length));
        ofs.write(str.c_str(), str_length);
        ofs.close();
    }

    if (true)
    {
        ifstream ifs("my_first_file.dat");

        if (!ifs)
        {
            cerr << "Cannot open file" << endl;
            exit(1);
        }

        //ASCII 방식
        //while (ifs)
        //{
        //    std::string str;
        //    getline(ifs, str);
        //    cout << str << endl;
        //}


        //binary 방식
        //unsigned int num_data = 0;
        //ifs.read((char*)&num_data, sizeof(num_data));

        //for (int i = 0; i < num_data; i++)
        //{
        //    int num;
        //    ifs.read((char*)&num, sizeof(num));
        //    cout << num << endl;
        //}

        //sstream에 담아서 읽기
        unsigned str_len = 0;
        ifs.read((char*)&str_len, sizeof(str_len));

        string str;
        str.resize(str_len);
        ifs.read(&str[0], str_len);

        cout << str << endl;
        ifs.close();
    }

    return 0;
}