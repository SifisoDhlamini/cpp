#include <iostream>
#include <vector>

using namespace std;
vector<int> twoSum(vector<int> &numbers, int target)
{
    for (auto i = numbers.begin(); i != numbers.end(); i++)
    {
        auto j = i + 1;
        auto found = find_if(j, numbers.end(), [i, target](int x)
                             { return *i + x == target; });
        if (found != numbers.end())
            return {int(i - numbers.begin()) + 1, int(found - numbers.begin()) + 1};
    }
    return {};
}

int main(){
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(numbers, target);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}