#include <iostream>
#include <vector>
#include <set>
using namespace std;
//! not completed
string longestPalindrome(string s)
{
    int center_pos = 0;
    int start = 0, end = 0;
    while (center_pos < s.length())
    {
        // for odd palindrome
        int extend = 0;
        while ((center_pos - extend) >= 0 && (center_pos + extend) < s.length())
        {
            if (s[center_pos - extend] != s[center_pos + extend])
                break;
            if (end - start + 1 < extend * 2 + 1)
            {
                start = center_pos - extend;
                end = center_pos + extend;
            }
            extend++;
        }
        // for even palindrome
        extend = 0;
        while (center_pos - extend >= 0 && center_pos + extend + 1 < s.length())
        {
            
        }
        
        center_pos++;
    }
    return s.substr(start, end + 1);
}

int main()
{
    string s;
    cin >> s;
    cout << longestPalindrome(s);
}