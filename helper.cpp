#include "helper.h"
#include "mergesort.h"
#include "quicksort.h"
#include "heapsort.h"

int randNum(int range_from, int range_to){
    static std::random_device r1; //static: ensure only one seed in runtime
    static std::default_random_engine reng(r1()); //seed the random engine
    std::uniform_int_distribution<> distr(range_from, range_to); //initialize the range for the distribution
    return distr(reng); //transform the random unsigned int generated by reng into an int
}

std::chrono::nanoseconds timeTrial(std::size_t size){
    std::vector<int> vec1;
    vec1.reserve(size);
    for (std::size_t i = 0; i < size; ++i)
    {
        vec1[i] = randNum(0, INT_MAX);
    }
    auto start  = std::chrono::high_resolution_clock::now();
    heapsort<int>(vec1);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::nanoseconds duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    return duration;
}