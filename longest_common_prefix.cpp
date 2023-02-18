#include <iostream>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    if(strs.empty())
        return "";
    string sol = "";
    int index = 0;
    while (true)
    {
        if(index >= strs.front().length())
            return sol;
        char ch = strs.front()[index];
        for (int i = 0; i < strs.size(); i++)
        {
            if(index >= strs[i].length() || ch != strs[i][index])
                return sol;
        }
        sol += ch;
        index++;
    }
    
}

int main()
{
    int n;
    cin >> n;
    vector<string> str(n);
    for (int i = 0; i < n; i++)
        cin >> str[i];
    cout << longestCommonPrefix(str);
}