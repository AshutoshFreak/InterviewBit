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
    ListNode* removeDuplicatesFromSortedListII(ListNode* A)
    {
        ListNode *k = new ListNode(0);
        k->next = A;
        ListNode *curr, *nxt;
        curr = A;
        nxt = A->next;
        A = k;
        while(nxt != NULL)
        {
            if(curr->val != nxt->val)
            {
                k->next = curr;
                k = curr;
                curr = nxt;
                nxt = nxt->next;
            }
            else
            {
                while(nxt != NULL && curr->val == nxt->val)
                    nxt = nxt->next;
                curr = nxt;
                if(nxt != NULL)
                    nxt = nxt->next;   
            }
        }
        k->next = curr;
        return A->next;
    }
};


int main()
{
    vector<int> L = {3,3,3,4,6,7,7,8,8,8,8};
    ListNode* A = new ListNode(L[0]);
    ListNode* temp = A;
    for(int i = 1; i < L.size(); i++)
    {
        temp->next = new ListNode(L[i]);
        temp = temp->next;
    }
    Solution* s = new Solution();
    A = s->removeDuplicatesFromSortedListII(A);
    while(A != NULL)
    {
        cout << A->val << "\n";
        A = A->next;
    }
}
