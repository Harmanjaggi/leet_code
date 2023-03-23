#include "iostream"
#include "vector"
#include "cmath"
using namespace std;

bool canPlaceFlowers(vector<int> &flowerbed, int n)
{
    int sol = 0;
    for (int i = 0; i < flowerbed.size(); i++)
    {
        int no_of_zeros = 0;
        while (i < flowerbed.size() && flowerbed[i] == 0)
            no_of_zeros++, i++;
        if (no_of_zeros > 1 && (i == flowerbed.size() || i - no_of_zeros == 0))
            sol += ceil((double)(no_of_zeros - 1) / 2);
        else if (no_of_zeros > 2)
            sol += ceil((double)(no_of_zeros - 2) / 2);
        cout << i << " :: " << no_of_zeros << "::" << sol << endl;
    }
    return sol >= n;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int &ele : nums)
        cin >> ele;
    cin >> n;
    cout << (canPlaceFlowers(nums, n) ? "true" : "false");
}