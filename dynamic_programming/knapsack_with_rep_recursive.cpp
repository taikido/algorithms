#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <map>

#include "utility.h"


using namespace std;

// Returns the maximum value that can be put in a knapsack of capacity W
int knapsack(int W, vector<int> wt, vector<int> val, int n)
{
   // Base Case
   if (n == 0 || W == 0)
       return 0;

   // If weight of the nth item is more than Knapsack capacity W, then
   // this item cannot be included in the optimal solution
   if (wt[n-1] > W)
       return knapsack(W, wt, val, n-1);
   else
   {
      vector<int> temp;
      for(int i=n-1; i>0; i--)
      {
        temp.push_back(val[i] + knapsack(W-wt[i], wt, val, i));
      }
      if (!temp.empty())
      return max(temp);
   }
}

void test()
{
    int W = 10;
    int v_array[] = {10, 40, 50, 30};
    int wt_array[] = {5, 4, 3, 6};

    int n = sizeof(v_array)/sizeof(v_array[0]);
    vector<int> v(v_array, v_array+n);
    vector<int> wt(wt_array, wt_array+n);

    int k = knapsack(W, wt, v, n);

    printf("\n\n Max value of knapsack subset is [%d] \n\n", k);
}

int main()
{
    test();
}