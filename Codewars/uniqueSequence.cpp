#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

template <typename T>
std::vector<T> uniqueInOrder(const std::vector<T> &iterable)
{
    vector<T> result{};
    int length = iterable.size();
    if (length > 0)
    {
        result.push_back(iterable[0]);
        for (int i = 1; i < length; i++)
        {
            if (iterable[i] != result.back())
                result.push_back(iterable[i]);
        }
    }
    return result;
}
std::vector<char> uniqueInOrder(const std::string &iterable)
{
    vector<char> c{};
    copy(iterable.begin(), iterable.end(), back_inserter(c));
    return uniqueInOrder(c);
}