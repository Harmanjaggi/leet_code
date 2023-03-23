#include <iostream>
#include <vector>
using namespace std;

void display(vector<string> arr)
{
    for (string ele : arr)
        cout << ele << endl;
    cout << endl;
}
void generateParenthesis(int open, int close, string str, vector<string> &ans)
{
    if (open == 0 && close == 0)
        ans.push_back(str);
    if (open >= 0)
        generateParenthesis(open - 1, close, str + "(", ans);
    if (close > open)
        generateParenthesis(open, close - 1, str +")", ans);
}

vector<string> generateParenthesis(int n)
{
    vector<string> ans;
    generateParenthesis(n, n, "", ans);
    return ans;
}
int main()
{
    int n;
    cin >> n;
    display(generateParenthesis(n));
}