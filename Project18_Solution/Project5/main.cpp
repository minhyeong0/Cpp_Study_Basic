#include <iostream>
#include <regex>
#include <string>

using namespace std;


int main()
{
    //regex re("\\d"); //한글자가 숫자인지 판별
    //regex re("\\d*"); //입력을 안받거나 한개 이상의 숫자인지 판별
    //regex re("\\d+"); //한개 이상의 글자가 숫자인지 판별
    //regex re("[ab]"); //a, b 만 가능
    //regex re("[[:digit:]]{3}"); //세자리 숫자인지 판별
    //regex re("[A-Z]+"); //대문자인지 판별
    //regex re("[A-Z]{1,5}"); //최소 한글자 최대 5글자의 대문자인지 판별
    
    //0~9까지 한글자를 입력받고 -가 있어도 되고 없어도 되고
    //0~9까지 최소 1글자에서 최대 4글자를 입력받는지 판별
    regex re("([0-9]{1})([-]?)([0-9]{1,4})"); 
    
    string str;

    while (true)
    {
        getline(cin, str);

        if (std::regex_match(str, re))
            cout << "Match" << endl;
        else
            cout << "No match" << endl;

        //print matches
        {
            auto begin = std::sregex_iterator(str.begin(), str.end(), re);
            auto end = std::sregex_iterator();
            for (auto itr = begin; itr != end; ++itr)
            {
                std::smatch match = *itr;
                cout << match.str() << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}