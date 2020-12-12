#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public:
    int removeElementFromArray(vector<int>& A, int B)
    {
        int k, i;
        k = 0;
        for(i = 0; i < A.size(); i++)
        {
            if(A[i] != B)
            {
                A[k] = A[i];
                k++;
            }
        }
        A.resize(k);
        return A.size();
    }
};


int main()
{
    vector<int> A = {4, 1, 1, 2, 1, 3};
    int B = 1;
    Solution* s = new Solution();
    int size = s->removeElementFromArray(A, B);
    for(int i = 0; i < A.size(); i++)
        cout << A[i] << "\n";
    cout << "Size: " << size;
}