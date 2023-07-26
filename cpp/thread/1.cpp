#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
using std::cout, std::endl;

size_t count = 0;
std::mutex countMutex;

void add(size_t n){
    for(size_t i=0; i<n; i++){
        countMutex.lock();
        count ++;
        countMutex.unlock();
    }
}

int main(){
    auto start = std::chrono::high_resolution_clock::now();
    cout << "Single Thread Execution Start" << endl;
    add(1000000000);
    add(1000000000);
    add(1000000000);
    cout << "Single Thread Execution End" << endl;
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Result: " << count << std::endl;
    cout << "Time Taken Single Thread: " << duration.count() << " microseconds"<< endl;

    start = std::chrono::high_resolution_clock::now();
    cout << "Multi Thread Execution Start" << endl;
    std::thread t1(add, 1000000000);
    std::thread t2(add, 1000000000);
    std::thread t3(add, 1000000000);
    t1.join(); t2.join(); t3.join();
    cout << "Multi Thread Execution End" << endl;
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Result: " << count << std::endl;
    cout << "Time Taken Multi Thread: " << duration.count() << " microseconds"<< endl;
}
