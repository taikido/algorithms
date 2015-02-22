/*============================================================================
* Name : radix_sort.cpp
* Author: taikido
* Description: Radix Sort
* Date: Feb.20.2015
*===========================================================================*/

#include <iostream>
#include <vector>

#include "utility.h"

using namespace std;

void radixSort(int r, vector<int>& nums)
{
    int n = nums.size();
    vector<int> count(r+1, 0);
    vector<int> temp(n);

    // Count Frequencies
    for(int i=0; i<=r; i++)
        count[nums[i]+1]++;

    // Cumulative Freq
    for(int i=1; i<=r; i++)
        count[i] += count[i-1];

    // Order elements
    for(int i=0; i<n; i++)
        temp[count[nums[i]]++] = nums[i];

    // Copy to original
    for(int i=0; i<n; i++)
        nums[i] = temp[i];
}


void test()
{
    int a[] = {9, 1, 6, 5, 9, 5, 3, 0, 0, 1, 3};
    int n = sizeof(a)/sizeof(a[0]);

    vector<int> nums(a, a+n);
    cout << "Unsorted Vector: \n"; printVector(nums); cout << endl;

    int r = 10;
    radixSort(r, nums);
    cout << "*Sorted Vector: \n"; printVector(nums); cout << endl;
}

int main()
{
    test();
}