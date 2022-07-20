#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Same
{
public:
    static bool comp(std::vector<int> &a, std::vector<int> &b)
    {
        if (a.empty() && b.empty())
            return true;
        if (a.size() != b.size())
            return false;
        return std::all_of(b.cbegin(), b.cend(), [a, b](int i)
                           { return (
                                 (find(a.begin(), a.end(), sqrt(i)) != a.end() || find(a.begin(), a.end(), sqrt(i) * -1) != a.end()) &&
                                 (count(b.begin(), b.end(), i) == (count(a.begin(), a.end(), sqrt(i)) + count(a.begin(), a.end(), sqrt(i) * -1)))); });
    }
};