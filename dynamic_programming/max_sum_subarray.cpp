#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>

using namespace std;


void printVector(vector<int> v)
{
    for(size_t i=0; i<v.size(); i++)
        cout << v[i] << "\t";

    cout << endl;
}

vector<int> c; // cache for max_sum

// Avoid overflow
long max(long a, long b)
{
    return a > b ? a : b;
}

int num_calls = 0;

// Handles only positive numbers
/*
int maxSum(vector<int> a, int n, int max_num)
{
    num_calls++;
    if (n < 0) return max_num;

    if (a[n] > 0){
        max_num = a[n] + max_num;
        return maxSum(a, n-1, max_num);
    }

    else return max(max_num, maxSum(a, n-1, 0));
}
*/

// Handles Negative & Positive numbers
long maxSum(vector<int> a, int n, long max_num)
{
    num_calls++;
    if (n < 0) return max_num;

    max_num = max(a[n], a[n] + max_num);
    return max(max_num, maxSum(a, n-1, max_num));

}

void test()
{
    //int a[] = {7, 3, 5, 20, 21, -5, -99, 100};
    int a[] = {5, 200, 7, 3, 5, 20, 21, -5, -99, 100};
//  int a[] = {-1, -2, -3, -4}; // *All negative numbers
//  int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
//  int a[] = {-5, 7, 3, 100};
    int n = sizeof(a)/sizeof(a[0]);

    c.assign(a, a+n);

    printVector(c);
    int max_num = INT_MIN;

    cout << "max_num: " << maxSum(c, n-1, max_num) << endl;

//  printf("num of function calls: %d \n\n", num_calls);

}

int main() {
    test();
    return 0;
}
