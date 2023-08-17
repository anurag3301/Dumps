#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <vector>
#include <algorithm>
#include <random>
using std::cout, std::endl;

std::mutex countMutex;
size_t upper_limit = 500000;
bool verbose = false;

bool single_thread_search(std::vector<size_t> vec, size_t val){
    for(size_t i=0; i<vec.size(); i++){
        if(vec[i]==val) return true;
    }
    return false;
}

bool single_multi_search(std::vector<size_t> vec, size_t val){

}

int main(){
    std::vector<size_t> vec;
    for(size_t i = 0; i<upper_limit; i++){
        vec.push_back(i);
    }
    // std::random_device rd;
    // std::mt19937 rng(rd());

    // std::shuffle(vec.begin(), vec.end(), rng);

    // std::vector<size_t> to_search;
    // for(int i=0; i<5; i++){
    //     to_search.push_back(rand()%upper_limit);
    // }

    // auto start = std::chrono::high_resolution_clock::now();
    // cout << "Single Thread Execution Start" << endl;
    // for(int i=0; i<100; i++){
    //     if(verbose)
    //         cout << "Searching: " << to_search[i] << " Result: " << (single_thread_search(vec, to_search[i])) << endl;
    //     else
    //         single_thread_search(vec, to_search[i]);
    // }
    // cout << "Single Thread Execution End" << endl;
    // auto stop = std::chrono::high_resolution_clock::now();
    // auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    // cout << "Time Taken Single Thread: " << duration.count() << " microseconds"<< endl;

    // start = std::chrono::high_resolution_clock::now();
    // cout << "Multi Thread Execution Start" << endl;
    // std::thread t1(add, 1000000000);
    // std::thread t2(add, 1000000000);
    // std::thread t3(add, 1000000000);
    // t1.join(); t2.join(); t3.join();
    // cout << "Multi Thread Execution End" << endl;
    // stop = std::chrono::high_resolution_clock::now();
    // duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    // std::cout << "Result: " << count << std::endl;
    // cout << "Time Taken Multi Thread: " << duration.count() << " microseconds"<< endl;
}
