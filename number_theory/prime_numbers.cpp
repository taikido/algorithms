/** ===========================================================================================
* Name : prime_numbers.cpp
* Author: taikido
* Description: Tutorials/Revision of Fundamentals of Prime Numbers.
* Date: Fri.Dec.6.2013
*=============================================================================================**/


#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

/**Factors an integer into a product of prime numbers
 * (based on the the fundamental theorem of arithmetic).
 *
 * @param n: integer to be factored.
 * @return vector of prime factors.
 */
vector<int> prime_factorization(long n){
	vector<int> factors;

	//factor even numbers first
	printf("\n\n----------The prime factors of %d are: \n\n", n);
	while (n % 2 == 0){
		printf("%d \t", 2);
		factors.push_back(2);
		n /= 2;
	}

	long i = 3;

	while ( i <= sqrt(n) + 1){
		while (n % i == 0){
			factors.push_back(i);
			printf("%d \t", i);
			n /= i;
		}
		i += 2;
	}

	if (n > 1){
		factors.push_back(n);
		printf("%d \t", n);
	}
	return factors;
}

/**Prints prime numbers.
 *
 * @param prime_flag: indices are prime numbers if val = true. *
 */
void print_primes(vector<bool> prime_flag){
	printf("\n\n----------The prime number are: \n\n");
	for (int i=2; i < int(prime_flag.size()); i++){
		if (prime_flag[i]){
			printf("%d \t", i);
		}
	}
}

/**Generates prime numbers using the Sieve of Eratosthenes.
 *
 * @param n: generate prime numbers up to n.
 * @return vector of boolean values where indices are prime numbers
 * 		if val = true
 */
vector<bool> prime_sieve(int n){
	//vector<int> primes;
	vector<bool> prime_flag(n, true);
	for(int i = 2; i < sqrt(n) + 1; i++){
		if  (prime_flag[i]){
			for (int j = i ; j * i < n; j++){
				prime_flag[i*j] = false;
			}
		}
	}
	print_primes(prime_flag);
	return prime_flag;
}

/**Struct representing a pair of elements.
 *
 * @field x: element 1.
 * @field y: element 2.
 */
struct Pair{
	int x;
	int y;
};

/**Uses Golbach conjecture to generate pairs of primes that sum to a Golbach number.
 *
 * @param n: Golbach number.
 * @return vector of pairs of primes that sum to a Golbach number
 */

vector<Pair> generate_golbach_pairs(int n){
	vector<Pair> pairs;

	vector<bool> primes = prime_sieve(n);

	cout << "\n\n-----------------Golbach Pairs-------------------\n\n";
	for(int i=2; i <= n/2; i++){
		if (primes[i] && primes[n-i]){
			Pair p;
			p.x = i; p.y = n-i;
			pairs.push_back(p);
			printf("(%d, %d) \n", p.x, p.y);
		}
	}
	return pairs;
}

/**Factors an integer into a product of prime numbers
 * (based on the the fundamental theorem of arithmetic).
 *
 * @param n: integer to be factored.
 * @return vector of prime factors.
 */
vector<int> generate_prime_factors(int n){
	vector<int> factors;

	//only generate for positive numbers
	if (n <= 1)			return factors;
	int i = 2;

	printf("\n\n----------The prime factors of %d are: \n\n", n);
	while (n > 1){
		while (n % i == 0){
			factors.push_back(i);
			printf("%d \t", i);
			n /= i;
		}
		i++;
	}

	cout << endl;
	return factors;
}

/**Uses Euclid's algorithm to find the gcd of 2 non-negative integers
 * 	a and b where a >= b. (Iterative version of Euclid's algorithm)
 *
 * @param a: integer 1.
 * @param b: integer 2.
 * @return gcd of a & b.
 */
int gcd_iterative(int a, int b){
	int r = b;
	while ( r > 0){
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

/**Uses Euclid's algorithm to find the gcd of 2 non-negative integers
 * 	a and b where a >= b. (Recursive version of Euclid's algorithm)
 *
 * @param a: integer 1.
 * @param b: integer 2.
 * @return gcd of a & b.
 */
int gcd_recursive(int a, int b){
	if (b == 0)	return a;
	return gcd_recursive(b, a % b);
}

/**Tests iterative and recursive versions of gcd algorithm.
 *
 * @param a: integer 1.
 * @param b: integer 2.
 */
void test_gcd(int a, int b){
	//Ensure that a and b are both non-negative and a >= b
	int c = gcd_iterative(a, b);
	printf("GCD of %d and %d is: %d \n", a, b, c);

	c = gcd_recursive(a, b);
	printf("GCD of %d and %d is: %d \n", a, b, c);

}

/**Euler's Totient Function: Phi.
 * 	Counts the number of totatives (the number of unique prime factors
 * 	in a number's list of prime factors).
 *
 * @param n: integer
 * @return count
 */

int phi(int n){
	int result = n;

	vector<int> factors = prime_factorization(n);

	int p = factors[0];
	int count = 0;

	for (int i=1; i < factors.size(); i++){
		if (p != factors[i]){
			result = (result *(p-1))/p;
			p = factors[i];
			count++;
		}
	}
	result = (result *(p-1))/p;
	count++;

	printf("\nPhi(%d) = %d and count: %d \n", n, result, count);

	return result;
}

int main() {
	phi(9240);
//	prime_factorization(9240);
//	phi(616);
//	test_gcd(12, 8);
//	generate_golbach_pairs(10);
//	prime_sieve(20);
//	generate_prime_factors(192);
//	prime_factorization(192);
	return 0;
}
