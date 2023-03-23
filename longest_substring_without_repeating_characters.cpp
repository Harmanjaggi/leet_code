#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

void display(set<char> s)
{
    for (auto ele : s)
        cout << ele;
    cout << endl;
}

int lengthOfLongestSubstring(string s)
{
    int max_val = 0;
    int first_element = 0;
    set<char> set1;
    for (int i = 0; i < s.length(); i++)
    {
        while (set1.count(s[i]) != 0)
            set1.erase(s[first_element++]);
        set1.insert(s[i]);
        max_val = max(max_val, (int)set1.size());
    }
    return max_val;
}

int main()
{
    string s;
    cin >> s;
    cout << lengthOfLongestSubstring(s);
}