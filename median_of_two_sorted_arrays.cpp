#include <iostream>
#include <vector>
#include <set>
using namespace std;

void display(vector<int> &num)
{
    for (int ele : num)
        cout << ele << " ";
    cout << endl;
}

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int i = 0, j = 0;
    vector<int> merge;
    while (i < nums1.size() || j < nums2.size())
    {
        int val_1 = i < nums1.size() ? nums1[i] : INT_MAX;
        int val_2 = j < nums2.size() ? nums2[j] : INT_MAX;
        if (val_1 < val_2)
            merge.push_back(val_1), i++;
        else
            merge.push_back(val_2), j++;
    }
    if (merge.size() % 2)
        return (double)merge[merge.size() / 2];
    else
        return (double)(merge[merge.size() / 2] + merge[merge.size() / 2 - 1]) / 2;
}

int main()
{
    int n;
    cin >> n;
    vector<int> num1(n);
    for (int &ele : num1)
        cin >> ele;
    cin >> n;
    vector<int> num2(n);
    for (int &ele : num2)
        cin >> ele;
    cout << findMedianSortedArrays(num1, num2);
}