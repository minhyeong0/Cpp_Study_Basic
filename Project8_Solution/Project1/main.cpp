#include <iostream>
#include <string>
#include <vector>


using namespace std;

//Friend : name, address, age, height, weight, ...
//         print()

//struct는 데이터만 묶을때 사용 (기능도 넣을 수 있지만 권장안함),
//stuct는 접근 지정자를 붙일 수없음
//데이터와 기능도 같이 묶을 때는 class 사용

//struct Friend
class Friend
{
public: //public, private, protected
    string m_name; //옛날 맴버변수 선언 스타일
    string address_; //맴버변수 선언 구글스타일
    int _age; //요즘 맴버변수 선언 스타일
    double height;
    double weight;

    void print()
    {
        cout << m_name << " " << address_ << " " << _age << " " << height << " "
            << weight << endl;
    }
};

void print(const Friend& fr)
{
    cout << fr.m_name << " " << fr.address_ << " " << fr._age << " " << fr.height << " "
        << fr.weight << endl;
}

void print(const string& m_name, const string& address, const int& age, 
    const double& height, const double& weight)
{
    cout << m_name << " " << address << " " << age << " " << height << " "
        << weight << endl;
}

int main()
{
    //string name = "";
    //string address = "";
    //int age = 0;
    //double height = 0.0;
    //double weight = 0.0;
    //print(name ,address , age, height, weight);


    //vector<string> name_vec;
    //vector<string> addr_vec;
    //vector<int> age_vec;
    //vector<double> height_vec;
    //vector<double> weight_vec;
    //print(name_vec[0], addr_vec[0], age_vec[0], height_vec[0], weight_vec[0]);


    Friend jj{ "Jack Jack", "Uptown", 2, 30, 10 }; //인스턴스
    print(jj.m_name, jj.address_, jj._age, jj.height, jj.weight);
    print(jj);
    jj.print();
    
    vector<Friend> my_friends;
    my_friends.resize(2);

    for (auto& ele : my_friends)
        ele.print();

    return 0;
}