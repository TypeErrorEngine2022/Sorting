#pragma once

#include <vector>

template <typename T>
void merge(std::vector<T>& vec, int left, int mid, int right)
{
    std::vector<T> tmp1;
    std::vector<T> tmp2;

    for (int i = left; i <= mid; ++i)
    {
        tmp1.push_back(vec[i]);
    }
    for (int i = mid + 1; i <= right; ++i)
    {
        tmp2.push_back(vec[i]);
    }

    int start = left;
    std::size_t ptr1 = 0, ptr2 = 0;

    while (ptr1 < tmp1.size() && ptr2 < tmp2.size())
    {
        vec[start++] = tmp1[ptr1] <= tmp2[ptr2] ? tmp1[ptr1++] : tmp2[ptr2++];
    }
    while (ptr1 < tmp1.size())
    {
        vec[start++] = tmp1[ptr1++];
    }
    while (ptr2 < tmp2.size())
    {
        vec[start++] = tmp2[ptr2++];
    }
}

template <typename T>
void mergesort(std::vector<T>& vec, int left, int right)
{
    if (left >= right) return;
    
    int mid = left + (right - left) / 2;
    mergesort<T>(vec, left, mid);
    mergesort<T>(vec, mid + 1, right);
    merge<T>(vec, left, mid, right);   
}

