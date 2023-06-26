#include "iostream"
#include "vector"
#include "unordered_map"

using namespace std;

unordered_map<string, bool> dp;
bool isScramble(string s1, string s2)
{
    int n = s1.size();
    if (n != s2.size())
        return false;
    if (s1 == s2)
        return true;

    if (n == 1)
        return false;

    string key = s1 + " " + s2;

    if(dp.count(key))
        return dp[key];
    
    for (int i = 1; i < n; i++)
    {
        bool withoutswap = isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i));
        if(withoutswap)
            return true;
        bool withswap = isScramble(s1.substr(0, i), s2.substr(n-i)) && isScramble(s1.substr(i), s2.substr(0, n-i));
        if(withswap)
            return true;
    }
    return dp[key] = false;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    isScramble(s1, s2);
}