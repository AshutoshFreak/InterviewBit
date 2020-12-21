#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

class Solution
{
    public:
    vector<int> twoOutOfThree(vector<int> A, vector<int> B, vector<int> C)
    {
        int i;
        vector<int> ans;
        unordered_map<int, bool> table_A, table_B;
        for(i = 0; i < A.size(); i++)
            table_A.insert({A[i], 0});
        for(i = 0; i < B.size(); i++)
        {
            if(table_A.find(B[i]) == table_A.end())
                table_B.insert({B[i], 0});
            else if(table_A[B[i]] == 0)
            {
                table_A[B[i]] = 1;
                ans.push_back(B[i]);
            }
        }
        for(i = 0; i < C.size(); i++)
        {
            if(table_A.find(C[i]) != table_A.end() && table_A[C[i]] == 0)
                ans.push_back(C[i]); 
            else if(table_B.find(C[i]) != table_B.end() && table_B[C[i]] == 0)
                ans.push_back(C[i]);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    vector<int> A = {2,3,1,4};
    vector<int> B = {1,1,3,3,2,2,3,3};
    vector<int> C = {2,1,2,3};

    Solution *s = new Solution();
    A = s->twoOutOfThree(A, B, C);
    for(auto x: A)
        cout << x << "\n";
}