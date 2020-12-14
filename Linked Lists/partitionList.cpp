#include<iostream>
#include<vector>

using namespace std;

class ListNode
{
    public:
    ListNode* next;
    int val;
    ListNode(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

class Solution
{
    public:
    ListNode* partitionList(ListNode* A, int B)
    {
        ListNode *prev, *curr, *less_head, *less_tail;
        less_head = new ListNode(0);
        less_head->next = A;
        A = less_head;
        less_head = new ListNode(0);
        less_tail = less_head;
        curr = A->next;
        prev = A;
        while(curr != NULL)
        {
            if(curr->val < B)
            {
                less_tail->next = curr;
                prev->next = curr->next;
                curr->next = NULL;
                curr = prev->next;
                less_tail = less_tail->next;
            }
            else
            {
                curr = curr->next;
                prev = prev->next;
            }
        }
        less_tail->next = A->next;
        return less_head->next;
    }
};

int main()
{
    vector<int> L = {1,4,3,2,5,2};
    int B = 3;
    ListNode* A = new ListNode(L[0]);
    ListNode* temp = A;
    for(int i = 1; i < L.size(); i++)
    {
        temp->next = new ListNode(L[i]);
        temp = temp->next;
    }
    Solution* s = new Solution();
    A = s->partitionList(A, B);
    while(A != NULL)
    {
        cout << A->val << "\n";
        A = A->next;
    }
}