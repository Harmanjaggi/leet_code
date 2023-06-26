#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DSU
{
public:
    vector<int> Parent, Rank;
    DSU(int n)
    {
        Parent.resize(n);
        Rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            Parent[i] = i;
    }
    int Find(int x)
    {
        return Parent[x] = Parent[x] == x ? x : Find(Parent[x]);
    }

    bool Union(int x, int y)
    {
        int xset = Find(x), yset = Find(y);
        if (xset != yset)
        {
            Rank[xset] < Rank[yset] ? Parent[xset] = yset : Parent[yset] = xset;
            Rank[xset] += Rank[xset] == Rank[yset];
            return true;
        }
        return false;
    }
};
class Solution
{
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>> &edgeList, vector<vector<int>> &queries)
    {
        DSU dsu(n);
        for (int i = 0; i < queries.size(); i++)
            queries[i].push_back(i);
        sort(queries.begin(), queries.end(), [&](auto const &a, auto const &b)
             { return a[2] < b[2]; });
        sort(edgeList.begin(), edgeList.end(), [&](auto const &a, auto const &b)
             { return a[2] < b[2]; });
        int i = 0;
        vector<bool> res(queries.size(), false);
        for (auto q : queries)
        {
            while (i < edgeList.size() && edgeList[i][2] < q[2])
            {
                dsu.Union(edgeList[i][0], edgeList[i][1]);
                i++;
            }
            if (dsu.Find(q[0]) == dsu.Find(q[1]))
                res[q[3]] = true;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    int n;
    cin >> n;
    int edge_num, queries_num;
    cin >> edge_num >> queries_num;
    vector<vector<int>> edgeList(edge_num, vector<int>(3)), queries(queries_num, vector<int>(3));
    for (auto &edge : edgeList)
        for (int &ele : edge)
            cin >> ele;
    for (auto &querie : queries)
        for (int &ele : querie)
            cin >> ele;
    vector<bool> ans = sol.distanceLimitedPathsExist(n, edgeList, queries);
    for(bool ele: ans)
        cout << (ele ? "true" : "false") << ", ";
}