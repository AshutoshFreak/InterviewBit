#include<iostream>
#include<unordered_map>
#include<vector>
#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

class Solution
{
    public:
    int longestSubarrayLength(vector<int> A)
    {
        int max = 0, i, sum = 0;
        unordered_map<int, int> table;
        table[0] = -1;
        for(i = 0; i < A.size(); i++)
        {
            if(A[i] == 1)
                sum++;
            else
                sum--;
            if(table.find(sum) == table.end())
                table.insert({sum, i});
            if(table.find(sum-1) != table.end())
            {
                if(max < i-table[sum-1])
                    max = i-table[sum-1];
            }
        }
        return max;
    }
};

int main()
{
    vector<int> A = {0, 1, 1, 0, 0, 1};
    Solution *s = new Solution();
    cout << s->longestSubarrayLength(A);
}