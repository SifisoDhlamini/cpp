#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


vector<int> nextGreaterElements(vector<int> &nums)
{
    vector<int> result(nums.size());
    int v_size = nums.size();
    for (int i = 0; i < v_size; i++)
    {
        result[i] = -1;
        for (int j = i + 1; j % nums.size() != i; j++)
        {
            if (nums[j % v_size] > nums[i])
            {
                result[i] = nums[j % v_size];
                break;
            }
        }
    }
    return result;
}

int main()
{
    vector<int> nums = { 1,2,1 };
    vector<int> result = nextGreaterElements(nums);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}