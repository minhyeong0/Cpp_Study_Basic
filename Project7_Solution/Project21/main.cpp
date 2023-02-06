#include <iostream>
#include <string>

using namespace std;

//명령줄 인수 커멘트 창에서 입력하면
//인자개수, 인자값을 배열에 담아서 리턴함, 처음인자는 파일 위치임
int main(int argc, char* argv[])
{
    for (int count = 0; count < argc; ++count)
    {
        std::string argv_single = argv[count];

        if (count == 1)
        {
            int input_nubmer = std::stoi(argv_single);
            cout << input_nubmer + 1 << endl;
        }

        cout << argv_single << endl;
    }

    return 0;
}