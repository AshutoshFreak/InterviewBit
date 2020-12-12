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
    ListNode* reverseAlternateKNodes(ListNode* A, int B)
    {
        int i, count;
        ListNode* L = A;
        vector<int> rev_List{};
        ListNode* finalList = new ListNode(0);
        ListNode* f = finalList;
        count = 0;
        while(L != NULL)
        {
            rev_List.clear();
            for(i = 0; i < B; i++)
            {
                rev_List.push_back(L->val);
                L = L -> next;
            }
            if(count % 2 == 0)
                reverse(rev_List.begin(), rev_List.end());
            for(i = 0; i < rev_List.size(); i++)
            {
                finalList->next = new ListNode(rev_List[i]);
                finalList = finalList->next;
            }
            count++;
        }
        return f->next;
    }
};


int main()
{
    vector<int> L = {3,4,7,5,6,6,15,61,16};
    int B = 3;
    ListNode* A = new ListNode(L[0]);
    ListNode* temp = A;
    for(int i = 1; i < L.size(); i++)
    {
        temp->next = new ListNode(L[i]);
        temp = temp->next;
    }
    Solution* s = new Solution();
    A = s->reverseAlternateKNodes(A, B);
    // cout << ans;
    while(A != NULL)
    {
        cout << A->val << "\n";
        A = A->next;
    }
}