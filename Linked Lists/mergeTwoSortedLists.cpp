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
    ListNode* mergeTwoSortedLists(ListNode* A, ListNode* B)
    {
        ListNode* finalList = new ListNode(0);
        ListNode* finalList_start = finalList;
        ListNode* curr_A = A;
        ListNode* curr_B = B;
        while(curr_A != NULL && curr_B != NULL)
        {
            if(curr_A->val < curr_B->val)
            {
                finalList->next = new ListNode(curr_A->val);
                curr_A = curr_A->next;
            }
            else
            {
                finalList->next = new ListNode(curr_B->val);
                curr_B = curr_B->next;
            }
            finalList = finalList->next;
        }
        while(curr_A != NULL)
        {
            finalList->next = new ListNode(curr_A->val);
            finalList = finalList->next;
            curr_A = curr_A->next;
        }
        while(curr_B != NULL)
        {
            finalList->next = new ListNode(curr_B->val);
            finalList = finalList->next;
            curr_B = curr_B->next;
        }
        return finalList_start->next;
    }
};


int main()
{
    vector<int> L = {5};
    ListNode* A = new ListNode(L[0]);
    ListNode* temp = A;
    for(int i = 1; i < L.size(); i++)
    {
        temp->next = new ListNode(L[i]);
        temp = temp->next;
    }

    L = {4};
    ListNode* B = new ListNode(L[0]);
    temp = B;
    for(int i = 1; i < L.size(); i++)
    {
        temp->next = new ListNode(L[i]);
        temp = temp->next;
    }

    Solution* s = new Solution();
    A = s->mergeTwoSortedLists(A, B);
    while(A != NULL)
    {
        cout << A->val << "\n";
        A = A->next;
    }
}