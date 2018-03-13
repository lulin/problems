/// https://www.codewars.com/kata/5667e8f4e3f572a8f2000039/train/cpp
#include <ctype.h>
#include <iostream>
#include <string>

class Accumul {
 public:
  static std::string accum(const std::string &s);
};

std::string Accumul::accum(const std::string &str) {
  std::string result;
  int pos = 0;
  for (auto it = str.cbegin(); it != str.end(); it++, pos++) {
    if (pos != 0) {
      result.append("-");
    }
    result.append(std::string(1, toupper(*it)));
    result.append(std::string(pos, tolower(*it)));
  }
  return result;
}

int main(int argc, char *argv[]) {
  std::string str;
  str = std::string("abc");
  std::cout << str << " -> " << Accumul::accum(str) << std::endl;
  str = std::string("Xyc");
  std::cout << str << " -> " << Accumul::accum(str) << std::endl;
  str = std::string("lmn");
  std::cout << str << " -> " << Accumul::accum(str) << std::endl;
}
