#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <cstdio>
using namespace std;


class BadSubstring { public:
  long long howMany(int length) {
    int n = 0;
    long long a = 0, x = 1; // how many n-letter words begin with a, or else
    while (n < length) {
      long long a1 = (a+x), x1 = (a + 2*x);
      a = a1; x = x1; n++;
    }
    return a + x;
  }
};
