#define UVIC_SOLUTION 1

#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <chrono>
#include <random>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstdint>
#include <queue>
#include <algorithm>

using namespace std;
using namespace std::chrono;

enum element
{
    hydrogen,
    oxygen
};

#if UVIC_SOLUTION

class barrier
{
private:
    mutex m_mutex;
    condition_variable m_stage_gate;

    int bonded_h;
    int bonded_o;
    string m_molecule;

public:
    barrier():
        bonded_h(0),
        bonded_o(0)
    {}

    bool molecule_complete()
    {
        return m_molecule.size() == 3;
    }

    void print_molecule()
    {
        cout << m_molecule;
        if (std::count(m_molecule.begin(), m_molecule.end(), 'H') != 2)
            cout << " ERROR!";
        cout << endl;

        m_molecule.clear();
    }

    void process_element(element e)
    {
        int & elem_count = e == hydrogen ? bonded_h : bonded_o;
        int elem_limit = e == hydrogen ? 2 : 1;

        unique_lock<mutex> lock(m_mutex);

        while (elem_count == elem_limit)
        {
            m_stage_gate.wait(lock);
        }

        ++elem_count;

        m_molecule += (e == hydrogen ? 'H' : 'O');

        if (molecule_complete())
        {
            print_molecule();
            bonded_h = 0;
            bonded_o = 0;
            m_stage_gate.notify_all();
        }
    }
};
#endif

int main()
{
    barrier b;

    minstd_rand r;
    uniform_int_distribution<int> u(0,2);

    minstd_rand r2;
    uniform_int_distribution<int> u2(10, 30);

    int count = 10;

    while(count--)
    {
        cout << "------------------" << endl;

        int batch_count = 100;
        while(batch_count--)
        {
            int choice = u(r);
            element e = choice == 0 ? oxygen : hydrogen;

            thread t( &barrier::process_element, &b, e );
            t.detach();
        }
        //this_thread::sleep_for(milliseconds(u2(r)));
        this_thread::sleep_for(milliseconds(500));
    }

    cout << "ending..." << endl;
    this_thread::sleep_for(milliseconds(100));
}
