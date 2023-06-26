#include "iostream"
#include "vector"
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    for (int i = 1; i < intervals.size(); i++) {
        if(intervals[i-1][1] >= intervals[i][0]) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            intervals.erase(intervals.begin() + i);
            i--;
            intervals[i][0] = min(start, intervals[i][0]);
            intervals[i][1] = max(end, intervals[i][1]);
        }
    }
    return intervals;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> nums(n, vector<int>(2));
    for (auto &ele : nums)
        cin >> ele[0] >> ele[1];
    merge(nums);
}