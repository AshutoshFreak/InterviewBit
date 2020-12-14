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
    ListNode* reverseLinkListII(ListNode* A, int m, int n)
    {
        int count = 0;
        ListNode *from, *to, *curr, *prev, *nxt;
        curr = A;
        while(curr != NULL)
        {
            count++;
            if(count == m-1)
            {
                from = curr;
                prev = curr->next;
                curr = prev->next;
                nxt = curr->next;
                while(count != n-1)
                {
                    curr->next = prev;
                    prev = curr;
                    curr = nxt;
                    nxt = nxt->next;
                    count++;
                }
                from->next->next = curr;
                from->next = prev;
            }
            curr = curr->next;
        }
        return A;
    }
};


int main()
{
    vector<int> L = {1,2,3,4};
    int m = 1;
    int n = 2;
    ListNode* A = new ListNode(L[0]);
    ListNode* temp = A;
    for(int i = 1; i < L.size(); i++)
    {
        temp->next = new ListNode(L[i]);
        temp = temp->next;
    }
    Solution* s = new Solution();
    A = s->reverseLinkListII(A, m, n);
    while(A != NULL)
    {
        cout << A->val << "\n";
        A = A->next;
    }
}