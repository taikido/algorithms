/*============================================================================
* Name : utility.h
* Author: taikido
* Description: Common Utility methods
* Date: Feb.15.2015
*===========================================================================*/

#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

void printSet(set<int> s)
{
    set<int>::iterator it;

    for(it = s.begin(); it != s.end(); it++)
    {
        cout << *it << "\t";
    }
}

int max(vector<int> v)
{
    return *max_element(v.begin(), v.end());
}


void printVector(vector<int> v)
{
    for(int i=0; i<v.size(); i++)
        cout << v[i] << "\t";
    cout << endl;
}

void printVector(vector<bool> v)
{
    for(int i=0; i<v.size(); i++)
        cout << v[i] << "\t";
    cout << endl;
}

void printVectors(vector<vector<int> > v)
{
    for(int i=0; i<v.size(); i++)
        printVector(v[i]);
}

int min(int a, int b, int c)
{
    int min_val = a < b ? a : b;
    min_val = min_val < c ? min_val : c;

    return min_val;
}