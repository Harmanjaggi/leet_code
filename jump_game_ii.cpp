#include "iostream"
#include "vector"
#include "cmath"
using namespace std;

int jump(vector<int> &nums)
{
    int jumps = 0;
    int current = 0;
    int farthest = 0;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        farthest = max(farthest, nums[i] + i);
        if (i == current)
            current = farthest, jumps++;
    }
    return jumps;
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int &ele : nums)
        cin >> ele;
    cout << jump(nums);
}