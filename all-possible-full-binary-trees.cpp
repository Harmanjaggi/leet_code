#include <iostream>
#include <vector>

using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<TreeNode *> solve(int n)
{
    if (n == 1)
        return {new TreeNode()};
    vector<TreeNode *> currList;
    int remainingNodes = n - 1;
    for (int left = 1; left < remainingNodes; left += 2)
    {
        int right = remainingNodes - left;
        vector<TreeNode *> leftList = solve(left);
        vector<TreeNode *> rightList = solve(right);
        for (TreeNode *leftNode : leftList)
        {
            for (TreeNode *rightNode : rightList)
            {
                TreeNode *curr = new TreeNode();
                curr->left = leftNode;
                curr->right = rightNode;
                currList.push_back(curr);
            }
        }
    }
    return currList;
}

vector<TreeNode *> allPossibleFBT(int n)
{
    if (n % 2 == 0)
        return {};
    return solve(n);
}

int main()
{
    allPossibleFBT(7);
}