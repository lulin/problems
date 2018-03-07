#include <string>
#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

class Solution{
public:
    Solution(): start(0), stop(0) {}
    int lengthOfLongestSubstring(string);
private:
    size_t start;
    size_t stop;
#define helperSolutionLength (this->stop - this->start)
};

int
Solution::lengthOfLongestSubstring(string str) {
    bitset<256> bs;
    vector<int> vec(255, -1);
    int longest;

    size_t pos;
    auto it = str.cbegin();
    auto start = it;
    auto end = str.cend();
    size_t index;
    for (pos = 0; it != end; it++, pos++) {
        index = static_cast<size_t>(*it);
        if (bs[index]) {
            if (longest < it - start) {
                longest = it -start;
            }
        }
    }
    return 0;
}

int
main(int argc, char *argv[]) {
    return 0;
}