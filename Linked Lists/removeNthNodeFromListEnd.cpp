#include<iostream>
#include<vector>
#include<bits/stdc++.h>

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
    ListNode* removeNthNodeFromListEnd(ListNode* A, int B)
    {
        int n = 0, nthFromEnd;
        ListNode* L = A;
        ListNode* prev;
        while(L != NULL)
        {
            n++;
            L = L->next;
        }
        nthFromEnd = n-B;
        n = 0;
        L = new ListNode(0);
        L->next = A;
        prev = L;
        L = L->next;
        if(nthFromEnd <= 0)
            return A->next;
        while(L != NULL)
        {
            if(n == nthFromEnd)
            {
                prev->next = L->next;
                L->next = L->next;
            }
            else
            {
                L = L->next;
                prev = prev->next;
            }
            n++;
        }
        return A;
    }
};

int main()
{
    vector<int> L = {1};
    int B = 1;
    ListNode* A = new ListNode(L[0]);
    ListNode* temp = A;
    for(int i = 1; i < L.size(); i++)
    {
        temp->next = new ListNode(L[i]);
        temp = temp->next;
    }
    Solution* s = new Solution();
    A = s->removeNthNodeFromListEnd(A, B);
    while(A != NULL)
    {
        cout << A->val << "\n";
        A = A->next;
    }
}