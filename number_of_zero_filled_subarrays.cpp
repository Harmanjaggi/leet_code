#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

void display(vector<int> arr)
{
    for (int ele : arr)
        cout << ele << " ";
    cout << endl;
}

long long zeroFilledSubarray(vector<int> &nums)
{
    long long sum = 0;
    long long counter = 0;
    for (int curr = 0; curr < nums.size(); curr++)
    {
        if (nums[curr] == 0)
            counter++;
        else
        {
            sum += (counter * (counter + 1)) / 2;
            counter = 0;
        }
    }
    if (counter)
    {
        sum += (counter * (counter + 1)) / 2;
        counter = 0;
    }
    return sum;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &ele : arr)
        cin >> ele;
    cout << zeroFilledSubarray(arr);
}