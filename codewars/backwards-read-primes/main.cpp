#include <string>
#include <vector>
#include <cmath>
#include <iostream>
class BackWardsPrime {
public:
  BackWardsPrime(): cache({2, 3, 5, 7}) {}
  static std::string backwardsPrime(long long start, long long end);
  bool isPrime(long long num);

private:
  std::vector<long long> cache;

  inline long long genNextPrime() {
    long long next = cache.back() + 2;
    for (; !isPrime(next); next += 2) {}
    return next;
  }
};

bool BackWardsPrime::isPrime(long long num) {
  for (auto it = cache.begin(); *it <= std::sqrt(num);) {
    if (num % *it == 0) {
      return false;
    }

    // if the cache is not enough, find next prime
    if (++it == cache.end()) {
      cache.push_back(genNextPrime());
      it = cache.end() - 1;
    }
  }

  return true;
}

std::string _reverse(std::string &&str) {
  std::string rever(str);
  for (auto i = 0; i <= (ssize_t)str.length() / 2 - 1; i++) {
    rever[i] = str[str.length() - 1 - i];
    rever[str.length() - 1 - i] = str[i];
  }
  return rever;
}

std::string BackWardsPrime::backwardsPrime(long long start, long long end) {
  std::string result;
  BackWardsPrime calc;
  int step = 1;

  for (auto i = start; i <= end; i += step) {
    if (calc.isPrime(i)) {
      step = 2;
      auto rever = _reverse(std::to_string(i));
      long long reverNum = std::stoll(rever);
      if (i != reverNum && calc.isPrime(reverNum)) {
        result.append(std::to_string(i));
        result.append(" ");
      }
    }
  }

  if (result.length() > 1)
    return result.substr(0, result.length() - 1);
  return result;
}

int main(int argc, char *argv[]) {
  BackWardsPrime primeCalc;

  for (auto i = 2; i < 1000000; i++) {
    primeCalc.isPrime(i);
  }

  std::cout << primeCalc.backwardsPrime(100, 500) << std::endl;

  return 0;
}