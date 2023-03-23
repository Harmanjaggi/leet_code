#include <iostream>
#include <string>
using namespace std;

bool isDigit(char ch)
{
    return ch <= '9' && ch >= '0';
}

int myAtoi(string s)
{
    int i = 0;
    long long ans = 0;
    while (i < s.length())
    {
        if (!isDigit(s[i]) && s[i] != '+' && s[i] != '-' && s[i] != ' ')
            return 0;
        if (s[i] == '-')
        {
            i++;
            if (isDigit(s[i]))
            {
                while (isDigit(s[i]))
                {
                    ans = ans * 10 - (s[i++] - '0');
                    if (ans < INT32_MIN)
                        return INT32_MIN;
                }
                return (int)ans;
            }
            else
                return 0;
        }
        if (s[i] == '+')
        {
            i++;
            if (isDigit(s[i]))
            {
                while (isDigit(s[i]))
                {
                    ans = ans * 10 + (s[i++] - '0');
                    if (ans > INT32_MAX)
                        return INT32_MAX;
                }
                return (int)ans;
            }
            else
                return 0;
        }
        if (isDigit(s[i]))
        {
            while (isDigit(s[i]))
            {
                ans = ans * 10 + (s[i++] - '0');
                if (ans > INT32_MAX)
                    return INT32_MAX;
            }
            return (int)ans;
        }
        i++;
    }
    return (int)ans;
}

int main()
{
    string str;
    getline(cin, str);
    cout << myAtoi(str);
}