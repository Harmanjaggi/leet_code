#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void display(vector<vector<int>> v)
{
    for (vector<int> list : v)
    {
        for (int ele1 : list)
            cout << ele1 << " ";
        cout << endl;
    }
}

void display2(vector<int> v)
{
    for (int ele : v)
        cout << ele << " ";
    cout << endl;
}

int xor_val(vector<int> v) {
    int xor_value = 0;
    for(int ele: v)
        xor_value ^= ele;
    return xor_value;
}

bool isDuplicate(vector<vector<int>> v, vector<int> s)
{
    for (vector<int> ele : v)
    {
        sort(ele.begin(), ele.end());
        sort(s.begin(), s.end());
        if(ele == s)
            return true;
    }
    return false;
}

vector<int> twoSum(vector<int> &nums, int target_idx)
{
    int lo = 0, hi = nums.size() - 1;
    vector<int> ans;
    while (lo < hi)
    {
        if (lo == target_idx)
        {
            lo++;
            continue;
        } else if(hi == target_idx){
            hi--;
            continue;
        }
        int val = nums[lo] + nums[hi];
        if (val == -nums[target_idx])
            return {nums[lo], nums[hi]};
        if (val < -nums[target_idx])
            lo++;
        else
            hi--;
    };
    return ans;
}
vector<vector<int>> threeSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> sol;
    for (int i = 0; i < nums.size(); i++)
    {
        vector<int> ans = twoSum(nums, i);
        if (ans.size() != 0)
        {
            ans.push_back(nums[i]);
            if (!isDuplicate(sol, ans))
                sol.push_back(ans);
        }
    }
    return sol;
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int &ele : nums)
        cin >> ele;
    display(threeSum(nums));
}