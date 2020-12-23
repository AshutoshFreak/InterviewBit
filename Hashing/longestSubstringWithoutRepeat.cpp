// Incomplete
#include<vector>
#include<iostream>
#include<unordered_map>

using namespace std;

class Solution
{
    public:
    int longestSubstringWithoutRepeat(string A)
    {
        int start = 0, max = 0;
        unordered_map<int, int> table;
        for(int i = 0; i < A.size(); i++)
        {
            if(table[A[i]] >= start)
                start = A[i];
            table[A[i]] = i;
            if(i-start>max)
            {
                max = i-start;
                cout << i << " " << start << " " << max << "\n";
            }
        }
        return max;
    }
};

int main()
{
    string A = "aabcdef";
    Solution *s = new Solution();
    cout << s->longestSubstringWithoutRepeat(A);
}
