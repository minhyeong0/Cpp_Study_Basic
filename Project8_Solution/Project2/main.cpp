#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Date
{
//기본접근제어자는 private
public: //access specifier (public, private, protected)
    int m_month;
    int m_day;
    int m_year;

public:
    void setDate(const int &month_input, const int& day_input, const int& year_input)
    {
        m_month = month_input;
        m_day = day_input;
        m_year = year_input;
    }

    void setMonth(const int& month_input)
    {
        m_month = month_input;
    }

    const int& getDay()
    {
        return m_day;
    }
    
    void copyFrom(const Date& original)
    {
        //private로 선언된 인스턴스 변수는 같은 클래스로 부터 선언된
        //다른 인스턴스에서 접근 가능
        m_month = original.m_month;
        m_day = original.m_day;
        m_year = original.m_year;
    }
};

int main()
{
    Date today; //인스턴스
    
    today.setDate(8, 4, 2025);
    today.setMonth(10);
    cout << today.getDay() << endl;

    Date copy; //인스턴스
    copy.copyFrom(today);

    //getter, setter 쓰는 이유 : 잘못된 값 제거할려고
    copy.m_day = 123;

    return 0;
}