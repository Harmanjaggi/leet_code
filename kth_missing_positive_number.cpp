#include <iostream>
#include <vector>
using namespace std;

void display(vector<int> &arr)
{
    for (int ele : arr)
        cout << ele << " ";
    cout << endl;
}

int findKthPositive(vector<int> &arr, int k)
{
    int sol = 0;
    vector<int> diff(arr.size());
    diff[0] = arr[0] - 1;
    int sum = arr[0] - 1;
    for (int i = 1; i < arr.size(); i++)
    {
        diff[i] = arr[i] - arr[i - 1] - 1;
        sum += arr[i] - arr[i - 1] - 1;
        if (sum > k)
            break;
    }
    int i = 0;
    for (; i < diff.size(); i++)
    {
        if (diff[i] > k)
            break;
        else
            k -= diff[i];
    }
    display(diff);
    cout << i << ":::" << k << "  " << arr[i - 1] << endl;

    if (i == 0)
        return k;
    if (k == 0)
        if (diff[i - 1] == 0)
            return arr[i - 1] - 2;
        else
            return arr[i - 1] - 1;
    return arr[i - 1] + k;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &ele : arr)
        cin >> ele;
    cin >> n;
    cout << findKthPositive(arr, n);
}