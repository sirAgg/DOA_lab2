#ifndef __SORTING_H_
#define __SORTING_H_

#include <iostream>
#include <cstring>

template <typename T>
void insert_sort(T* arr, int size)
{
    for (int current_idx = 1; current_idx < size; current_idx++)
    {
        T current_elem = arr[current_idx];

        int i;
        for (i = current_idx-1; i >= 0; i--)
        {
            if ( arr[i] < current_elem )
                break;

            else
                arr[i+1] = arr[i];
        }
        arr[i+1] = current_elem;
    }
}

template <typename T>
T* bin_search(T* arr, int size, T target)
{
    if(size < 1)
        return arr;

    if(target < arr[size/2])
        return bin_search(arr, size/2, target);
    else if(target > arr[size/2])
        return bin_search(arr+size-size/2, size/2, target);
    else
        return arr+size/2;
}

template <typename T>
void binsert_sort(T* arr, int size)
{
    for(int i = 1; i < size; i++)
    {
        T tmp = arr[i];
        T* target_pos = bin_search(arr,i,tmp);
        memmove(target_pos+1, target_pos, (arr+size-target_pos)*sizeof(T));
        // for(T* j = arr+i; j != target_pos; j--)
        //     *j = *(j-1);
        *target_pos = tmp;
    }
}


template <typename T,void (*func)(T*, int)>
T* __merge_sort_internal(T* arr, int size, int k, T* work_arr)
{
    if( size <= k )
    {
        func(arr,size);
        return arr;
    }
    else
    {
        int left_size = size/2;
        int right_size = size-left_size;

        T* left = __merge_sort_internal<T,func>( arr, left_size, k, work_arr);
        T* right = __merge_sort_internal<T,func>( arr+left_size, right_size, k, work_arr+left_size);

        T* target_arr = (left == arr) ? work_arr : arr;
        int left_idx = 0, right_idx = 0, idx = 0;

        while((left_idx < left_size) || (right_idx < right_size))
        {
            if((left[left_idx] < right[right_idx] && left_idx != left_size) || right_idx == right_size)
            {
                target_arr[idx++] = left[left_idx++];
            }
            else
            {
                target_arr[idx++] = right[right_idx++];
            }
        }

        return target_arr;
    }
}

template <typename T,void (*func)(T*, int)>
void merge_sort(T* arr, int size, int k)
{
    T* work_arr = new T[size];

    T* ret = __merge_sort_internal<T, func>(arr, size, k, work_arr);

    if (ret == work_arr)
    {
        // copy the work array to main array
        memcpy(arr, work_arr, size * sizeof(T));
    }
}

#endif // __SORTING_H_
