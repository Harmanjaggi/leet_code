#include "iostream"
#include "vector"
#include "unordered_map"

using namespace std;

int ways(int r, int c, vector<string>& &pizza, int k) {
    
}

int ways(vector<string> &pizza, int k)
{

}

int main()
{
    int n;
    cin >> n;
    vector<string> pizza(n);
    for(string& ele: pizza)
        cin >> ele;
    cin >> n;
    cout << ways(pizza, n);
}