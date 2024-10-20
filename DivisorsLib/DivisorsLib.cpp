#include <vector>

#include <cmath> // for std::sqrt
 
std::vector<unsigned long long> divisors(unsigned long long number) {

    std::vector<unsigned long long> result;

    unsigned long long limit = std::sqrt(number);
 
    for (unsigned long long i = 1; i <= limit; ++i) {

        if (number % i == 0) {

            result.push_back(i);  // i is a divisor

            if (i != number / i) {

                result.push_back(number / i);  // number / i is a divisor, add only if it's different from i

            }

        }

    }

    return result;

}
 
#include <vector>

#include <cmath>  // for std::sqrt

#include <algorithm> // for reverse
 
std::vector<unsigned long long> divisors(unsigned long long number) {

    std::vector<unsigned long long> smallDivisors;

    std::vector<unsigned long long> largeDivisors;
 
    unsigned long long limit = std::sqrt(number);

    // Reserve memory assuming the number has at most 100 divisors (heuristic for optimization)

    smallDivisors.reserve(100);

    largeDivisors.reserve(100);
 
    for (unsigned long long i = 1; i <= limit; ++i) {

        if (number % i == 0) {

            smallDivisors.push_back(i);  // i is a divisor

            if (i != number / i) {

                largeDivisors.push_back(number / i);  // number / i is a divisor, add only if it's different from i

            }

        }

    }
 
    // Combine small and large divisors

    smallDivisors.insert(smallDivisors.end(), largeDivisors.rbegin(), largeDivisors.rend());
 
    return smallDivisors;

}

 