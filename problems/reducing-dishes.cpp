#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

int maxSatisfaction(vector<int> &satisfaction)
{
    int ans = INT32_MIN, n = satisfaction.size();
    sort(satisfaction.begin(), satisfaction.end());
    vector<int> postSum(n);
    postSum[n - 1] = satisfaction[n - 1];
    for (int i = n - 2; i >= 0; i--)
        postSum[i] = postSum[i + 1] + satisfaction[i];
    for (int i = n - 1; i >= 0; i--) {
        int temp = ans + postSum[i];
        if(ans > temp)
            return ans;
        ans = temp;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int &ele : nums)
        cin >> ele;
    cout << maxSatisfaction(nums);
}