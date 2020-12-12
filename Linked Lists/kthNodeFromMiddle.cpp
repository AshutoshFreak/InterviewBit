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
    int kthNodeFromMiddle(ListNode* A, int B)
    {
        int n = 0;
        ListNode* L = A;
        while(L != NULL)
        {
            n++;
            L = L->next;
        }
        int kthFromMiddle = (n/2+1)-B-1;
        if(kthFromMiddle < 0)
            return -1;
        n = 0;
        L = A;
        while(L != NULL)
        {
            // cout << L->val << "\n";
            if(n == kthFromMiddle)
                return L->val;
            L = L->next;
            n++;
        }
    }
};


int main()
{
    vector<int> L = {3,4,7,5,6,16,15,61,16};
    int B = 3;
    ListNode* A = new ListNode(L[0]);
    ListNode* temp = A;
    for(int i = 1; i < L.size(); i++)
    {
        temp->next = new ListNode(L[i]);
        temp = temp->next;
    }
    Solution* s = new Solution();
    int ans = s->kthNodeFromMiddle(A, B);
    cout << ans;
    // while(A != NULL)
    // {
    //     cout << A->val << "\n";
    //     A = A->next;
    // }
}