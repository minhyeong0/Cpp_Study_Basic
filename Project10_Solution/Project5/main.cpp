#include <iostream>
#include <initializer_list>
#include <cassert>
#include <vector>
#include <array>


using namespace std;

class IntArray
{
private:
    int m_length = 0;
    int* m_data = nullptr;
    const int one_digit = 1;

public:
    IntArray(const unsigned int& len_in)
        : m_length(len_in)
    {
        initialize(m_length);
    }

    IntArray(const initializer_list<int>& list)
        : IntArray(list.size())
    {
        int count = 0;
        for (auto& element : list)
        {
            m_data[count] = element;
            count++;
        }
    }

    ~IntArray()
    {
        delete[] m_data;
    }

    void initialize(const unsigned int& len_in)
    {
        m_data = new int[len_in];
    }

    void reset()
    {
        delete[] m_data;
        m_data = nullptr;
        m_length = 0;
    }

    void resize(const unsigned int& len_in)
    {
        IntArray temp(len_in);

        copyAll(temp, *this);

        resetAndAssignment(temp);
    }

    void insertBefore(const int& value, const int& ix)
    {
        IntArray temp(m_length + one_digit);

        copyOriginalFromZeroToIx(temp, *this, ix - one_digit);
        temp.setValue(value, ix);
        copyOriginalFromIXToEnd(temp, *this, ix + one_digit, ix);

        resetAndAssignment(temp);
    }

    void remove(const int& ix)
    {
        IntArray temp(m_length - one_digit);

        copyOriginalFromZeroToIx(temp, *this, ix - one_digit);
        copyOriginalFromIXToEnd(temp, *this, ix, ix + one_digit);

        resetAndAssignment(temp);
    }

    void push_back(const int& value)
    {
        IntArray temp(m_length + one_digit);

        copyAll(temp, *this);
        int temp_end_index = temp.getLength() - one_digit;
        temp.setValue(value, temp_end_index);

        resetAndAssignment(temp);
    }

    void copyAll(IntArray& target, const IntArray& orginal)
    {
        for (int i = 0; i < target.m_length; ++i)
        {
            target.m_data[i] = orginal.m_data[i];
        }
    }

    void copyOriginalFromZeroToIx(IntArray& target, IntArray& original, const unsigned int& to_ix)
    {
        // TODO: 방어적 프로그래밍 - to_ix가 배열 길이를 벗어날 때.
        for (int i = 0; i < to_ix + one_digit; ++i)
        {
            target.m_data[i] = original.m_data[i];
        }
    }

    void copyOriginalFromIXToEnd(IntArray& target, IntArray& original, const unsigned int& from_ix_target, const unsigned int& from_ix_original)
    {
        // TODO: 방어적 프로그래밍 - to_ix가 배열 길이를 벗어날 때.
        unsigned int count = from_ix_original;
        for (int i = from_ix_target; i < target.getLength(); ++i)
        {
            target.m_data[i] = original.m_data[count];
            count++;
        }
    }

    void resetAndAssignment(IntArray& intarray)
    {
        this->reset();
        *this = intarray;
    }

    int getLength()
    {
        return m_length;
    }

    void setValue(const int& value, const int& ix)
    {
        //TODO: 방어적 프로그래밍 - 인덱스가 배열 범위를 벗어날 때
        m_data[ix] = value;
    }

    IntArray& operator = (IntArray& source)
    {
        this->m_length = source.m_length;
        this->m_data = new int[this->m_length];
        copyAll(*this, source);
    }

    friend ostream& operator << (ostream& out, IntArray& intarray)
    {
        for (int i = 0; i < intarray.getLength(); ++i)
        {
            out << intarray.m_data[i] << " ";
        }
        return out;
    }
};

int main()
{
    //컨테이너 클래스
    std::vector<int> int_vec;
    std::array<int, 10> int_arr;

    return 0;
}