#include <cmath>
#include <iostream>

class Arge
{
public:
  static int nbYear(int p0, double percent, int aug, int p);
  static int population(int p0, double percent, int aug, int n);
};

int Arge::population(int p0, double percent, int aug, int n)
{
  return static_cast<int>(p0 * std::pow(1 + percent, n)) +
         static_cast<int>(((pow(1 + percent, n) - 1) / percent) * aug);
}

int Arge::nbYear(int p0, double percent, int aug, int p)
{
  if (percent == 0) {
    return (p - p0) / aug + 1;
  }

  percent /= 100;
  return std::log((p + aug / percent)/(p0 + aug / percent)) / std::log(1 + percent) + 1;
}

/*
      dotest(1500, 5, 100, 5000,15);
      dotest(1500000, 2.5, 10000, 2000000, 10);
      dotest(1500000, 0.25, 1000, 2000000, 94);
      dotest(1500000, 0.25, -1000, 2000000, 151);
*/
int main(int argc, char *argv[])
{
  int p0 = 1500;
  double percent = 5;
  int aug = 100;
  std::cout << "Init: " << p0
            << "  percentage: " << percent
            << "  augment: " << aug
            << std::endl;

  int nYear = 0;
  std::cout << "Population after " << nYear << " years: " << Arge::population(p0, percent, aug, nYear) << std::endl;
  nYear++;
  std::cout << "Population after " << nYear << " years: " << Arge::population(p0, percent, aug, nYear) << std::endl;
  nYear++;
  std::cout << "Population after " << nYear << " years: " << Arge::population(p0, percent, aug, nYear) << std::endl;
  nYear++;
  std::cout << "Population after " << nYear << " years: " << Arge::population(p0, percent, aug, nYear) << std::endl;

  std::cout << Arge::nbYear(1500, 5, 100, 5000) << " year(s) later, the population is beyond 5000" << std::endl;
  std::cout << Arge::nbYear(1500000, 2.5, 10000, 2000000) << " year(s) later, the population is beyond 2000000" << std::endl;
  std::cout << Arge::nbYear(1500000, 0.25, 1000, 2000000) << " year(s) later, the population is beyond 2000000" << std::endl;
  std::cout << Arge::nbYear(1500000, 0.25, -1000, 2000000) << " year(s) later, the population is beyond 2000000" << std::endl;
  std::cout << Arge::nbYear(1500000, 0, 1000, 2000000) << " year(s) later, the population is beyond 2000000" << std::endl;
  std::cout << Arge::nbYear(1010, 0, 100, 1500) << " year(s) later, the population is beyond 1500" << std::endl;
  return 0;
}