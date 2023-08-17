#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <vector>
#include <algorithm>
#include <random>
using std::cout, std::endl;

int main(){
    int num_threads = std::thread::hardware_concurrency();
    cout << num_threads << endl;
}
