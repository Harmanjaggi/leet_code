#include "iostream"
#include "vector"
#include "queue"
#include "unordered_set"

using namespace std;

int ans = -1;

void dfs(int node, int distance, vector<int>& dist_node, vector<int> &adj, vector<bool> &vis, vector<bool> &extra)
{
    if (node != -1)
    {
        if (!vis[node])
        {
            vis[node] = true;
            extra[node] = true;
            dist_node[node] = distance;
            dfs(adj[node], distance + 1, dist_node, adj, vis, extra);
        }
        else if (extra[node])
            ans = max(ans, distance - dist_node[node]);
        extra[node] = false;
    }
}
int longestCycle(vector<int> &edges)
{
    int n = edges.size();
    vector<bool> vis(n);
    vector<bool> extra(n);
    vector<int> dist_node(n);
    for (int i = 0; i < n; i++)
        dfs(i, 0, dist_node, edges, vis, extra);
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int &ele : vec)
        cin >> ele;
    longestCycle(vec);
}