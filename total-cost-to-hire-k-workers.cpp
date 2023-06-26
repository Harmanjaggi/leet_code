#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long long totalCost(vector<int>& costs, int k, int candidates) {
    priority_queue<int, vector<int>, greater<int>> q1, q2;
    int i = 0, j = costs.size() - 1;
    long long ans = 0;
    while(k--) {
        while(q1.size() < candidates && i <= j){
            q1.push(costs[i++]);
        }
        while(q2.size() < candidates && i <= j){
            q2.push(costs[j--]);
        }
        
        int t1 = q1.size() ? q1.top() : INT_MAX;
        int t2 = q2.size() ? q2.top() : INT_MAX;

        auto& q = t1 <= t2 ? q1 : q2;
        ans += q.top();
        q.pop();
    }
    return ans;
}

int main() {
    vector<int> t{17, 12, 10, 2, 7, 2, 11, 20, 8};
    cout << totalCost(t, 3, 4);
    return 0;
}