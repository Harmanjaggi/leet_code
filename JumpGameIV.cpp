#include <iostream>
#include <map>
#include <vector>
using namespace std;

int minJumps(vector<int> &arr, int )

int minJumps(vector<int> &arr)
{
    map<int, vector<int>> similarIndex;
    for (int i = 0; i < arr.size(); i++)
        similarIndex[arr[i]].push_back(i);
    
    
}
int main()
{
    int n;
    vector<int> nums(n);
    cin >> n;
    for (int &ele : nums)
        cin >> ele;
    cout << minJumps(nums);
}