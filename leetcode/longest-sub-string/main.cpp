#include <string>
#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

class Solution{
public:
    Solution(): start(0), stop(0), longest(0) {}
    int lengthOfLongestSubstring(string);
    void clearParsingState() {start = stop = longest = 0;}
private:
    size_t start;
    size_t stop;
    int longest;

    inline int
    lengthOfTemp() {return this->stop - this->start;}
};

int
Solution::lengthOfLongestSubstring(string str) {
    clearParsingState();
    vector<int> vec(256, -1); // map the characters

    size_t pos;
    auto it = str.cbegin();
    auto end = str.cend();
    size_t preStart;

    preStart = start;
    size_t index;
    for (pos = 0; it != end; it++, pos++) {
        index = static_cast<size_t>(*it);
        if (vec[index] == -1) {
            vec[index] = (int)pos;
            // update length
            if (longest < pos + 1 - start)
                longest = pos + 1 - start;

            continue;
        }

        // clear the charater map
        for (int i = preStart; i < vec[index]; i++) {
            vec[str[i]] = -1;
        }
        start = vec[index] + 1;
        preStart = start;
        vec[index] = pos;
    }
    return longest;
}

int
main(int argc, char *argv[]) {
    Solution solution;
#define length(str) solution.lengthOfLongestSubstring(str)
    string str = "abcdaefghic";
    cout << "lenght of longest substring " << str << " is " << length(str) << endl;
    str = "ababbb";
    cout << "lenght of longest substring " << str << " is " << length(str) << endl;
    str = "aabbb";
    cout << "lenght of longest substring " << str << " is " << length(str) << endl;
    str = "abbcdea";
    cout << "lenght of longest substring " << str << " is " << length(str) << endl;
    return 0;
}