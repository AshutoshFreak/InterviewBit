#include<vector>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution
{
    public:
    bool diffkII(vector<int> A, int B)
    {
        if(A.size() < 2)
            return 0;
        vector<int> diff;
        bool dup = 0;
        unordered_map<int,bool> table;
        for(auto x: A)
        {
            if(table.find(x) == table.end())
                table.insert({x,0});
            else
                dup = 1;
            diff.push_back(x-B);
        }
        if(B == 0)
        {
            if(dup == 1)
                return 1;
            else
                return 0;
        }
        for(auto x: diff)
            if(table.find(x) != table.end())
                return 1;
        return 0;
    }
};

int main()
{
    vector<int> A = {1,2,5};
    int B = 0;
    Solution *s = new Solution();
    cout << s->diffkII(A, B);
}