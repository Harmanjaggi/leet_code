#include <iostream>
#include <vector>
using namespace std;

void display(vector<int> &arr) {
    for (int &ele : arr)
        cout << ele << endl;
}

int removeElement(vector<int> nums, int val)
{
    for (auto it = nums.begin(); it != nums.end(); it++) {
        if (val == *it) {
            nums.erase(it);
            it--;
        }
    }
    return nums.size();
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &ele : arr)
        cin >> ele;
    cin >> n;
    cout << removeElement(arr, n);
}