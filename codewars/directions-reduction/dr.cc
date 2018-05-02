#include <iostream>
#include <string>
#include <vector>

class DirReduction {
public:
  static std::vector<std::string> dirReduc(std::vector<std::string> &arr);

private:
  static std::vector<std::string> &compose(std::vector<std::string> &dirs,
                                           std::string &next);
};

bool is_dir_oppsite(const std::string &d1, const std::string &d2) {
  return d1 == "NORTH"
             ? d2 == "SOUTH"
             : (d1 == "SOUTH" ? d2 == "NORTH"
                              : (d1 == "EAST" ? d2 == "WEST" : d2 == "EAST"));
}

std::vector<std::string> &DirReduction::compose(std::vector<std::string> &dirs,
                                                std::string &next) {
  if (dirs.empty() || !is_dir_oppsite(next, dirs.back())) {
    dirs.push_back(next);
    return dirs;
  }

  dirs.pop_back();
  return dirs;
}

std::vector<std::string> DirReduction::dirReduc(std::vector<std::string> &arr) {
  std::vector<std::string> res;
  for (auto &dir : arr) {
    compose(res, dir);
  }
  return res;
}

int main(int argc, char *argv[]) {
  (void)argc;
  (void)argv;
  std::vector<std::string> reduced_dirs;
  std::vector<std::string> dirs = {"NORTH", "SOUTH", "SOUTH",
                                   "WEST",  "NORTH", "EAST"};

  reduced_dirs = DirReduction::dirReduc(dirs);
  for (auto &e : reduced_dirs) {
    std::cout << " " << e;
  }
  std::cout << std::endl;
  return 0;
}
