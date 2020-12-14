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
    ListNode* insertionSortList(ListNode* A)
    {
        ListNode* start = new ListNode(0);
        start->next = A;
        ListNode* curr1 = A->next;
        ListNode* curr2 = A;
        ListNode* prev1 = A;
        ListNode* prev2 = start;
        while(curr1 != NULL)
        {
            if(curr1->val < prev1->val)
            {
                curr2 = start->next;
                prev2 = start;
                while(curr2->val < curr1->val)
                {
                    curr2 = curr2->next;
                    prev2 = prev2->next;
                }
                prev1->next = curr1->next;
                curr1->next = curr2;
                prev2->next = curr1;
                curr1 = prev1->next;
            }
            else
            {
                curr1 = curr1->next;
                prev1 = prev1->next;
            }
        }
        return start->next;
    }
};

int main()
{
    vector<int> L = {5,7,3};
    ListNode* A = new ListNode(L[0]);
    ListNode* temp = A;
    for(int i = 1; i < L.size(); i++)
    {
        temp->next = new ListNode(L[i]);
        temp = temp->next;
    }
    Solution* s = new Solution();
    A = s->insertionSortList(A);
    while(A != NULL)
    {
        cout << A->val << "\n";
        A = A->next;
    }
}