#include <iostream>
#include <fstream>

using namespace std;

class Point
{
private:
    double m_x, m_y, m_z;

public:
    Point(double x = 0.0, double y = 0.0, double z = 0.0)
        :m_x(x), m_y(y), m_z(z)
    {}

    double getX() { return m_x; }
    double getY() { return m_y; }
    double getZ() { return m_z; }

    //void print()
    //{
    //    cout << m_x << " " << m_y << " " << m_z;
    //}
    

    //입출력 연산자 오버로딩 (파일 스트림에서도 작동)
    //첫번째 인자가 output stream이므로 맴버함수로 입출력 연산자 오버로딩 불가능
    friend std::ostream& operator << (std::ostream& out, const Point& point)
    {
        out << "(" << point.m_x << " " << point.m_y << " " << point.m_z << ")";
        return out;
    }

    friend std::istream& operator >> (std::istream& in, Point& point)
    {
        in >> point.m_x >> point.m_y >> point.m_z;
        return in;
    }
};


int main()
{

    //Point p1(0.0, 0.1, 0.2), p2(3.4, 1.5, 2.0);
    //p1.print();
    //cout << " ";
    //p2.print();
    //cout << endl;
    
    ofstream of("out.txt");

    Point p1, p2;
    cin >> p1 >> p2;
    
    cout << p1 << " " << p2 << endl;
    
    of << p1 << " " << p2 << endl; //파일 출력
    of.close();

    return 0;
}