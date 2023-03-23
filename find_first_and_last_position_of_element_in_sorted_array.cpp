#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

void display(vector<int> arr)
{
    for (int ele : arr)
        cout << ele << " ";
    cout << endl;
}

vector<int> searchRange(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;
    int start = -1, end = -1;

    // Searching the start index of target
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] < target)
            low = mid + 1;
        else if (nums[mid] > target)
            high = mid - 1;
        else
        { // nums[mid] == target
            start = mid;
            high = mid - 1;
        }
    }

    // Searching the end index of target
    if (start != -1)
    {
        low = 0, high = nums.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] < target)
                low = mid + 1;
            else if (nums[mid] > target)
                high = mid - 1;
            else
            { // nums[mid] == target
                end = mid;
                low = mid + 1;
            }
        }
    }
    return {start, end};
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &ele : arr)
        cin >> ele;
    cin >> n;
    display(searchRange(arr, n));
}