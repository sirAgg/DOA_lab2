#include <chrono>
#include <iostream>

#define TIME_FUNC(func) {Timer __timer__(#func); func;}
#define TIME_FUNC_N(func,name) {Timer __timer__(name); func;}

struct Timer
{
    Timer(const char* name_)
    {
        name = name_;
        start_time = std::chrono::high_resolution_clock::now();
    }
    ~Timer()
    {
        stop();
    }
    void stop()
    {
        if(!stopped)
        {
            auto stop_time = std::chrono::high_resolution_clock::now();
            auto start = std::chrono::time_point_cast<std::chrono::nanoseconds>(start_time);
            auto end = std::chrono::time_point_cast<std::chrono::nanoseconds>(stop_time);
            std::cout << name << " took: " << (float)((end-start).count())/1000000.0f << "ms" << std::endl;
            stopped = true;
        }
    }
private:
    const char* name;
    bool stopped = false;
    std::chrono::high_resolution_clock::time_point start_time;
};
