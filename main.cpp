#include <iostream>

#include <cstdlib>
#include <time.h>

#include "sorting.h"
#include "timer.h"

void randomize_arr(int* arr, int size)
{
    for (int i = 0; i < size; i++)
        arr[i] = rand();
}
void randomize_arr(int* arr, int size, int seed)
{
    srand(seed);
    randomize_arr(arr,size);
}

bool is_sorted(int* arr, int size)
{
    for (int i = 1; i < size; i++)
        if( arr[i-1] > arr[i] )
            return false;
    return true;
}


void test_k_values( void (*func)(int*, int, int), int test_size, int seed )
{
    int* arr = new int[test_size];

    for(int k = 1; k <= 1000; k++)
    {
        randomize_arr(arr,test_size, seed);
        std::string s = std::to_string(k) + "\t";
        {
            Timer t(s.c_str());
            func(arr,test_size,k);
        }
    }
    delete[] arr;
}


int main(int argc, char *argv[])
{
    int test_size = 1000000;
    int seed = time(NULL);

    test_k_values(merge_sort<int,insert_sort>,test_size, seed);
    test_k_values(merge_sort<int,binsert_sort>,test_size, seed);

    return 0;
}
