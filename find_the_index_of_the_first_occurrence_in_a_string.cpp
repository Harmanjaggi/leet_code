#include <iostream>
#include <vector>
using namespace std;

void display(vector<int> v)
{
    for (int ele : v)
        cout << ele << " ";
    cout << endl;
}

vector<int> lps(string s)
{
    int i = 1, len = 0;
    vector<int> lps(s.length());
    while (i < s.length())
    {
        if (s[i] == s[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len > 0)
                len = lps[len - 1];
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

int strStr(string haystack, string needle)
{
    vector<int> index = lps(needle);
    display(index);
    int i = 0, j = 0;
    while (i < haystack.length())
    {
        if(needle[j] == haystack[i])
        {
            if (j == needle.length() - 1)
                return i - needle.length() + 1;
            i++, j++;
        } else {
        if(j == 0)
            i++;
        else
            j = index[j - 1];
        }
    }
    return -1;
}

int main()
{
    string haystack, needle;
    cin >> haystack >> needle;
    cout << strStr(haystack, needle);
}