#include <string>
#include <iostream>

using namespace std;

std::string highestScoringWord(const std::string &str)
{
    auto b = str.begin();
    string::const_iterator i2 = str.begin();
    string str2("hehe");
    string::iterator itBegin = str2.begin();
    string::iterator itBegin2 = str2.begin();
    for (; itBegin != str2.end(); itBegin++) {
        cout << *itBegin << " ";
    }
    return "magic";
}

int main(int argc, char *argv[])
{
    return 0;
}