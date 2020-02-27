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

int main(int argc, char *argv[])
{
    srand(time(NULL));

    int test_size = 100000;
    int seed = 42;
    int k_value = 50;
    int* arr = new int[test_size];

    randomize_arr(arr,test_size, seed);
    {
        Timer t("binsert-sort");
        binsert_sort(arr,test_size);
    }
    if(is_sorted(arr, test_size)) std::cout << "Is sorted\n";
    else std::cout << "Not sorted\n";

    randomize_arr(arr,test_size, seed);
    {
        Timer t("insert-sort");
        insert_sort(arr,test_size);
    }
    if(is_sorted(arr, test_size)) std::cout << "Is sorted\n";
    else std::cout << "Not sorted\n";

    randomize_arr(arr,test_size, seed);
    {
        Timer t("A-sort");
        merge_sort<int,insert_sort>(arr,test_size,k_value);
    }
    if(is_sorted(arr, test_size)) std::cout << "Is sorted\n";
    else std::cout << "Not sorted\n";

    randomize_arr(arr,test_size, seed);
    {
        Timer t("B-sort");
        merge_sort<int,binsert_sort>(arr,test_size,k_value);
    }
    if(is_sorted(arr, test_size)) std::cout << "Is sorted\n";
    else std::cout << "Not sorted\n";
    // int arr[] = {1,2,4,7,8};
    // std::cout << bin_search(arr,sizeof(arr)/sizeof(*arr),4) - arr << std::endl;


    return 0;
}
