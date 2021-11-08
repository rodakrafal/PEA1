#include <iostream>
#include <memory>
#include <chrono>
using namespace std;
class Clock
{
public:
    Clock(){
        m_StartTimepoint = chrono::high_resolution_clock::now();
    }
    ~Clock(){
        StopClock();
    }
    int StopClock(){
        auto endTimepoint = chrono::high_resolution_clock::now();

        auto start = chrono::time_point_cast<chrono::microseconds>(m_StartTimepoint).time_since_epoch().count();
        auto end = chrono::time_point_cast<chrono::microseconds>(endTimepoint).time_since_epoch().count();

        auto duration = end - start;
        cout << duration << "us- czas trwania"<<endl;
        return duration;
    }
private:
    chrono::time_point< chrono::high_resolution_clock> m_StartTimepoint;
};