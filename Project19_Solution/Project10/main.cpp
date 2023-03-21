#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Example
{
public:
    void ex1()
    {
        std::vector<int> vect;
        for (std::vector<int>::iterator itr = vect.begin(); itr != vect.end(); itr++)
            cout << *itr;

        for (auto itr = vect.begin(); itr != vect.end(); itr++)
            cout << *itr;

        for (auto itr : vect) // for (const auto& itr : vect)
            cout << itr;
    }

    void ex2()
    {
        int x = int();

        auto auto_x = x;
        const int& crx = x;

        //auto는 형추론을 할 때 const,&를 때버림
        auto auto_crx1 = crx;
        const auto& auto_crx2 = crx;

        volatile int vx = 1024;
        auto avx = vx;
        //auto는 형추론을 할 때 volatile를 때버림
        volatile auto avx = vx;
    }

    
    //template <typename T>
    //void func_ex3(T arg) //형추론할때 const, & 제거 됨
    //{}

    template <class T>
    void func_ex3(const T& arg) //const와 &를 적어줌
    {}

    void ex3()
    {
        const int& crx = 123;
        func_ex3(crx); 
    }

    void ex4()
    {
        const int c = 0;
        auto& rc = c; //reference가 const이면 형추론할때 const 붙여줌
        //rc = 123; //error
    }

    void ex5()
    {
        int i = 42;
        //오른쪽 값이 L-value이면 타입은 L-value
        auto&& ri_1 = i;
        auto&& ri_1 = 42; //r-value
    }

    void ex6()
    {
        int x = 42;
        const int* p1 = &x;
        auto p2 = p1; 
        //*p2 = 42; //error
    }

    template <typename T, typename S>
    void func_ex7(T lhs, S rhs)
    {
        auto prod1 = lhs * rhs;

        //typedef typeof(lhs* rhs) product_type; //pre-c11 'some' compilers
        typedef decltype(lhs* rhs) product_type; //자료형 추론
        product_type prod2 = lhs * rhs;
        
        decltype(lhs * rhs) prod3 = lhs * rhs;
    }

    template <typename T, typename S>
    auto func_ex8(T lhs, S rhs) -> decltype(lhs* rhs)
    {
        return lhs * rhs;
    }

    void ex7_8()
    {
        func_ex7(1.0, 345);
        func_ex8(1.2, 345);
    }

    struct S
    {
        int m_x;
        
        S()
        {
            m_x = 42;
        }
    };

    void ex9()
    {
        int x;
        const int cx = 42;
        const int& crx = x;
        const S* p = new S();

        auto a = x;
        auto b = cx;
        auto c = crx;
        auto d = p;
        auto e = p->m_x;

        //decltype : 변수가 선언된 타입 그대로 가져옴
        typedef decltype(x) x_type;
        typedef decltype(cx) cx_type; 
        typedef decltype(crx) crx_type;
        typedef decltype(p->m_x) m_x_type;

        //괄호를 붙이면 L-value에 referece를 붙여줌
        typedef decltype((x)) x_with_parens_type;
        typedef decltype((cx)) cx_with_parens_type;
        typedef decltype((crx)) crx_with_parens_type;
        typedef decltype((p->m_x)) m_x_with_parens_type;
    }

    const S foo()
    {
        return S();
    }

    const int& foobar()
    {
        return 123;
    }

    void ex10()
    {
        std::vector<int> vect = { 42, 43 };
        
        auto a = foo();
        typedef decltype(foo()) foo_type;

        auto b = foobar();
        typedef decltype(foobar()) foobar_type;

        auto itr = vect.begin();
        typedef decltype(vect.begin()) iterator_type;
        
        auto first_element = vect[0];
        decltype(vect[1]) second_element = vect[1];

    }

    void ex11()
    {
        int x = 0;
        int y = 0;
        const int cx = 42;
        const int cy = 43;
        double d1 = 3.14;
        double d2 = 2.72;

        typedef decltype (x * y) prod_xy_type;
        auto a = x * y;
        
        typedef decltype (cx * cy) prod_cxcy_type; //result is prvalue
        auto b = cx * cy;

        typedef decltype (d1 < d2 ? d1 : d2) cond_type; //result is L-value, & is added.
        auto c = d1 < d2 ? d1 : d2;

        typedef decltype (x < d2 ? x : d2) cond_type_mixed; //promotion of x to double
        auto d = x < d2 ? x : d2;

        //auto e = std::min(x, d2); //error : not same type
    }

    template <typename T, typename S>
    auto fpmin_wrong(T x, S y) -> decltype(x < y ? x : y)
    {
        return x < y ? x : y;
    }

    template <typename T, typename S>
    auto fpmin(T x, S y) ->
        typename std::remove_reference<decltype(x < y ? x : y)>::type
    {
        return x < y ? x : y;
    }

    void ex12()
    {
        int i = 42;
        double d = 45.1;

        //auto a = std::min(i, d); //error : no match overload function found
        auto a = std::min(static_cast<double>(i), d);

        int& j = i;
        typedef decltype (fpmin_wrong(d, d)) fpmin_return_type1;
        typedef decltype (fpmin_wrong(i, d)) fpmin_return_type2;
        typedef decltype (fpmin_wrong(i, i)) fpmin_return_type3;
    }

    void ex13()
    {
        std::vector<int> vect; //vect is empty
        //괄호의 내용을 실행하지 않기 때문에 문제없음, 타입만 확인
        typedef decltype(vect[0]) integer; 
    }

    template <typename R>
    class SomeFunctor
    {
    public:
        typedef R result_type;

        SomeFunctor()
        {}

        result_type operator() ()
        {
            return R();
        }
    };

    void ex14()
    {
        SomeFunctor<int> func;
        typedef decltype(func)::result_type integer; //nested type
    }

    void ex15()
    {
        auto lambda = []() {return 42; };
        decltype(lambda) lambda2(lambda);
        decltype((lambda)) lambda3(lambda);

        cout << "Lambda function" << endl;
        cout << &lambda << " " << &lambda2 << endl;
        cout << &lambda << " " << &lambda3 << endl;
    }

    void ex16()
    {
        auto lambda = [](auto x, auto y)
        {
            return x + y;
        };

        cout << lambda(1.1, 2) << " " << lambda(3, 4) << " " << lambda(4.5, 2.2) << endl;
    }
};

int main()
{
    Example example;

    return 0;
}