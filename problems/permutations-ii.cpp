#include "iostream"
#include "vector"
#include "set"

using namespace std;

set<vector<int>> s;
void permuteUnique(vector<int> &nums, vector<int> tmp, vector<bool> &vis)
{
    if (tmp.size() == nums.size()){
        s.insert(tmp);
        return;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (!vis[i])
        {
            tmp.push_back(nums[i]);
            vis[i] = true;
            permuteUnique(nums, tmp, vis);
            vis[i] = false;
            tmp.pop_back();
        }
    }
}
vector<vector<int>> permuteUnique(vector<int> &nums)
{
    vector<bool> vis(nums.size());
    permuteUnique(nums, {}, vis);
    vector<vector<int>> ans;
    for (auto &vec : s)
        ans.push_back(vec);
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int &ele : nums)
        cin >> ele;
    permuteUnique(nums);
}