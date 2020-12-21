#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

class Solution
{
    public:
    int firstRepeatingElement(vector<int> A)
    {
        int min = INT32_MAX;
        unordered_map<int,int> table;
        for(int i = 0; i < A.size(); i++)
        {
            if(table.find(A[i]) != table.end())
            {
                if(table[A[i]] < min)
                {
                    min = table[A[i]];
                }
            }
            else
                table.insert({A[i], i});
        }
        if(min == INT32_MAX)
            return -1;
        else
            return A[min];
    }
};

int main()
{
    vector<int> A = {8, 15, 1, 10, 5, 19, 19, 3, 5, 6, 6, 2, 8, 2, 12, 16, 3};
    Solution *s = new Solution();
    cout << s->firstRepeatingElement(A);
}