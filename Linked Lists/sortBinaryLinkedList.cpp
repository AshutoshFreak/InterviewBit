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
    ListNode* sortBinaryLinkedList(ListNode* A)
    {
        int i;
        ListNode* curr = A->next;
        ListNode* prev = A;
        ListNode* start = A;
        while(curr != NULL)
        {
            if(curr->val == 0)
            {
                prev->next = curr->next;
                curr->next = start;
                start = curr;
                curr = prev->next;
            }
            else
            {
                curr = curr->next;
                prev = prev->next;
            }
        }
        return start;
    }
};

int main()
{
    vector<int> L = {1,0,0,1,1,0,0,1};
    ListNode* A = new ListNode(L[0]);
    ListNode* B = A;
    for(int i = 1; i < L.size(); i++)
    {
        B->next = new ListNode(L[i]);
        B = B->next;
    }
    Solution* s = new Solution();
    A = s->sortBinaryLinkedList(A);
    while(A != NULL)
    {
        cout << A->val << "\n";
        A = A->next;
    }
}