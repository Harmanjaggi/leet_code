#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            ans.push_back({i, j});
        }
    }
    return ans;
}
int main()
{
    int n1, n2;
    cin >> n1 >> n2;
    combine(n1, n2);
}