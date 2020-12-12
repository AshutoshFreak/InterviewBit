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
    ListNode* removeDuplicatesFromSortedList(ListNode* A)
    {
        ListNode* k = A;
        ListNode* i = A->next;
        while(i != NULL)
        {
            if(i->val == k->val)
                i = i->next;
            else
            {
                k->next = i;
                k = i;
                i = i->next;
            }
        }
        k->next = NULL;
    }
    return A;
};

int main()
{
    vector<int> L = {1,1,2};
    ListNode* A = new ListNode(L[0]);
    ListNode* B = A;
    for(int i = 1; i < L.size(); i++)
    {
        B->next = new ListNode(L[i]);
        B = B->next;
    }
    Solution* s = new Solution();
    s->removeDuplicatesFromSortedList(A);
    while(A != NULL)
    {
        cout << A->val << "\n";
        A = A->next;
    }
}