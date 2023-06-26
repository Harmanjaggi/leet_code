#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

void display(vector<string> arr)
{
    for (string ele : arr)
        cout << ele << endl;
    cout << endl;
}

void display1(vector<vector<string>> arr)
{
    for (auto list : arr)
    {
        for (auto ele : list)
            cout << ele << endl;
        cout << endl;
    }
    cout << endl;
}
vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> map;
    for(string str: strs) {
        string sorted_str = str;
        sort(sorted_str.begin(), sorted_str.end());
        map[sorted_str].push_back(str);
    }
    vector<vector<string>> ans;
    for(auto itr: map)
        ans.push_back(itr.second);
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<string> arr(n);
    for (string &ele : arr)
        cin >> ele;
    display1(groupAnagrams(arr));
}