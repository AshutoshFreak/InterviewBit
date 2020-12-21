#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution
{
    public:
    vector<int> largestContinoutSequenceZeroSum(vector<int> A)
    {
        int sum, i, max_size, start, end, curr;
        unordered_map<int, int> table;
        vector<int> ans;
        table[0] = -1;
        sum = 0;
        max_size = 0;
        start = -1;
        end = -1;
        for(i = 0; i < A.size(); i++)
        {
            sum += A[i];
            if(table.find(sum) == table.end())
                table.insert({sum, i});
            else
            {
                curr = i-table[sum]+1;
                if(curr > max_size)
                {
                    max_size = curr;
                    start = table[sum]+1;
                    end = i;
                }
            }
        }
        if(start != -1 && end != -1)
        {
            for(i = start; i <= end; i++)
                ans.push_back(A[i]);
        }
        else
            ans = {};
        return ans;
    }
};

int main()
{
    vector<int> A = {-19, 8, 2, -8, 19, 5, -2, -23};
    Solution *s = new Solution();
    A = s->largestContinoutSequenceZeroSum(A);
    for(int i: A)
        cout << i << " ";
}