class Solution {
public:
    vector<int> getRow(int numRows) {
        numRows++;
        if(numRows == 0) return {{}};
        vector<vector<int>> ans(numRows);
        ans.front() = {1};
        for(int i = 1;i<numRows;i++){
            auto temp = vector<int>(i + 1);
            temp.front() = 1;
            temp.back() = 1;
            for(int j = 1;j<i;j++){
                temp[j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
            ans[i] = temp;
        }
        return ans.back();
    }
};