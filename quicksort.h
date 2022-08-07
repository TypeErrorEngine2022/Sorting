#pragma once

#include <vector>
#include <algorithm>

#include "helper.h"


template <typename T>
int Partition(std::vector<T>& vec, int start, int end)
{
    T pivot = vec[end];
    int pIndex = start;

    //loop in [start,end)
    for (std::size_t i = start; i < end; i++)
    {
        if (vec[i] <= pivot)
        {
            std::swap(vec[i], vec[pIndex]);
            ++pIndex;
        }
    }
    std::swap(vec[pIndex], vec[end]);

    return pIndex;
}


/**
 * @brief Make three partition, [start, pIndex - 1], [pIndex] and [pIndex + 1, end], 
 * elements on the left of pInex are smaller than pivot, elements on the right of pIndex are larger than pivot
 * @tparam T 
 * @param vec 
 * @param start 
 * @param end 
 * @return std::size_t : the pivot index
 */
template <typename T>
int RandomizedPartition(std::vector<T>& vec, int start, int end)
{
    int pIndex = randNum(start, end);
    std::swap(vec[pIndex], vec[end]);
    return Partition(vec, start, end);
}

template <typename T>
void quicksort(std::vector<T>& vec, int start, int end)
{
    //Start can be greater than end when pivot is at index 0,
    //and end = pivot - 1 => -1
    //Since negative number may come out, DO NOT USE STD::SIZE_T
    if (start >= end) return;

    int pIndex = RandomizedPartition<T>(vec, start, end);
    
    //pIndex contains pivot that is at right position
    //so do not include pIndex
    quicksort<T>(vec, start, pIndex - 1);
    quicksort<T>(vec, pIndex + 1, end);
}
