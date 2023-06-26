#include "iostream"
#include "vector"

using namespace std;

int numWays(int target_idx, int word_idx, vector<vector<int>> &dp, vector<string> &words, string target)
{
    if (dp[target_idx][word_idx] > 0)
        return dp[target_idx][word_idx];
    if (target_idx == target.size())
        return 1;
    if (word_idx == words[0].size())
        return 0;
    int ans = 0;
    for (int i = 0; i < words.size(); i++)
    {
        if (words[i][word_idx] == target[target_idx])
            ans += numWays(target_idx + 1, word_idx + 1, dp, words, target);
    }
    ans += numWays(target_idx, word_idx + 1, dp, words, target);
    dp[target_idx][word_idx] = ans;
    return ans;
}

int numWays(vector<string> &words, string target)
{
    vector<vector<int>> dp(target.size(), vector<int>(words[0].size()));
    return numWays(0, 0, dp, words, target);
}

int main()
{
    int n;
    cin >> n;
    vector<string> words(n);
    for (string &ele : words)
        cin >> ele;
    string target;
    cin >> target;
    numWays(words, target);
}