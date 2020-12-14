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
    ListNode* sortPartList(ListNode* A, ListNode* start, ListNode* end)
    {
        if(start->next == end)
            return start;
        ListNode *pad = new ListNode(0);
        pad->next = A;
        ListNode *curr = start->next;
        ListNode *prev = start;
        while(curr != end)
        {
            if(curr->val < start->val)
            {
                prev->next = curr->next;
                curr->next = pad->next;
                pad->next = curr;
                curr = prev->next;
            }
            else
            {
                curr = curr->next;
                prev = prev->next;
            }
        }
        sortPartList(A, pad->next, A);
        sortPartList(A, A->next, end);
        return pad->next;
    }
    ListNode* sortList(ListNode* A)
    {
        return sortPartList(A, A, NULL);
        
    }
};


int main()
{
    vector<int> L = {8,6,2,3,6,8};
    ListNode* A = new ListNode(L[0]);
    ListNode* temp = A;
    for(int i = 1; i < L.size(); i++)
    {
        temp->next = new ListNode(L[i]);
        temp = temp->next;
    }
    Solution* s = new Solution();
    A = s->sortList(A);
    while(A != NULL)
    {
        cout << A->val << "\n";
        A = A->next;
    }
}
