#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int binarySearch(int lo, int hi, int target, vector<int> &piles)
{
    int ans = 0;
    while (lo <= hi)
    {
        int mid = (hi + lo) / 2;
        long long hours = 0;
        for (int ele : piles)
            hours += ceil((double) ele / mid);
        if (hours <= target)
        {
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    return ans;
}
int minEatingSpeed(vector<int> &piles, int h)
{
    int max_num = INT_MIN;
    for (int ele : piles)
        max_num = max(max_num, ele);
    return binarySearch(1, max_num, h, piles);
}

int main()
{
    int n;
    cin >> n;
    vector<int> piles(n);
    for (int &ele : piles)
        cin >> ele;
    cin >> n;
    cout << minEatingSpeed(piles, n);
}