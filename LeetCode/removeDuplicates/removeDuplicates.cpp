#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int removeDuplicates(vector<int> &nums) {
    int i = 0;
    for (int j = 1; j < nums.size(); j++)
    {
        if (nums[i] != nums[j])
        {
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1;
}

int main(){
    vector<int> nums = {1,1,2};
    cout << removeDuplicates(nums) << endl;
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
   
}