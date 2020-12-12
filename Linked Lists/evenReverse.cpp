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
    ListNode* evenReverse(ListNode* A)
    {
        int i;
        vector<int> evenList{};
        vector<int> oddList{};
        int count = 1;
        ListNode* L = A;
        while(L != NULL)
        {
            if(count % 2 == 0)
                evenList.push_back(L->val);
            else
                oddList.push_back(L->val);
            count++;
            L = L->next;
        }
        reverse(evenList.begin(), evenList.end());
        count = 0;
        ListNode* finalList = new ListNode(0);
        L = finalList;
        for(i = 0; i < evenList.size(); i++)
        {
            L->next = new ListNode(oddList[i]);
            L = L->next;
            L->next = new ListNode(evenList[i]);
            L = L->next;
        }
        if (oddList.size() > evenList.size())
            L->next = new ListNode(oddList[i]);
        return finalList->next;
    }
};

int main()
{
    vector<int> L = {1};
    ListNode* A = new ListNode(L[0]);
    ListNode* temp = A;
    for(int i = 1; i < L.size(); i++)
    {
        temp->next = new ListNode(L[i]);
        temp = temp->next;
    }
    Solution* s = new Solution();
    A = s->evenReverse(A);
    while(A != NULL)
    {
        cout << A->val << "\n";
        A = A->next;
    }
}