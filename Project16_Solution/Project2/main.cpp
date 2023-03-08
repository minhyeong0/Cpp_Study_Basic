#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>

using namespace std;


int main()
{
    map<int, char> container;
    for (int i = 0; i < 10; ++i)
        container.insert(make_pair(i, char(i + 65)));

    //vector, list, set을 동일한 방법으로 출력 가능
    map <int, char>::const_iterator itr;
    itr = container.begin();

    while (itr != container.end())
    {
        //cout << *itr << " ";
        cout << itr->first << " " << itr->second << " ";
        ++itr;
    }
    cout << endl;

    for (auto itr = container.begin(); itr != container.end(); ++itr)
    {
        //cout << *itr << " ";
        cout << itr->first << " " << itr->second << " ";
    }
    cout << endl;

    return 0;
}