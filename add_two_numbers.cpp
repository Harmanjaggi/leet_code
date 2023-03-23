#include <iostream>
#include <stack>
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

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    if (l1 == nullptr)
        return l2;
    else if (l2 == nullptr)
        return l1;
    else
    {
        ListNode *head = new ListNode();
        ListNode *curr = head;
        bool carry = 0;
        while (l1 != nullptr || l2 != nullptr)
        {
            int value = carry;
            value += l1 != nullptr ? l1->val : 0;
            value += l2 != nullptr ? l2->val : 0;
            if (value >= 10)
                value %= 10, carry = 1;
            else
                carry = 0;
            curr->next = new ListNode(value);
            curr = curr->next;
            // cout << value << " " << carry << " " << l1->val << " " << l2->val << endl;
            if (l1 != nullptr)
                l1 = l1->next;
            if (l2 != nullptr)
                l2 = l2->next;
        }
        return head->next;
    }
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
    display(addTwoNumbers(list1, list2));
}