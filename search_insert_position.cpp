#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int> &nums, int target)
{
    int lo = 0, hi = nums.size() - 1;
    int mid;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return lo;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &ele : arr)
        cin >> ele;
    cin >> n;
    cout << searchInsert(arr, n);
}