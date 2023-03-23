#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

void display(vector<vector<int>> arr)
{
    for (vector<int> list : arr)
    {
        for (int ele : list)
            cout << ele << " ";
        cout << endl;
    }
}

void combinationSumHelper(vector<int> &candidates, int target, int i, vector<int> path, vector<vector<int>> &ans)
{
    if (target == 0)
    {
        ans.push_back(path);
        return;
    }
    while (i < candidates.size() && target - candidates[i] >= 0)
    {
        path.push_back(candidates[i]);
        combinationSumHelper(candidates, target - candidates[i], i, path, ans);
        i++;
        path.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end()); // sort candidates array
    // remove duplicates
    candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
    vector<vector<int>> ans;
    combinationSumHelper(candidates, target, 0, {}, ans);
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int &ele : nums)
        cin >> ele;
    cin >> n;
    display(combinationSum(nums, n));
}