#ifndef __HEADER__ARITHMETIC
#define __HEADER__ARITHMETIC
#include <stdbool.h>

int gcd(int a, int b);
int lcm(int a, int b);
int * divisors(int a);
int * primeFactors(int a);
bool isPrime(int a);
int * primesUp2N(int N);
int * partitions(int a); // returns all partitions of number a

#endif // __HEADER__ARITHMETIC