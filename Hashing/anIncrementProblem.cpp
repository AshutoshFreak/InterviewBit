#include<iostream>
// incomplete
#include<vector>
#include<unordered_map>

using namespace std;

class Solution
{
    public:
    vector<int> anIncrementProblem(vector<int> A)
    {
        unordered_map<int, int> table;
        vector<int> ans = {};
        int toIncrease, prev;
        for(int i = 0; i < A.size(); i++)
        {
            ans.push_back(A[i]);
            if(table.find(A[i]) == table.end())
                table.insert({A[i], i});
            else
            {
                toIncrease = table[ans[i]];
                ans[toIncrease]++;
                prev = table[ans[toIncrease]];
                table[ans[toIncrease]] = toIncrease;
                table[ans[i]] = prev;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> A = {2,3,2,2,2,3,3};
    Solution *s = new Solution();
    A = s->anIncrementProblem(A);
    for(int i: A)
        cout << i << " ";
}