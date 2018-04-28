#include <iostream>
#include <list>

class WeightSort {
public:
  static std::string orderWeight(const std::string &strng);

private:
  static std::list<std::string> transform(const std::string &str);
};

std::string WeightSort::orderWeight(const std::string &s) {
  std::list<std::string> &&data = transform(s);
  std::string res{};

  for (auto &e : data) {
    res.append(e + ' ');
  }
  if (res.size() > 0)
    res.pop_back();
  return res;
}

unsigned int weight(const std::string &str) {
  unsigned int w = 0;
  for (auto c : str)
    w += c - '0';

  return w;
}

bool operator<(const std::string &lhs, const std::string &rhs) {
  unsigned int wl = weight(lhs);
  unsigned int wr = weight(rhs);

  if (wl > wr)
    return false;
  if (wl < wr)
    return true;

  auto il = lhs.cbegin();
  auto ir = rhs.cbegin();
  while (il != lhs.cend() && ir != rhs.cend() && *il == *ir) {
    il++;
    ir++;
  }
  if (il == lhs.cend())
    return true;
  if (ir == rhs.cend())
    return false;
  return *il <= *ir;
}

std::list<std::string> WeightSort::transform(const std::string &str) {
  std::list<std::string> data_list;
  std::string num;

  for (auto it = str.cbegin(); it != str.cend();) {
    if (*it == ' ' || *it == '\t' || *it == '\n') {
      it++;
      continue;
    }

    num = "";
    while (it != str.cend() && *it != ' ' && *it != '\t' && *it != '\n') {
      num.push_back(*it);
      ++it;
    }

    // insert
    auto e = data_list.cbegin();
    for (; e != data_list.cend(); e++) {
      if (num < *e) {
        data_list.insert(e, std::move(num));
        break;
      }
    }

    if (e == data_list.cend())
      data_list.push_back(std::move(num));
  }

  return data_list;
}

int main(int argc, char *argv[]) {
  if (argc == 1)
    std::cout << WeightSort::orderWeight(" 100   99 128\t117 119 88  ") << std::endl;
  else if (argc == 2)
    std::cout << WeightSort::orderWeight(argv[1]) << std::endl;
  return 0;
}
