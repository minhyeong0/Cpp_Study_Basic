#include <iostream>
#include <vector>
#include <cstdint>

int main()
{
    using namespace std;

    //자료형 별명
    typedef double distance_t;

    std::int8_t i(97);

    double my_distance;
    distance_t home2work;
    distance_t home2school;
    
    //자료형 별칭 선언 방법1
    //typedef vector<pair<string, int>> pairlist_t;

    //자료형 별칭 선언 방법2
    using pairlist_t = vector<pair<string, int>>;

    pairlist_t pairlist1;
    pairlist_t pairlist2;
    
    return 0;
}