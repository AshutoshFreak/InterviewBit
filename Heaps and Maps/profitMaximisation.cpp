#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

class Solution
{
    public:
    int profitMaximisation(vector<int>& A, int B)
    {
        priority_queue<int> q;
        int i, t, ans;
        for(int i: A)
            q.push(i);
        for(i = 1; i < B; i++)
        {
            t = q.top();
            ans += t;
            q.pop();
            q.push(t-1);
        }
        return ans;
    }
};

int main()
{
    vector<int> A = {2, 3};
    B = 3;
    Solution *s = new Solution();
    cout << s->profitMaximisation(A, B);
}
