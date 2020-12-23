#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

class Solution
{
    public:
    vector<int> mergeKSortedArrays(vector<vector<int>>& A)
    {
        priority_queue<vector<int>> q;
        vector<int> top = {};
        vector<int> ans = {};
        vector<int> pointers = {};
        int i, j, n, k;
        k = A.size();
        n = A[0].size();
        for(i = 0; i < k; i++)
        {
            q.push({A[i][n-1],i});
            pointers.push_back(n-1);
        }
        for(i = 0; i < n*k; i++)
        {
            top = q.top();
            ans.push_back(top[0]);
            pointers[top[1]]--;
            q.pop();
            if(pointers[top[1]] > -1)
                q.push({A[top[1]][pointers[top[1]]], top[1]});
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    vector<vector<int>> A = {{1, 2, 3},
                             {2, 4, 6},
                             {0, 9, 10}};
    Solution *s = new Solution();
    vector<int> ans = s->mergeKSortedArrays(A);
    for(int i: ans)
        cout << i << " ";
}
