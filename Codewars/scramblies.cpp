#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

bool scramble(const std::string &s1, const std::string &s2)
{
    set<char> s2_set;
    for (char c : s2)
    {
        s2_set.insert(c);
    }
    for (char it : s2_set)
    {
        bool enough =  (count(s1.begin(), s1.end(), it) >= count(s2.begin(), s2.end(), it));
        if (!enough)
            return false;
            
    }
    return true;
}

int main()
{
    cout << scramble("rkqodlw", "world") << endl;
    cout << scramble("cedewaraaossoqqyt", "codewars") << endl;
    cout << scramble("katas", "steak") << endl;
    cout << scramble("scriptjavx", "javascript") << endl;
    cout << scramble("scriptingjava", "javascript") << endl;
    cout << scramble("scriptsjava", "javascript") << endl;
    cout << scramble("javscripts", "javascript") << endl;
    cout << scramble("aabbcamaomsccdd", "commas") << endl;
    cout << scramble("commas", "commas") << endl;
    cout << scramble("sammoc", "commas") << endl;
}