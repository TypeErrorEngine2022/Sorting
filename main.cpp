#include <time.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <string>

#include "mergesort.h"
#include "quicksort.h"
#include "helper.h"

template <typename T>
bool checkIncreasing(std::vector<T> vec)
{
    if (vec.empty()) return true;

    T prev = vec[0];
    for (std::size_t i = 1; i < vec.size(); ++i)
    {
        T el = vec[i];
        if (! (el >= prev))
        {
            return false;
        }
        prev = el;
    }

    return true;
}


int main()
{
    /*srand(time(NULL));

    std::vector<int> vec1;
    std::vector<int> vec2;
    std::vector<int> vec3;

    for (int i = 0; i < 10; ++i)
    {
        vec1.push_back(rand());
    }

    for (int i = 0; i < 100; ++i)
    {
        vec2.push_back(rand());
    }

    for (int i = 0; i < 1000; ++i)
    {
        vec3.push_back(rand());
    }

    std::cout << "Vec1:\n";
    for (auto& el1: vec1)
    {
        std::cout << el1 << " ";
    }
    std::cout << "\n--------------------------------------------------------\n";
    std::cout << "Vec2:\n";
    for (auto& el2: vec2)
    {
        std::cout << el2 << " ";
    }
    std::cout << "\n--------------------------------------------------------\n";
    /*std::cout << "Vec3:\n";
    for (auto& el3: vec3)
    {
        std::cout << el3 << " ";
    }
    std::cout << "\n--------------------------------------------------------\n";

    quicksort<int>(vec1, 0, vec1.size() - 1);
    quicksort<int>(vec2, 0, vec2.size() - 1);
    //mergesort<int>(vec3, 0, vec3.size() - 1);

    std::cout << "After sorting:\n";

    std::cout << "Vec1:\n";
    for (auto& el1: vec1)
    {
        std::cout << el1 << " ";
    }
    std::cout << "\n";
    std::string state = checkIncreasing<int>(vec1) ? "Success" : "Fail";
    std::cout << state << "\n";
    std::cout << "\n--------------------------------------------------------\n";
    std::cout << "Vec2:\n";
    for (auto& el2: vec2)
    {
        std::cout << el2 << " ";
    }
    std::cout << "\n";
    state = checkIncreasing<int>(vec2) ? "Success" : "Fail";
    std::cout << state << "\n";
    std::cout << "\n--------------------------------------------------------\n";
    /*std::cout << "Vec3:\n";
    for (auto& el3: vec3)
    {
        std::cout << el3 << " ";
    }
    std::cout << "\n--------------------------------------------------------\n";*/


    std::size_t size = 25;
    std::chrono::nanoseconds prev_duration = timeTrial(size);
    printElement("Size", 10);
    printElement("Time", 10);
    printElement("Ratio", 10);
    std::cout << "\n";
    for (std::size_t i = 0; i < 20 ; i++){
        size *= 2;
        std::chrono::nanoseconds duration = timeTrial(size);
        printElement(size, 10);
        printElement(duration.count(), 10);
        printElement(static_cast<double>(duration.count()) / prev_duration.count() , 10);
        std::cout << "\n";
        prev_duration = duration;
    }
    return 0;
}