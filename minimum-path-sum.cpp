#include "iostream"
#include "vector"

using namespace std;

int minPathSum(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid.front().size();
    for (int i = 1; i < m; i++)
        grid[0][i] += grid[0][i - 1];
    for (int i = 1; i < n; i++)
        grid[i][0] += grid[i - 1][0];
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
    return grid[n - 1][m - 1];
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> vec(n, vector<int>(m));
    for (auto &list : vec)
        for (int &ele : list)
            cin >> ele;
    minPathSum(vec);
}