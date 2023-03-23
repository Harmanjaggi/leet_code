#include "iostream"
#include "vector"
#include "unordered_map"

using namespace std;

unordered_map<int, string> map = {
    {2, "abc"},
    {3, "def"},
    {4, "ghi"},
    {5, "jkl"},
    {6, "mno"},
    {7, "pqrs"},
    {8, "tuv"},
    {9, "wxyz"},
};

void display(vector<string> vec)
{
    for (string str : vec)
        cout << str << " ";
    cout << endl;
}

void letterCombinations(string &digits, vector<string> &res, int i, string s)
{
    if (i == digits.length())
    {
        res.push_back(s);
        return;
    }
    string val = map[digits[i] - '0'];
    for (int j = 0; j < val.length(); j++)
        letterCombinations(digits, res, i + 1, s + val[j]);
}

vector<string> letterCombinations(string digits)
{
    if(digits.empty())
        return {};
    vector<string> vec;
    letterCombinations(digits, vec, 0, "");
    return vec;
}

int main()
{
    string str;
    cin >> str;
    display(letterCombinations(str));
}