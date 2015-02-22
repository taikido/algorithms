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

vector<int> c; // cache for fib numbers

int num_calls = 0;
int fibR(int n)
{
    num_calls++;
    if (n == 0 || n == 1) return n;
    return fibR(n-1) + fibR(n-2);
}

int fib(int n)
{
    num_calls++;
    if (n == 0 || n == 1) return c[n] = n;

    if (c[n] != -1)
    {
        return c[n];
    }

    c[n] = fib(n-1) + fib(n-2);

    return c[n];
}

void test()
{
    int n = 20;
    c.assign(n+1, -1); // Important!!!

    printVector(c);

//  int out = fibR(n);

    int out = fib(n);
    cout << out << endl;

    printf("num of function calls: %d \n\n", num_calls);
    /*
     * fib(8) = 21
     * w/o cache: num_calls = 67 --> 21 with caching (for n = 8)
     *
     * fib(20) = 6765
     * w/o cache: num_calls = 21891 --> 39 with caching (for n = 20)
     */

    printVector(c);
}


int main() {
    test();
    return 0;
}