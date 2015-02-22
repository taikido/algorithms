/*
Source: http://www.quora.com/Are-there-any-good-resources-or-tutorials-for-dynamic-programming-besides-the-TopCoder-tutorial

Added: Sun.Feb.9.2015

*/


#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

void printVector(vector<int> v)
{
    for(size_t i=0; i<v.size(); i++)
        cout << v[i] << "\t";

    cout << endl;
}

void printVectors(vector<vector<int> > v)
{
    for(size_t i=0; i<v.size(); i++)
        printVector(v[i]);
}

int max(int a, int b)
{
    return a > b ? a : b;
}

vector<int> p;
vector<vector<int> > cache;
int num_calls = 0;

int profit(int year, int start, int end)
{
    num_calls++;
    if (start > end) return 0;

    if (cache[start][end] != -1)
        return cache[start][end];

    cache[start][end] = max(profit(year+1, start+1, end) + year * p[start],
            profit(year+1, start, end-1) + year * p[end]);

    return cache[start][end];
}

void test()
{
    int a[] = {2, 3, 5, 1, 4};
    int n = sizeof(a)/sizeof(a[0]);

    p.assign(a, a+n);

    printVector(p); cout << endl;

    vector<int> temp(n, -1);
    cache.assign(n, temp);

    printVectors(cache); cout << endl;

    int max_profit = profit(1, 0, n-1);

    printf("Maximum profit: %d \n\n", max_profit);
    printf("num of function calls: %d \n\n", num_calls);

    printVectors(cache); cout << endl;

    /*
     * cache at end of run:
     *
        10  23  43  45  50
        -1  15  37  40  48
        -1  -1  25  29  41
        -1  -1  -1  5   24
        -1  -1  -1  -1  20

    */


}




int main() {
    //cout << "Wa de gwaan werl!" << endl; // prints Wa de gwaan werl!

    test();
    return 0;
}
