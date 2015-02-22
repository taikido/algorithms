/*============================================================================
* Name : knapsack_with_rep.cpp
* Author: taikido
* Description: Knapsack with Repetition
* Sources:
*           http://www.cs.berkeley.edu/~vazirani/algorithms/chap6.pdf
*           http://www.es.ele.tue.nl/education/5MC10/Solutions/knapsack.pdf
*           http://cse.unl.edu/~goddard/Courses/CSCE310J/Lectures/Lecture8-DynamicProgramming.pdf
*           http://www.cs.rochester.edu/courses/282/fall2013/Lectures/lec13-24oct2013-memo.txt
* Date: Feb.15.2015
*===========================================================================*/

#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <map>

#include "utility.h"

using namespace std;

void getMaxSubset(vector<int> c, map<int, int> m, vector<int>& subset);



/*
    Assume arrays v and wt are 1-indexed to ignore off by 1 error
    considerations during coding

*/
int knapsack(int W, vector<int> wt, vector<int> v)
{
    int n = v.size();
    vector<int> c(W+1, 0);

    map<int, int> m;
    for(int i=1; i<n; i++)
        m[v[i]] = i;

    for(int w=1; w <= W; w++)
    {
        vector<int> temp;
        for(int i=1; i<n; i++)
        {
            if (wt[i] <= w)
                temp.push_back(c[w - wt[i]] + v[i]);
        }
        printf("\n[%d] temp... \n", w);
        if (!temp.empty())
        {
            printVector(temp);
            c[w] = max(temp);
        }

    }

    printVector(c);

    vector<int> subset;
    getMaxSubset(c, m, subset);

    printf("Most Profitable subset of Knapsack ([Index]: Value -> Weight) \n");
    for(int i=0; i<subset.size(); i++)
    {
        printf("[%d]: %d -> %d \n", subset[i], v[subset[i]], wt[subset[i]]);
    }
    return c[W];
}

void getMaxSubset(vector<int> c, map<int, int> m, vector<int>& subset)
{
    int n = c.size();
    for(int i=n-1; i>1; i--)
    {
        if (c[i] != c[i-1])
        {
            int diff = c[i] - c[i-1];
            int idx = m[diff];
            subset.push_back(idx);
        }
    }

}

void test()
{
    int W = 10;
    int v_array[] = {0, 10, 40, 50, 30};
    int wt_array[] = {0, 5, 4, 3, 6};

    int n = sizeof(v_array)/sizeof(v_array[0]);
    vector<int> v(v_array, v_array+n);
    vector<int> wt(wt_array, wt_array+n);

    int k = knapsack(W, wt, v);

    printf("\n\n Max value of knapsack subset is [%d] \n\n", k);
}

int main()
{
    test();
}