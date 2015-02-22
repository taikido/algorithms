#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <map>

#include "utility.h"


using namespace std;

int count( vector<int> S, int m, int n )
{
    int i, j, x, y;

    // We need n+1 rows as the table is consturcted in bottom up manner using
    // the base case 0 value case (n = 0)
    // int table[n+1][m];
    vector<int> temp(m, 0);
    vector<vector<int> > table(n+1, temp);

    // Fill the enteries for 0 value case (n = 0)
    for (i=0; i<m; i++)
        table[0][i] = 1;

    // Fill rest of the table enteries in bottom up manner
    for (i = 1; i < n+1; i++)
    {
        for (j = 0; j < m; j++)
        {

            // if (j < S[i])
            //     table[i][j] = table[i-1][j];
            // else
            //     table[i][j] = min(table[i-1][j], 1+table[i][j-S[i]]);
            /* */
            // Count of solutions including S[j]
            x = (i-S[j] >= 0)? table[i - S[j]][j]: 0;

            // Count of solutions excluding S[j]
            y = (j >= 1)? table[i][j-1]: 0;

            // total count
            table[i][j] = x + y;

        }
    }

    printVectors(table);
    return table[n][m-1];
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

}

int main()
{
    test();
}