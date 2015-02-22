/*============================================================================
* Name : edit_distance.cpp
* Author: taikido
* Description: Edit Distance using Dynamic Programming
* Sources:
*           http://www.cs.berkeley.edu/~vazirani/algorithms/chap6.pdf
*           http://en.wikipedia.org/wiki/Levenshtein_distance
* Date: Feb.2015
*===========================================================================*/

#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

#include "utility.h"

using namespace std;


// Use backtracking to align strings
void alignStrings(vector<vector<int> > c, string x, string y, string& a, string& b)
{
    int m = c.size() - 1;
    int n = c[0].size() - 1;

    int i=m, j=n;

    while (i > 0 && j > 0)
    {
        if (x[i-1] == y[j-1])
        {
            a = x[i-1] + a;
            b = y[i-1] + b;
            i--;
            j--;
        }
        else
        {
            int min_val = min(c[i-1][j], c[i][j-1], c[i-1][j-1]);
            // Deletion from source
            if (min_val == c[i-1][j])
            {
                a = "_" + a; // not really necessary but shows where deletion occurs
                i--;
            }
            else if (min_val == c[i][j-1])
            {
                b = "_" + b;
                j--;
            }
            else if (min_val == c[i-1][j-1])
            {
                // Substitution
                a = "_" + a; // a = x[i-1] + a;
                b = "_" + b; // y[i-1] + b;
                i--;
                j--;
            }
        }
    }
}

int editDistance(string x, string y)
{
    int m = x.length();
    int n = y.length();
    vector<int> temp(n+1, 0);
    vector<vector<int> > c(m+1, temp);

    // Handle Base Cases
    // Edit distance from source to 0-length prefix
    for(int i=1; i<=m; i++)
        c[i][0] = i;
    // Edit distance from 0-length string to target
    for(int j=1; j<=n; j++)
        c[0][j] = j;

    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if (x[i-1] == y[j-1])
                c[i][j] = c[i-1][j-1];
            else
                c[i][j] = min(c[i-1][j], c[i][j-1], c[i-1][j-1]) + 1;
        }
    }

    printVectors(c); cout << endl;
    string a = "";
    string b = "";
    alignStrings(c, x, y, a, b);
    cout << "\t" << a << endl;
    cout << "\t" << b << endl;
    return c[m][n];
}


void test()
{
    string x = "sitting";
    string y = "kitten";

    int dist = editDistance(x, y);

    printf("\n\nEdit Distance between [%s] and [%s] is [%d] \n", x.c_str(), y.c_str(), dist);
}

int main()
{
    // cout << "Go Taikido \n\n";
    test();
}