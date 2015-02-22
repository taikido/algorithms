/*
Iterative Version
*/


#include <iostream>
#include <cstdio>
#include <vector>
#include <set>

using namespace std;
//int n = 8; //7
//int m = 7; //6
//
//vector<int> c(n, 0);
//vector<vector<int> > v;


void printV(vector<vector<int> > a)
{
    cout << "printing vector: " << endl;
    for(int i=0; i<a.size(); i++)
    {
        for(int j=0; j<a[i].size(); j++)
            printf("%d \t", a[i][j]);
        printf("\n");
    }
}

int max(int a, int b)
{
    return a > b ? a : b;
}

vector<vector<int> > lcs(string x, string y)
{
    int m = x.length();
    int n = y.length();

    vector<int> rows(n+1, 0);
    vector<vector<int> > v(m+1, rows);

//  printV(v);

    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(x.at(i-1) == y.at(j-1))
            {
                v[i][j] = 1 + v[i-1][j-1];
                cout << x.at(i-1) << "\t";
            }

            else
                v[i][j] = max(v[i-1][j], v[i][j-1]);
        }
    }

    cout << endl;

//  printV(v);
    cout << endl;

//  return v[m][n];
    return v;

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

string backtrack(vector<vector<int> > v, string x, string y, int i, int j, int k)
{
    if (i == 0 || j == 0) return "";
    else if (x[i-1] == y[j-1])
    {
        //printf("i: %d, j: %d, x[i]: %c, y[j]: %c \n", i, j, x[i], y[j]);
        string left =  backtrack(v, x, y, i-1, j-1, k+1) + x[i-1];
        string right = backtrack(v, x, y, i-1, j-1, k+1) + y[i-1];

        cout << "left: " << left << endl;
        cout << "right: " << right << endl;

        return backtrack(v, x, y, i-1, j-1, k+1) + x[i-1];
    }
    else
    {
        if (v[i-1][j] > v[i][j-1]) return backtrack(v, x, y, i-1, j, k+1);
        else return backtrack(v, x, y, i, j-1, k+1);
    }
}


vector<string> backtrackAll(vector<vector<int> > v, string x, string y, int i, int j)
{
    if (i == 0 || j == 0)
    {
        vector<string> empty(1, "");
        return empty;
    }

    else if (x[i-1] == y[j-1])
    {
        vector<string> b = backtrackAll(v, x, y, i-1, j-1);
        for(int k =0; k<b.size(); k++) b[k] += x[i-1];
        return b;

//      for(int z=0; z<backtrackAll(v, x, y, i-1, j-1).size(); z++)

    }

    else
    {
        vector<string> r;
        if (v[i-1][j] >= v[i][j-1])
        {
//          r = backtrackAll(v, x, y, i-1, j);
            vector<string> r2 = backtrackAll(v, x, y, i-1, j);
            for(int k=0; k<r2.size(); k++)
                r.push_back(r2[k]);
        }
        if (v[i][j-1] >= v[i-1][j])
        {
//          r = backtrackAll(v, x, y, i, j-1);
            vector<string> r2 = backtrackAll(v, x, y, i, j-1);
            for(int k=0; k<r2.size(); k++)
                r.push_back(r2[k]);

        }
        return r;
    }

}

//set<string> backtrackAll(vector<vector<int> > v, string x, string y, int i, int j)
//{
//  if (i == 0 || j == 0)
//  {
//      set<string> empty;
//      empty.insert("");
//      return empty;
//  }
//
//  else if (x[i-1] == y[j-1])
//  {
//      set<string> b = backtrackAll(v, x, y, i-1, j-1);
//      for(int k =0; k<b.size(); k++) b[k] += x[i-1];
//      return b;
//
//  }
//
//  else
//  {
//      vector<string> r;
//      if (v[i-1][j] >= v[i][j-1])
//      {
////            r = backtrackAll(v, x, y, i-1, j);
//          vector<string> r2 = backtrackAll(v, x, y, i-1, j);
//          for(int k=0; k<r2.size(); k++)
//              r.push_back(r2[k]);
//      }
//      if (v[i][j-1] >= v[i-1][j])
//      {
////            r = backtrackAll(v, x, y, i, j-1);
//          vector<string> r2 = backtrackAll(v, x, y, i, j-1);
//          for(int k=0; k<r2.size(); k++)
//              r.push_back(r2[k]);
//
//      }
//      return r;
//  }
//
//}


void getLCS()
{
    string x = "XMJYAUZ";
    string y = "MZJAWXU";

//  string x = "rabbbit";
//  string y = "rabbit";

//  string x = "rabbit";
//  string y = "rabbbit";

//  string x = "abcabcaa";
//  string y = "acbacba";

//  string x = "AATCC";
//  string y = "ACACG";

//  ababa abaca abcba acaba acaca acbaa acbca

    vector<vector<int> > v = lcs(x, y);
    int m = x.length();
    int n = y.length();

    cout << endl;

    printV(v);
    cout << endl;

    string longest = backtrack(v, x, y, m, n);
    cout << "longest: " << longest << endl;

//  longest = backtrack(v, x, y, m, 0);

    vector<string> all = backtrackAll(v, x, y, m, n);

    set<string> unique;


    cout << endl << "All LCS: \n";

    for(int i=0; i<all.size(); i++)
    {
        cout << all[i] << "\n";
        unique.insert(all[i]);
    }

    cout << endl << "All *Unique LCS: \n";

    set<string>::iterator it;

    for(it = unique.begin(); it != unique.end(); it++)
        cout << *it << "\t";

    cout << endl << "donezo \n";
}

/*
 *
 *
X   M   J   A   U   Z


printing vector:
0   0   0   0   0   0   0   0
0   0   0   0   0   0   1   1
0   1   1   1   1   1   1   1
0   1   1   2   2   2   2   2
0   1   1   2   2   2   2   2
0   1   1   2   3   3   3   3
0   1   1   2   3   3   3   4
0   1   2   2   3   3   3   4

longest: MJAU

All LCS:
MJAU

All *Unique LCS:
MJAU
donezo
 */


int main() {
    cout << "Wa de gwaan werl!" << endl; // prints Wa de gwaan werl!

    getLCS();
//  lcs("abcbdab", "bdcabc");
//  cout << lcs("abcbdab", "bdcabc") << endl;
    return 0;
}
