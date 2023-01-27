#include <iostream>

using namespace std;


enum class Colors
{
    BLACK,
    WHITE,
    RED,
    GREEN,
    BLUE,
};

void printColorName(Colors color)
{
    switch (static_cast<int>(color))
    {
    case 0:
        cout << "BLACK" << endl;
        break;
    case 1:
        cout << "WHITE" << endl;
        break;
    case 2:
        cout << "RED" << endl;
        break;
    case 3:
        cout << "GREEN" << endl;
        break;
    case 4:
        cout << "BLUE" << endl;
        break;
    default:
        break;
    }
}

int main()
{
    //printColorName(Colors::WHITE);

    int x;
    cin >> x;

    switch (x)
    {
        int a; //변수선언 가능, 변수 초기화는 불가능
        int y;

        case 0:
            //int y; //case 안에서 변수 선언해도 밖에 선언한 것처럼 작동
            y = 5; //변수 초기화 가능
            break;
        case 1:
            //cout << y << endl;
        case 2:
        { 
            //블록 스코프를 사용하면 각 case 영역에 변수 선언한 것처럼 작동
            int y = 123;
            y = y - x;
            cout << y << endl;
            break;
        }

        default:
            cout << "Undefined input " << x << endl;
    }

    return 0;
}