/*============================================================================
* Name : msd_sort.cpp
* Author: taikido
* Description: MSD and LSD Radix Sort
* Date: Feb.20.2015
*===========================================================================*/

#include <iostream>
#include <vector>
#include <cmath>

#include "utility.h"

using namespace std;

int getDigit(int num, int d)
{
    int digit = (num/(int(pow(10, d)))) % 10;
    // printf("Num: %d, d: %d, digit: %d \n", num, d, digit);
    return digit;
}


void radixSort(int r, int d, vector<int>& nums)
{
    int n = nums.size();
    vector<int> temp(n);
    vector<int> count(r+1, 0);

    // Freq
    for(int i=0; i<n; i++)
        count[getDigit(nums[i], d)+1]++;

    // Cumulative
    for(int i=1; i<=r; i++)
        count[i] += count[i-1];

    // Order
    for(int i=0; i<n; i++)
        temp[count[getDigit(nums[i], d)]++] = nums[i];


    // Copy
    for(int i=0; i<n; i++)
        nums[i] = temp[i];

}


void lsdSort(vector<int> nums, int num_digits)
{
    int r = 10;
    for(int d=0; d<num_digits; d++)
    {
        printf("Result after sorting by Digit [%d] \n", d);
        radixSort(r, d, nums);
        printVector(nums);
    }
}

void msdSort(vector<int> nums, int num_digits)
{
    int r = 10;
    for(int d=num_digits-1; d>=0; d--)
    {
        printf("Result after sorting by Digit [%d] \n", d);
        radixSort(r, d, nums);
        printVector(nums);
    }
}


void test()
{
    int a[] = {920, 543, 671, 234};
    int n = sizeof(a)/sizeof(a[0]);
    vector<int> nums(a, a+n);

    int num_digits = 3;
    // lsdSort(nums, num_digits);
    msdSort(nums, num_digits);

    // getDigit(920, 2);

}

int main()
{
    test();
}