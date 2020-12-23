#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

class Solution
{
    public:
    vector<int> maximumSumCombinations(vector<int>& A, vector<int>& B, int C)
    {
        priority_queue<int> qA;
        priority_queue<int> qB;
        vector<int> ans = {};
        int i, temp, sum1, sum2;
        for(i = 0; i < A.size(); i++)
        {
            qA.push(A[i]);
            qB.push(B[i]);
        }
        for(i = 0; i < C; i++)
        {
            ans.push_back(qA.top()+qB.top());
            temp = qA.top();
            qA.pop();
            sum1 = qA.top() + qB.top();
            qA.push(temp);


            temp = qB.top();
            qB.pop();
            sum2 = qA.top() + qB.top();
            if(sum1>sum2)
            {
                qB.push(temp);
                qA.pop();
            }
            // if(qA.top() < qB.top())
            //     qA.pop();
            // else
            //     qB.pop();
        }
        return ans;
    }
};

int main()
{
    vector<int> A = {4, 3, 2, 1};
    vector<int> B = {6, 5, 2, 1};
    int C = 3;
    Solution *s = new Solution();
    vector<int> ans = s->maximumSumCombinations(A, B, C);
    for(int i: ans)
        cout << i << " ";
}