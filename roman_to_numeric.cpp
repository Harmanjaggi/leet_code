#include <iostream>
#include <map>
using namespace std;

const map<char, int> m = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000},
};
int romanToInt(string s)
{
    int sol = 0, num = 0;
    for (int i = 0; i < s.length();)
    {
        int s1 = m.at(s[i]), s2 = m.at(s[i+1]);
        if (i == s.length() - 1 || s1 >= s2)
        {
            num = s1;
            i++;
        }
        else
        {
            num = s2 - s1;
            i += 2;
        }
        sol += num;
    }
    return sol;
}

int main()
{
    string str;
    cin >> str;
    cout << romanToInt(str);
}