#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    double median{};
    int size = (int)(nums1.size()) + (int)(nums2.size());
    vector<int> combined = {};
    combined.reserve(size);
    copy(nums1.begin(), nums1.end(), back_inserter(combined));
    copy(nums2.begin(), nums2.end(), back_inserter(combined));
    sort(combined.begin(), combined.end(), less<int>());
    if (size % 2 == 0)
    {
        median = (combined[size / 2] + combined[size / 2 - 1]) / 2.0;
    }
    else
    {
        median = combined[size / 2];
    }
    return median;
}

int main()
{
    vector<int> nums1{1, 2};
    vector<int> nums2{3, 4};
    cout << findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}