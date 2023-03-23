#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

void display(vector<int> &arr)
{
    for (int ele : arr)
        cout << ele << " ";
    cout << endl;
}

void display(set<int> s)
{
    for (auto ele : s)
        cout << ele << " ";
    cout << endl;
}

set<int> prime_factor_set;
void primeFactors(int n)
{
    if (n == 1)
        return;
    while (n % 2 == 0)
    {
        prime_factor_set.insert(2);
        n = n / 2;
    }

    for (int i = 3; i * i <= n; i = i + 2)
    {
        while (n % i == 0)
        {
            prime_factor_set.insert(i);
            n = n / i;
        }
    }
    if (n > 2)
        prime_factor_set.insert(n);
}

long long search(int lo, int hi, long long target, vector<int> &time)
{
    int ans = 0;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        long long sum = 0;
        for (int ele : time)
            sum += mid / ele;
        if (sum >= target)
        {
            ans = mid;
            hi = mid - 1;
        }
        else if (sum < target)
            lo = mid + 1;
    }
    if(ans == 0)
        return hi;
    return ans;
}
// long long prime_factor = 1, total_trips = 0, ans = 0;
// for (int ele : time)
//     primeFactors(ele);
// for(int ele: prime_factor_set)
//     prime_factor *= ele;
// //till prime_factor
// for(int ele : time)
//     total_trips += prime_factor / ele;

// if(totalTrips > total_trips)
//     ans += totalTrips / total_trips;
// totalTrips %= total_trips;
long long minimumTime(vector<int> &time, int totalTrips)
{
    // if (time.size() == 1)
    //     return time[0] * totalTrips;

    int min_num = INT_MAX;
    for (int ele : time)
    {
        if (ele < min_num)
            min_num = ele;
    }
    int ans = search(1, totalTrips * min_num, totalTrips, time);
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &ele : arr)
        cin >> ele;
    cin >> n;
    cout << minimumTime(arr, n);
}