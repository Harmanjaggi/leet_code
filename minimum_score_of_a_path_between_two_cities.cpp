#include "iostream"
#include "vector"
#include "unordered_map"
#include "unordered_set"
#include "queue"

using namespace std;

vector<int> parent;
vector<int> road;

int minScore(int n, vector<vector<int>> &roads)
{
    unordered_map<int, unordered_map<int, int>> graph;
    for (auto &road : roads)
    {
        int u = road[0], v = road[1], w = road[2];
        graph[u][v] = graph[v][u] = w;
    }
    int res = numeric_limits<int>::max();
    unordered_set<int> visited;
    queue<int> q;
    q.push(1);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto&[adj, score] : graph[node]) {
            if(!visited.count(adj)){
                q.push(adj);
                visited.insert(adj);
            }
            res = min(res, score);
        }
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n, vector<int>(3));
    for (auto &v : g)
        cin >> v[0] >> v[1] >> v[2];
    cin >> n;
    minScore(n, g);
}