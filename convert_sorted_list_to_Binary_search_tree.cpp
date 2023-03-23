#include "iostream"
#include "vector"

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    ListNode *head = nullptr;
    ListNode *tail = nullptr;

    void addFirstNode(ListNode *node)
    {
        if (head == nullptr)
        {
            head = node;
            tail = node;
        }
        else
        {
            node->next = head;
            tail = node;
        }
    }

    void addLastNode(ListNode *node)
    {
        if (head == nullptr)
        {
            head = node;
            tail = node;
        }
        else
        {
            node->next = tail;
            head = node;
        }
    }

    int length(ListNode *node)
    {
        ListNode *curr = node;
        int len = 0;
        while (curr != nullptr)
        {
            curr = curr->next;
            len++;
        }
        return len;
    }

public:
    void display(ListNode *list)
    {
        ListNode *curr = list;
        if (curr == nullptr)
            return;
        while (curr != nullptr)
        {
            cout << curr->val << " ";
            curr = curr->next;
        }
        cout << endl;
    }


    ListNode *insertLinkedList(int n)
    {
        ListNode *head = nullptr;
        ListNode *curr = nullptr;
        for (int i = 0; i < n; i++)
        {
            int ele;
            cin >> ele;
            if (head == nullptr)
            {
                head = new ListNode(ele);
                curr = head;
            }
            else
            {
                curr->next = new ListNode(ele);
                curr = curr->next;
            }
        }
        return head;
    }

    TreeNode* sortedListToBST(vector<int>& v, int l, int r) {
        if(l > r)
            return nullptr;
        int mid = l + (r - l) / 2;
        TreeNode *node = new TreeNode(v[mid]);
        node->left = sortedListToBST(v, l, mid - 1);
        node->right = sortedListToBST(v, mid + 1, r);
        return node;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> list;
        ListNode *curr = head;
        while(curr != nullptr) {
            list.push_back(curr->val);
            curr = curr->next;
        }
        return sortedListToBST(list, 0, list.size() - 1);
    }
};

int main()
{
    Solution sol;
    int n;
    ListNode *list;
    cin >> n;
    list = sol.insertLinkedList(n);
    sol.sortedListToBST(list);
}