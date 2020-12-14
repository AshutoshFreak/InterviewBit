#include<iostream>
#include<vector>
#include<cmath>

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
    bool palindromeList(ListNode* A)
    {
        ListNode* end = A;
        ListNode* start = A;
        ListNode* prev = A;
        ListNode* curr = A->next;
        ListNode* nxt;
        int n, mid, i;
        n = 0;
        while(end->next != NULL)
        {
            end = end->next;
            n++;
        }
        if(n == 0)
            return true;
        else if(n == 1)
        {
            if(A->val == A->next->val)
                return true;
            else
                return false;
        }
        mid = n/2;
        nxt = A->next->next;
        for(i = 0; i < mid; i++)
        {
            curr = curr->next;
            prev = prev->next;
            nxt = nxt->next;
        }
        prev->next = NULL;
        for(i = mid; i < n; i++)
        {
            curr->next = prev;
            prev = curr;
            curr = nxt;
            if(nxt != NULL)
                nxt = nxt->next;
        }
        for(i = 0; i <= mid; i++)
        {
            if(start->val != end->val)
                return false;
            start = start->next;
            end = end->next;
        }
        return true;
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
    bool ans = s->palindromeList(A);
    cout << ans;
}