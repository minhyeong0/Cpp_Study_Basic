#include "Calc.h"

using namespace std;



int main()
{
    //Calc cal(10);
    //cal.add(10);
    //cal.sub(1);
    //cal.mult(2);
    //cal.print();


    //Calc& temp1 = cal.add(10);
    //Calc& temp2 = temp1.sub(1);
    //Calc& temp3 = temp2.mult(2);
    //temp3.print();


    //member function chaining 기법 : 위의 코드를 아래처럼 생략 가능
    //cal.add(10).sub(1).mult(2).print();
    Calc(10).add(10).sub(1).mult(2).print();



    return 0;
}