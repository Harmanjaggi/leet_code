#include "iostream"
#include "vector"
#include "unordered_map"

using namespace std;

int largestPathValue(string colors, vector<vector<int>> &edges)
{
    vector<vector<int>> g(colors.size()), count(colors.size(), vector<int>(26));
    vector<int> indegrees(colors.size());
    for (auto &e : edges)
    {
        g[e[0]].push_back(e[1]);
        ++indegrees[e[1]];
    }
    vector<int> q;
    for (int i = 0; i < colors.size(); ++i)
        if (indegrees[i] == 0)
            q.push_back(i);
    int res = 0, processed = 0;
    while (!q.empty())
    {
        vector<int> q1;
        for (auto i : q)
        {
            ++processed;
            res = max(res, ++count[i][colors[i] - 'a']);
            for (auto j : g[i])
            {
                for (auto k = 0; k < 26; ++k)
                    count[j][k] = max(count[j][k], count[i][k]);
                if (--indegrees[j] == 0)
                    q1.push_back(j);
            }
        }
        swap(q, q1);
    }
    return processed != colors.size() ? -1 : res;
}

int main()
{
    string colors;
    cin >> colors;
    int n;
    cin >> n;
    vector<vector<int>> edges(n, vector<int>(2));
    for (auto &edge : edges)
        cin >> edge[0] >> edge[1];
    largestPathValue(colors, edges);
}