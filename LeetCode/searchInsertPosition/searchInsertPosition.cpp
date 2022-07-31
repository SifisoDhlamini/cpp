#include<iostream>
#include<vector>

using namespace std;

int searchInsert(vector<int> &nums, int target)
{
    int low = 0;
    int high = nums.size() - 1;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (nums[mid] == target)
            return mid;
        else if (target > nums[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }

    return (target > nums[mid]) ? mid + 1 : mid;
}

int main(){
    vector<int> nums = {1,3,5,6};
    cout << searchInsert(nums, 5) << endl;
    return 0;
}