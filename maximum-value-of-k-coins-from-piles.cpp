#include "iostream"
#include "vector"

using namespace std;

int maxValueOfCoins(int piles_idx, int k, vector<vector<int>> &piles, vector<vector<int>> &dp)
{
    if (dp[piles_idx][k] > 0)
        return dp[piles_idx][k];
    if (piles_idx == piles.size() || k == 0)
        return 0;
    int res = maxValueOfCoins(piles_idx + 1, k, piles, dp), cur = 0;
    for (int no_pile_chosen = 0; no_pile_chosen < piles[piles_idx].size() && no_pile_chosen < k; no_pile_chosen++)
    {
        cur += piles[piles_idx][no_pile_chosen];
        res = max(res, maxValueOfCoins(piles_idx + 1, k - no_pile_chosen - 1, piles, dp) + cur);
    }

    dp[piles_idx][k] = res;
    return res;
}

int maxValueOfCoins(vector<vector<int>> &piles, int k)
{
    int n = piles.size();
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    return maxValueOfCoins(0, k, piles, dp);
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> piles(n);
    for (auto &stack : piles)
        for (int &ele : stack)
            cin >> ele;
    cin >> n;
    maxValueOfCoins(piles, n);
}