#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public:
    int subarrayWithBOddNumbers(vector<int> A, int B)
    {
        int start_even = 0, end_even = 0, total_odds = 0, count = 0, i;
        for(i = 0; i < A.size(); i++)
        {
            if(A[i]%2 != 0)
                break;
            start_even++;
        }
        for(;i < A.size(); i++)
        {
            if(A[i]%2 != 0)
            {
                total_odds++;
                end_even = 0;
            }
            else
                end_even++;
        }
        if(total_odds < B)
            return 0;
        if(total_odds == B)
            return (start_even+1)*(end_even+1);
        else
            return (total_odds-B+1)+start_even+end_even;
    }
};

int main()
{
    vector<int> A = {43, 28, 37, 92, 5, 3, 54, 93, 83, 22, 17, 19, 96, 48, 27, 72};
    int B = 2;
    Solution *s = new Solution();
    cout << s->subarrayWithBOddNumbers(A, B);
}