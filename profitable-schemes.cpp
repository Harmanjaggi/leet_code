#include <iostream>
#include <vector>

using namespace std;

int mod = 1e9 + 7;

// k: crime index
// i: members index
// j: profit made
int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit)
{
    int no_crime = profit.size();
    vector<vector<int>> dp(n + 1, vector<int>(minProfit + 1));

    dp[0][0] = 1;

    for (int k = 1; k <= no_crime; k++)
    {
        int g = group[k - 1];
        int p = profit[k - 1];
        for (int i = n; i >= g; i--)
        {
            for (int j = minProfit; j >= 0; j--)
            {
                dp[i][j] = (dp[i][j] + dp[i - g][max(0, j - p)]) % mod;
            }
        }
    }
    int sum = 0;
    for (int i = 0; i <= n; i++)
    {
        sum = (sum + dp[i][minProfit]) % mod;
    }
    return sum;
}

int main()
{
    int n, minProfit;
    cin >> n >> minProfit;
    int group_n;
    cin >> n;
    vector<int> group(n), profit(n);
    for (int &ele : group)
        cin >> ele;

    for (int &ele : profit)
        cin >> ele;
    profitableSchemes(n, minProfit, group, profit);
}