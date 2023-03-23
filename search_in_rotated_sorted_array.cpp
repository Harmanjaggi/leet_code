#include "iostream"
#include "vector"

using namespace std;

int find_sorted_nums_start(vector<int> &nums)
{
    int lo = 0, hi = nums.size() - 1;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (mid > 0 && mid < nums.size() - 1)
        {
            if (nums[mid - 1] > nums[mid] && nums[mid + 1] > nums[mid])
                return mid;
        }
        else
        {
            if ((mid > 0 && nums[mid - 1] > nums[mid]) || ((mid < nums.size() - 1) && nums[mid + 1] > nums[mid]))
                return mid;
        }
        // cout << "mid:" << mid << " lo:" << lo << " hi:" << hi;
        // in increasing order
        if (nums[mid] < nums[hi])
            hi = mid - 1;
        // in between increasing order
        else
            lo = mid + 1;
        // cout << " lo:" << lo << " hi" << hi << endl;
    }
    return lo;
}

int search(vector<int> &nums, int target)
{
    int lo = find_sorted_nums_start(nums);
    // cout << "lo: " << lo << endl;
    int hi = lo + nums.size();
    while (lo <= hi)
    {
        int mid = (lo + (hi - lo) / 2);
        if (nums[mid % nums.size()] == target)
            return mid % nums.size();
        if (nums[mid % nums.size()] < target)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return -1;
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int &ele : nums)
        cin >> ele;
    cin >> n;
    cout << search(nums, n);
}