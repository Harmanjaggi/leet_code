#include <iostream>
#include <vector>

using namespace std;

int lps(string &s)
{
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n));
    for (int g = 0; g < n; g++)
    {
        for (int r = 0, c = g; r < n && c < n; r++, c++)
        {
            if (g == 0)
                dp[r][c] = 1;
            else
            {
                if (s[r] == s[c])
                    dp[r][c] = dp[r + 1][c - 1] + 2;
                else
                    dp[r][c] = max(dp[r + 1][c], dp[r][c - 1]);
            }
        }
    }
    return dp[0][n - 1];
}

int minInsertions(string &s)
{
    int val = lps(s);
    return s.size() - val;
}

int main()
{
    string s;
    minInsertions(s);
}