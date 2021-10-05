#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

// odd prime numbers are marked as "true" in a bitvector
std::vector<bool> sieve;

// return true, if x is a prime number
bool isPrime(unsigned int x)
{
  // handle even numbers
  if ((x & 1) == 0)
    return x == 2;

  // lookup for odd numbers
  return sieve[x >> 1];
}

// find all prime numbers from 2 to size
void fillSieve(unsigned int size)
{
  // store only odd numbers
  const unsigned int half = (size >> 1) + 1;

  // allocate memory
  sieve.resize(half, true);
  // 1 is not a prime number
  sieve[0] = false;

  // process all relevant prime factors
  for (unsigned int i = 1; 2*i*i < half; i++)
    // do we have a prime factor ?
    if (sieve[i])
    {
      // mark all its multiples as false
      unsigned int current = 3*i+1;
      while (current < half)
      {
        sieve[current] = false;
        current += 2*i+1;
      }
    }
}


// compute all factorials until factorial % n == 0
unsigned int naive(unsigned int n)
{
  unsigned long long factorial = 1;
  unsigned int result = 0;
  while (factorial % n != 0)
  {
    result++;
    factorial *= result;
    factorial %= n;
  }
  return result;
}

// all prime numbers < 10^8
std::vector<unsigned int> primes;
// cache for i^2, i^3, i^4, ... where i is prime
std::unordered_map<unsigned int, unsigned int> cache;

// compute s(n)
unsigned int getSmallestFactorial(unsigned int n)
{
  // will be the result
  unsigned int best = 0;

  // split off all prime factors
  for (auto p : primes)
  {
    // p is not a prime factor of the current number ?
    if (n % p != 0)
      continue;

    // extract the current prime factor as often as possible
    // e.g. => 24 => 2^3 * 3 => primePower will be 8 and reduced = 3
    unsigned int primePower = 1;
    do
    {
      n          /= p;
      primePower *= p;
    } while (n % p == 0);

    // higher result ?
    best = std::max(best, cache[primePower]);

    // no further factorization possible ?
    if (n == 1)
      return best;
    if (isPrime(n))
      // s(prime) = prime
      return std::max(best, n);
  }

  return best;
}

int main()
{
  unsigned int limit = 100000000;
  std::cin >> limit;

  unsigned long long sum = 0;

  // simple algorithm, too slow
  //for (unsigned int i = 2; i <= 100; i++)
  //  sum += naive(i);

  // and now the more sophisticated approach

  // find all primes below 10^8
  fillSieve(limit);
  // copy those 5761455 primes to a dense array for faster access
  for (unsigned int i = 2; i < limit; i++)
    if (isPrime(i))
      primes.push_back(i);

  // find result for numbers with are powers of a single prime
  for (unsigned int i = 2; i <= limit; i++)
  {
    if (isPrime(i))
    {
      // pre-compute all values of i^2, i^3, ... where i is prime and store in cache[]
      unsigned long long power = i * (unsigned long long) i;
      for (unsigned int exponent = 2; power <= limit; exponent++)
      {
        // optimized version of naive(), skip i numbers in each iteration
        unsigned long long factorial = i;
        unsigned int result = i;
        do
        {
          result    += i;
          factorial *= result;
          factorial %= power;
        } while (factorial % power != 0);

        cache[power] = result;

        // next exponent
        power *= i;
      }

      // s(prime) = prime
      sum += i;
    }
    else
    {
      // compute s(non prime)
      sum += getSmallestFactorial(i);
    }
  }

  // and display the result
  std::cout << sum << std::endl;
  return 0;
}
