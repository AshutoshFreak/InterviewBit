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
    ListNode* swapListNodesInPairs(ListNode* A)
    {
        ListNode* finalList = new ListNode(0);
        finalList->next = A;
        ListNode* prev_prev = finalList;
        ListNode* prev = A;
        ListNode* curr = A->next;
        while(curr != NULL)
        {
            prev_prev->next = curr;
            prev->next = curr->next;
            curr->next = prev;
            if(prev->next != NULL)
            {
                prev_prev = prev;
                curr = curr->next->next->next;
                prev = prev->next;
            }
            else
                break;  
        }
        return finalList->next;
    }
};


int main()
{
    vector<int> L = {1,2,3};
    ListNode* A = new ListNode(L[0]);
    ListNode* temp = A;
    for(int i = 1; i < L.size(); i++)
    {
        temp->next = new ListNode(L[i]);
        temp = temp->next;
    }
    Solution* s = new Solution();
    A = s->swapListNodesInPairs(A);
    while(A != NULL)
    {
        cout << A->val << "\n";
        A = A->next;
    }
}