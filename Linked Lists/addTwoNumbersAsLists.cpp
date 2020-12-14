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
    ListNode* partitionList(ListNode* A, ListNode* B)
    {
        ListNode *ptrA, *ptrB, *sum;
        ptrA = A;
        ptrB = B;
        int s = 0;
        int carry = 0;
        sum = new ListNode(0);
        ListNode* finalList = sum;
        while(ptrA != NULL && ptrB != NULL)
        {
            s = ptrA->val + ptrB->val + carry;
            if(s > 9)
            {
                s = s-10;
                carry = 1;
            }
            else
                carry = 0;
            sum->next = new ListNode(s);
            sum = sum->next;
            ptrA = ptrA->next;
            ptrB = ptrB->next;
        }
        while(ptrA != NULL)
        {
            s = ptrA->val + carry;
            if(s > 9)
            {
                s = s-10;
                carry = 1;
            }
            else
                carry = 0;
            sum->next = new ListNode(s);
            ptrA = ptrA->next;
            sum = sum->next;
        }
        while(ptrB != NULL)
        {
            s = ptrB->val + carry;
            if(s > 9)
            {
                s = s-10;
                carry = 1;
            }
            else
                carry = 0;
            sum->next = new ListNode(s);
            ptrB = ptrB->next;
            sum = sum->next;
        }
        if(carry == 1)
            sum->next = new ListNode(1);
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

    L = {9,9,9};
    ListNode* B = new ListNode(L[0]);
    temp = B;
    for(int i = 1; i < L.size(); i++)
    {
        temp->next = new ListNode(L[i]);
        temp = temp->next;
    }

    Solution* s = new Solution();
    A = s->partitionList(A, B);
    while(A != NULL)
    {
        cout << A->val << "\n";
        A = A->next;
    }
}