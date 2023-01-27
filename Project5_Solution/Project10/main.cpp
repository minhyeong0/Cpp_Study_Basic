#include <iostream>

using namespace std;


int getInt()
{
    while (true)
    {
        cout << "Enter an integer numbers : ";
        int x;
        cin >> x;

        if (std::cin.fail()) //입력 실패 시
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n'); //버퍼 비우기
            cout << "Invaild operator, please try again" << endl;
        }
        else
        {
            std::cin.ignore(32767, '\n'); //버퍼 비우기
            return x;
        }
    }
}

char getOperator()
{
    while (true)
    {
        cout << "Enter an operator (+, -) : ";
        char op;
        cin >> op;
        std::cin.ignore(32767, '\n'); //버퍼 비우기
        
        if (op == '+' || op == '-')
            return op;
        else 
            cout << "Invaild operator, please try again" << endl;
    }
}

void printResult(int x, char op, int y)
{
    if (op == '+') cout << x + y << endl;
    else if (op == '-') cout << x - y << endl;
    else
    {
        cout << "Invaild operator" << endl;
    }
}

int main()
{
    int x = getInt();
    char op = getOperator();
    int y = getInt();
    printResult(x, op, y);
    return 0;
}