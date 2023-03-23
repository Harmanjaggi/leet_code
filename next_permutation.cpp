#include "iostream"
#include "vector"
#include "unordered_map"
#include "algorithm"

using namespace std;

void display(vector<int> &nums)
{
    for (int &ele : nums)
        cout << ele << " ";
    cout << endl;
}
void nextPermutation(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return;
    int peak = n - 1;
    for (; peak > 0; peak--)
        if (nums[peak - 1] < nums[peak])
            break;
    if (peak == 0)
    {
        sort(nums.begin(), nums.end());
        return;
    }
    int idx_to_replace = peak;
    for (int i = peak; i < n; i++)
        if (nums[peak - 1] < nums[i] && nums[i] < nums[idx_to_replace])
            idx_to_replace = i;
    swap(nums[peak - 1], nums[idx_to_replace]);
    sort(nums.begin() + peak, nums.end());
};

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int &ele : nums)
        cin >> ele;
    nextPermutation(nums);
    display(nums);
}