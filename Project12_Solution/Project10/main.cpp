#include <iostream>

using namespace std;

class PoweredDevice
{
public:
    int m_i;

    PoweredDevice(int power)
    {
        cout << "PoweredDevice : " << power << '\n';
    }

};

class Scanner : virtual public PoweredDevice
{
public:
    Scanner(int scanner, int power)
        :PoweredDevice(power)
    {
        cout << "Scanner : " << scanner << '\n';
    }
};

class Printer : virtual public PoweredDevice
{
public:
    Printer(int printer, int power)
        :PoweredDevice(power)
    {
        cout << "Printer : " << printer << '\n';
    }
};

class Copier : public Scanner, public Printer
{
public:
    Copier(int scanner, int printer, int power)
        :Scanner(scanner, power), Printer(printer, power),
        //가상 상속
        PoweredDevice(power) //PoweredDevice 생성자를 하나로 통일
    {
        
    }
};


int main()
{
    Copier cop(1, 2, 3);

    //Scanner, Printer 클래스에 virtual 키워드 안 붙이면 
    //PoweredDevice가 생성자 2번 호출 되고 
    //Scanner::PoweredDevice::m_i와 Printer::PoweredDevice::m_i 주소가 달라짐
    //다중 상속 문제 발생함
    
    //Scanner, Printer 클래스에 virtual 키워드를 붙이고
    //PoweredDevice 생성자를 따로 호출하면
    //생성자는 한번만 호출되고
    //Scanner::PoweredDevice::m_i와 Printer::PoweredDevice::m_i 주소가 같아짐
    //다이아몬드 상속
    cout << &cop.Scanner::PoweredDevice::m_i << endl;
    cout << &cop.Printer::PoweredDevice::m_i << endl;

    return 0;
}