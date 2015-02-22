/*
Recursive Version
*/

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<vector<int> > c; // cache for costs

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

int num_calls = 0;

int lcs(string x, string y, int i, int j)
{
    num_calls++;
    if (i == 0 || j == 0) return 0;

    if (c[i][j] != -1) return c[i][j];

    if (x[i-1] == y[j-1])
    {
        printf("(i, j): {%d, %d), x[i]: %c, x[j]: %c \n", i, j, x[i], x[j]);
        c[i][j] = lcs(x, y, i-1, j-1) + 1;
        return c[i][j];
    }

    c[i][j] = max(lcs(x, y, i-1, j), lcs(x, y, i, j-1));
    return c[i][j];

}

string backtrack(vector<vector<int> > v, string x, string y, int i, int j)
{
    if (i == 0 || j == 0) return "";
    else if (x[i-1] == y[j-1])
    {
        //printf("i: %d, j: %d, x[i]: %c, y[j]: %c \n", i, j, x[i], y[j]);
        return backtrack(v, x, y, i-1, j-1) + x[i-1];
    }
    else
    {
        if (v[i-1][j] > v[i][j-1]) return backtrack(v, x, y, i-1, j);
        else return backtrack(v, x, y, i, j-1);
    }
}

void test()
{
    string x = "XMJYAUZ";
    string y = "MZJAWXU";

    int m = x.length();
    int n = y.length();

    printf("m: %d, n: %d \n", m, n);

    vector<int> temp(n+1, -1);
    c.assign(m+1, temp);

    int longest = lcs(x, y, m, n);
    cout << "length: " << longest << endl;

    string longest_string = backtrack(c, x, y, m, n);
    cout << "longest_string: " << longest_string << endl;

    cout << "c[m][n]: " << c[m][n] << endl;
    printf("num of function calls: %d \n\n", num_calls); // without caching: 606, 64 with cacheing

    printVectors(c); cout << endl;

}

/*
 m: 7, n: 7
(i, j): {7, 2), x[i]:
(i, j): {2, 1), x[i]: J, x[j]: M
(i, j): {3, 3), x[i]: Y, x[j]: Y
(i, j): {5, 4), x[i]: U, x[j]: A
(i, j): {1, 6), x[i]: M, x[j]: Z
(i, j): {6, 7), x[i]: Z, x[j]:
length: 4
longest_string: MJAU
c[m][n]: 4
num of function calls: 81

-1  -1  -1  -1  -1  -1  -1  -1
-1  0   0   0   0   0   1   -1
-1  1   1   1   1   1   1   -1
-1  1   1   2   2   2   2   -1
-1  1   1   2   2   2   2   -1
-1  1   1   2   3   3   3   -1
-1  1   1   2   3   3   3   4
-1  -1  2   2   3   3   3   4



 */

int main() {
    cout << "Wa de gwaan werl!" << endl; // prints Wa de gwaan werl!

    test();
    return 0;
}
