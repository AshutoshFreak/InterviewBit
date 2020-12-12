#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public:
    int removeDuplicatesFromSortedArray(vector<int>& A)
    {
        int k, i,curr;
        curr = A[0];
        k = 1;
        for(i = 0; i < A.size(); i++)
        {
            if(A[i] != curr)
            {
                curr = A[i];
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
    vector<int> A{1,1,2};
    Solution* s = new Solution();
    int size = s->removeDuplicatesFromSortedArray(A);
    for(int i = 0; i < A.size(); i++)
        cout << A[i] << "\n";
    cout << "Size: " << size;
}