#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int maxArea(vector<int> &height)
{
    // get max area for each height
    int left = 0;
    int right = height.size() - 1;
    int max_area = 0;

    while (left < right)
    {
        int width = right - left;
        int min_height = min(height[left], height[right]);
        int area = width * min_height;

        if (area > max_area)
            max_area = area;

        if (height[left] >= height[right])
        {
            right--;
        }
        else
        {
            left++;
        }
    }
    return max_area;
}

int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    vector<int> height2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << maxArea(height) << endl;
    cout << maxArea(height2) << endl;
    return 0;
}