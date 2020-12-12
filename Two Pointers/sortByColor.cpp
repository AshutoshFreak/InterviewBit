#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public:
    vector<int> sortByColor(vector<int>& A)
    {
        vector<int> A1, A2, A3, sorted;
        int i;
        for(i = 0; i < A.size(); i++)
        {
            if(A[i] == 0)
                A1.push_back(A[i]);
            else if(A[i] == 1)
                A2.push_back(A[i]);
            else
                A3.push_back(A[i]);
        }
        for(i = 0; i < A1.size(); i++)
            sorted.push_back(A1[i]);
        for(i = 0; i < A2.size(); i++)
            sorted.push_back(A2[i]);
        for(i = 0; i < A3.size(); i++)
            sorted.push_back(A3[i]);
        return sorted;
    }
};

int main()
{
    vector<int> A{0, 1};
    Solution* s = new Solution();
    vector<int> sorted = s->sortByColor(A);
    for(int i = 0; i < sorted.size(); i++)
        cout << sorted[i] << "\n";
}