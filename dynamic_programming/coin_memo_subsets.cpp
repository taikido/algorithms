// Mon.Feb.16.2015
// Source: http://www.geeksforgeeks.org/dynamic-programming-set-7-coin-change/

#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <map>

#include "utility.h"


using namespace std;

int i = 0;
/*
Given a value N, if we want to make change for N cents,
and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins,
how many ways can we make the change? The order of coins doesn’t matter.
*/

int count(vector<int> S, int m, int n)
{
    i++;
    // Sum is 0 so solution exists
    if (n == 0)
        return 1;

    // No solution
    if (n < 0)
        return 0;

    // No more coins exist but sum > 0
    if (m <= 0 && n >= 1)
        return 0;

    // Count = sum of solutions when mth element is included and when it isn't
    return count(S, m-1, n) + count(S, m, n-S[m-1]);
}

int j = 0;
// c represents cost matrix with dimension: m x n
int count(vector<int> S, int m, int n, vector<vector<int> >& c)
{
    j++;
    // Sum is 0 so solution exists
    if (n == 0)
    {
        c[m][n] = 1;
        return c[m][n];
    }

    // No solution
    if (n < 0)
        return 0;

    // No more coins exist but sum > 0
    if (m <= 0 && n >= 1)
        return 0;

    // Count = sum of solutions when mth element is included and when it isn't

    if (c[m][n] != -1) return c[m][n];

    int a, b;
    a = count(S, m-1, n, c);
    b = count(S, m, n-S[m-1], c);
    c[m][n] = a + b;
    return c[m][n];

    /*
    if (c[m-1][n] == -1)
        c[m-1][n] = count(S, m-1, n, c);

    if (c[m][n-S[m-1]] == -1)
        c[m][n-S[m-1]] = count(S, m, n-S[m-1], c);

    return c[m-1][n] + c[m][n-S[m-1]];
    */
}

// Return subsets
int count(vector<int> S, int m, int n, vector<int>& curr, vector<vector<int> >& solution)
{
    // Sum is 0 so solution exists
    if (n == 0)
    {
        printf("Subset... \n");
        printVector(curr);
        return 1;
    }

    // No solution
    if (n < 0)
    {
        if (!curr.empty()) curr.pop_back();
        return 0;
    }

    // No more coins exist but sum > 0
    if (m <= 0 && n >= 1)
    {
        if (!curr.empty()) curr.pop_back();
        return 0;
    }

    // Count = sum of solutions when mth element is included and when it isn't
    int a = count(S, m-1, n, curr, solution);
    curr.push_back(S[m-1]);
    int b = count(S, m, n-S[m-1], curr, solution);

    return a + b;
}

void test()
{
    int a[] = {1, 2, 3};
    // int a[] = {2, 5, 3, 6};
    // int a[] = {1, 3};
    int m = sizeof(a)/sizeof(a[0]);
    vector<int> S(a, a+m);

    // int n = 10; // Make change for 10 cents
    int n = 5; //3;

    cout << "change: " << count(S, m, n) << endl;
    printf("Number of calls with recursion: %d \n", i);

    vector<int> curr;
    vector<vector<int> > solution;

    // cout << "(change: " << count(S, m, n, curr, solution) << endl;

    // Memoization

    vector<int> temp(n+1, -1);
    vector<vector<int> > c(m+1, temp);
    // c[0].assign(c[0])
    cout << "\n*change: " << count(S, m, n, c) << endl;

    printf("Memoized Cost matrix... \n");
    printVectors(c); cout << endl;
    printf("Number of calls with Memoization: %d \n", j);
}

int main()
{
    test();
}