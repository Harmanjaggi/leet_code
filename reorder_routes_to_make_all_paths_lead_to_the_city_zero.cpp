#include "iostream"
#include "vector"
#include "queue"
#include "unordered_set"

using namespace std;

int minReorder(int n, vector<vector<int>> &con)
{
    vector<vector<int>> towards_0(n), away_from_0(n);
    vector<bool> vis(n);
    vis[0] = true;
    for (auto a : con)
    {
        towards_0[a[1]].push_back(a[0]);
        away_from_0[a[0]].push_back(a[1]);
    }
    int ans = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int a = q.front();
        q.pop();
        vis[a] = true;
        for (int no : away_from_0[a])
        {
            if (!vis[no])
            {
                ans++;
                q.push(no);
            }
        }
        for (int no : towards_0[a])
        {
            if (!vis[no])
            {
                ans++;
                q.push(no);
            }
        }
    }
    return ans;
}

int main()
{
    int n, n1;
    cin >> n >> n1;
    vector<vector<int>> arr(n1, vector<int>(2));
    for (auto &vec : arr)
        cin >> vec[0] >> vec[1];
    minReorder(n, arr);
}