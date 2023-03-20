#include <chrono>
#include <iostream>
#include <mutex>
#include <random>
#include <thread>
#include <utility>
#include <vector>
#include <atomic>
#include <future>
#include <numeric> //std::inner_product
#include <execution> //parallel execution

using namespace std;

mutex mtx;

void dotProductNative(const vector<int>& v0, const vector<int>& v1,
    const unsigned i_start, const unsigned i_end, unsigned long long& sum)
{
    for (unsigned i = i_start; i < i_end; ++i)
        sum += v0[i] * v1[i];
}

void dotProductThreadDivideConquer(const vector<int>& v0, const vector<int>& v1,
    const unsigned i_start, const unsigned i_end, int& sum)
{
    for (unsigned i = i_start; i < i_end; ++i)
        sum += v0[i] * v1[i];
}

void dotProductAtomicDivideConquer(const vector<int>& v0, const vector<int>& v1,
    const unsigned i_start, const unsigned i_end, atomic<unsigned long long>& sum)
{
    int prefix_sum = 0;
    for (unsigned i = i_start; i < i_end; ++i)
        prefix_sum += v0[i] * v1[i];
    sum += prefix_sum;
}


int main()
{
    /*
        v0 = {1, 2, 3}
        v1 = {4, 5, 6}
        v0_dot_v1 = 1*4 + 2*5 + 3*6;
    */

    const long long n_data = 100'000'000;
    const unsigned n_threads = 4;

    //initalize vectors
    vector<int> v0, v1;
    v0.reserve(n_data);
    v1.reserve(n_data);

    random_device seed;
    mt19937 engine(seed());

    uniform_int_distribution<> uniformDist(1, 10);

    for (long long i = 0; i < n_data; ++i)
    {
        v0.push_back(uniformDist(engine));
        v1.push_back(uniformDist(engine));
    }

    cout << "std::inner_product" << endl;
    {
        const auto sta = chrono::steady_clock::now();

        //                                  개수가 같으므로 end필요 X, unsigned long long
        const auto sum = std::inner_product(v0.begin(), v0.end(), v1.begin(), 0ull);

        const chrono::duration<double> dur = chrono::steady_clock::now() - sta;
        cout << dur.count() << endl;
        cout << sum << endl; //백터 내적 결과값
        cout << endl;
    }

    cout << "Native" << endl;
    {
        const auto sta = chrono::steady_clock::now();
        unsigned long long sum = 0;

        vector<thread> threads;
        threads.resize(n_threads);
        const unsigned n_per_thread = n_data / n_threads;
        for (unsigned t = 0; t < n_threads; ++t)
        {
            threads[t] = std::thread(dotProductNative, std::ref(v0), std::ref(v1),
                t * n_per_thread, (t + 1) * n_per_thread, std::ref(sum));
        }

        for (unsigned t = 0; t < n_threads; ++t)
            threads[t].join();

        const chrono::duration<double> dur = chrono::steady_clock::now() - sta;
        cout << dur.count() << endl;
        cout << sum << endl;
        cout << endl;
    }

    cout << "ThreadDivideConquer" << endl;
    {
        const auto sta = chrono::steady_clock::now();
        unsigned long long sum = 0;

        vector<thread> threads;
        threads.resize(n_threads);
        const unsigned n_per_thread = n_data / n_threads;

        vector<int> sums;
        sums.resize(n_per_thread);
        int idx = 0;
        for (unsigned t = 0; t < n_threads; ++t)
        {
            threads[t] = std::thread(dotProductThreadDivideConquer, std::ref(v0), std::ref(v1),
                t * n_per_thread, (t + 1) * n_per_thread, std::ref(sums[idx++]));
        }

        for (unsigned t = 0; t < n_threads; ++t)
            threads[t].join();

        for (unsigned i = 0; i < sums.size(); ++i)
            sum += sums[i];

        const chrono::duration<double> dur = chrono::steady_clock::now() - sta;
        cout << dur.count() << endl;
        cout << sum << endl;
        cout << endl;
    }

    cout << "AtomicDivideConquer" << endl;
    {
        const auto sta = chrono::steady_clock::now();
        //여러쓰레드가 동시에 접근할때 레이스 컨디션 방지
        atomic<unsigned long long> sum = 0;

        vector<thread> threads;
        threads.resize(n_threads);
        const unsigned n_per_thread = n_data / n_threads;

        for (unsigned t = 0; t < n_threads; ++t)
        {
            threads[t] = std::thread(dotProductAtomicDivideConquer, std::ref(v0), std::ref(v1),
                t * n_per_thread, (t + 1) * n_per_thread, std::ref(sum));
        }

        for (unsigned t = 0; t < n_threads; ++t)
            threads[t].join();

        const chrono::duration<double> dur = chrono::steady_clock::now() - sta;
        cout << dur.count() << endl;
        cout << sum << endl;
        cout << endl;
    }

    return 0;
}