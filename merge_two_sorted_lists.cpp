#include <iostream>
#include <stack>
#include <vector>
using namespace std;
//! insert code
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *head = new ListNode(-1);
        ListNode *curr = head;
        while (true)
        {
            int min_num = INT_MAX, min_index = -1, check = 0;
            for (int i = 0; i < lists.size(); i++)
            {
                if (lists[i] == nullptr)
                {
                    check++;
                    continue;
                }
                if (lists[i]->val < min_num)
                {
                    min_num = lists[i]->val;
                    min_index = i;
                }
            }
            if (check == lists.size())
                break;
            curr->next = new ListNode(min_num);
            curr = curr->next;
            lists[min_index] = lists[min_index]->next;
        }

        return head->next;
    }
};

// bool check(ListNode *head, int k)
// {
//     for (int i = 0; i < k; i++)
//     {
//         if (head != nullptr)
//             head = head->next;
//         else
//             return false;
//     }
//     return true;
// }

// ListNode *reverseKGroup(ListNode *head, int k)
// {
//     if (k < 2 || head == nullptr || head->next == nullptr)
//         return head;
//     ListNode *curr = head;
//     bool isStart = true;
//     if (k == 2)
//     {
//         ListNode *start = curr;
//         ListNode *prev = curr;
//         ListNode *next_node = curr->next->next;
//         curr = curr->next;
//         while (curr != nullptr)
//         {
//             //assign
//             curr->next = prev;
//             prev->next = next_node;
//             //set head
//             if(isStart)
//                 isStart = false, head = curr;
//             //assign for future
//             prev = curr->next;
//             curr = next_node;
//             next_node = next_node->next;
//         }
//     }
//     while (curr != nullptr)
//     {
//         if (!check(curr, k))
//             break;
//         ListNode *start = curr;
//         ListNode *prev = curr;
//         ListNode *next_node = curr->next->next;
//         curr = curr->next;
//         //group
//         for (int i = 1; i < k; i++)
//         {
//             //assign
//             curr->next = prev;
//             prev = curr;
//             //assign for future
//             curr = next_node;
//             next_node = next_node->next;
//         }
//         start->next = next_node;
//         if (isStart)
//             head = curr, isStart = false;
//     }
//     return head;
// }
ListNode *th = nullptr;
ListNode *tt = nullptr;
void addFirstNode(ListNode* node) {
    if(th == nullptr) {
        th = node;
        tt = node;
    } else {
        node->next = th;
        tt = node;
    }
}

int length(ListNode* node) {
    ListNode *curr = node;
    int len = 0;
    while (curr != nullptr)
    {
        curr = curr->next;
        len++;
    }
    return len;
}

    ListNode *reverseKGroup(ListNode *head, int k) {
    if (k < 2 || head == nullptr || head->next == nullptr)
        return head;
    int len = length(head);
    ListNode *oh = nullptr;
    ListNode *ot = nullptr;
    ListNode *curr = head;
    while (len >= k)
    {
        int tempk = k;
        while (tempk--)
        {
            ListNode *forw = curr->next;
            curr->next = nullptr;
            addFirstNode(curr);
            curr = forw;
        }
        if(oh == nullptr) {
            oh = th;
            ot = tt;
        } else {
            oh->next = th;
            ot = tt;
        }
        th = nullptr;
        tt = nullptr;
        len -= k;
    }
    ot->next = curr;
    return oh;
}

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (list1 == nullptr)
        return list2;
    if (list2 == nullptr)
        return list1;
    if (list1->val > list2->val)
    {
        swap(list1, list2);
    }
    ListNode *res = list1;
    while (list1 != nullptr && list2 != nullptr)
    {
        ListNode *tmp = nullptr;
        while (list1 != nullptr && list1->val <= list2->val)
        {
            tmp = list1;
            list1 = list1->next;
        }
        tmp->next = list2;
        swap(list1, list2);
    }
    return res;
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
}

int main()
{
    int n;
    ListNode *list1;
    ListNode *list2;
    cin >> n;
    list1 = insertLinkedList(n);
    cin >> n;
    list2 = insertLinkedList(n);
    display(mergeTwoLists(list1, list2));
}