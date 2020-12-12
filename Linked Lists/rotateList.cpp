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
    ListNode* rotateList(ListNode* A, int B)
    {
        ListNode* curr = A;
        int n = 1;
        while(curr->next != NULL)
        {
            curr = curr->next;
            n++;
        }
        B = B%n;
        int breakLink = n-B;
        curr->next = A;
        n = 0;
        ListNode* prev = curr;
        while(n != breakLink)
        {
            A = A->next;
            prev = prev->next;
            n++;
        }
        prev->next = NULL;
        return A;
    }
};

int main()
{
    vector<int> L = {1,2,3,4,5};
    int B = 6;
    ListNode* A = new ListNode(L[0]);
    ListNode* temp = A;
    for(int i = 1; i < L.size(); i++)
    {
        temp->next = new ListNode(L[i]);
        temp = temp->next;
    }
    Solution* s = new Solution();
    A = s->rotateList(A, B);
    while(A != NULL)
    {
        cout << A->val << "\n";
        A = A->next;
    }
}