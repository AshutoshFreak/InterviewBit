#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public:
    vector<int> swap(vector<int> A, int i, int j)
    {
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
        return A;
    }

    void generatePermutations(vector<vector<int>>& ans, int i, vector<int> A)
    {
        if(i == A.size()-1)
            return;
        vector<int> afterSwap;
        for(int k = i; k < A.size(); k++)
        {
            for(int j = k+1; j < A.size(); j++)
            {
                afterSwap = swap(A, k, j);
                ans.push_back(afterSwap);
                generatePermutations(ans, k+1, afterSwap);
            }
        }
    }
    vector<vector<int>> permutations(vector<int>& A)
    {
        vector<vector<int>> ans = {A};
        generatePermutations(ans, 0, A);
        return ans;
    }
};

int main()
{
    vector<int> A = {1,2,3,4,5,6};
    Solution* s = new Solution();
    vector<vector<int>> ans = s->permutations(A);
    for(int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << "\n";
    }
}