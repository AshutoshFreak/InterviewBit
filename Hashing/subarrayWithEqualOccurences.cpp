#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution
{
    public:
    int subarrayWithEqualOccurences(vector<int>& A, int B, int C)
    {
        unordered_map<int, int> table;
        int sum = 0, ans = 0;
        table[0] = 1;
        for(int i: A)
        {
            if(i == B)
                sum++;
            else if(i == C)
                sum--;
            ans += table[sum];
            table[sum]++;
        }
        return ans;
    }
};

int main()
{
    vector<int> A = {1, 2, 1};
    int B = 1;
    int C = 2;
    Solution *s = new Solution();
    cout << s->subarrayWithEqualOccurences(A, B, C);
}