#include<iostream>
#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution
{
    public:
    vector<int> nearestSmallerElement(vector<int>& A)
    {
        vector<int> near;
        stack<int> s;
        for(int i = 0; i < A.size(); i++)
        {
            if(s.empty() == true)
                near.push_back(-1);
            else
            {
                while(s.empty() == false && s.top() >= A[i])
                    s.pop();
                if(s.empty() == true)
                    near.push_back(-1);
                else
                    near.push_back(s.top());
            }
            s.push(A[i]);
        }
        return near;
    }
};

int main()
{
    vector<int> A = {39, 27, 11, 4, 24, 32, 32, 1};
    Solution* s = new Solution();
    A = s->nearestSmallerElement(A);
    for(int i = 0; i < A.size(); i++)
        cout << A[i] << "\n";
}