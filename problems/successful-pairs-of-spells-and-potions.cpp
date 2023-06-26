#include "iostream"
#include "vector"
#include "algorithm"
#include "unordered_map"

using namespace std;

int binarySearch(vector<int> &potions, long long spell, long long target)
{
    int lo = 0, hi = potions.size() - 1, bestIdx = potions.size();
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (potions[mid] * spell >= target)
        {
            bestIdx = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    return (potions.size() - bestIdx);
}

vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
{
    sort(potions.begin(), potions.end());
    vector<int> ans(spells.size());
    for (int i = 0; i < spells.size(); i++)
        ans[i] = binarySearch(potions, spells[i], success);
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> spells(n);
    for (int &ele : spells)
        cin >> ele;
    cin >> n;
    vector<int> potions(n);
    for (int &ele : potions)
        cin >> ele;
    cin >> n;
    successfulPairs(spells, potions, n);
}