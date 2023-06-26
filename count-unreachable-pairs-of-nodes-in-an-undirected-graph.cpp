#include "iostream"
#include "vector"
#include "queue"
#include "unordered_set"

using namespace std;

vector<bool> vis;
vector<vector<int>> adj;
void dfs(int src, int &size)
{
    vis[src] = true;
    size++;
    for (int v : adj[src])
        if (!vis[v])
            dfs(v, size);
}
long long countPairs(int n, vector<vector<int>> &edges)
{
    vis.resize(n);
    adj.resize(n);
    for (auto edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    long long ans = 0, rem = n;
    for (int i = 0; i < adj.size(); i++)
        if (!vis[i])
        {
            int size = 0;
            dfs(i, size);
            ans += (rem - size) * size;
            rem -= size;
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
    countPairs(n, arr);
}