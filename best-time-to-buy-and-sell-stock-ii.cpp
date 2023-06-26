#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int maxProfit(vector<int> &prices)
{
    stack<int> st;
    int ans = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        if(prices[i-1] < prices[i])
            ans += prices[i] - prices[i - 1];
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> prices(n);
    for (int &ele : prices)
        cin >> ele;
    maxProfit(prices);
}