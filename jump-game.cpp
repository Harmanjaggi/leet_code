#include "iostream"
#include "vector"
using namespace std;

bool canJump(vector<int> &nums)
{
    int farthest = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (farthest < i)
            return false;
        farthest = max(farthest, i + nums[i]);
        if (farthest >= nums.size() - 1)
            return true;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int &ele : nums)
        cin >> ele;
    canJump(nums);
}