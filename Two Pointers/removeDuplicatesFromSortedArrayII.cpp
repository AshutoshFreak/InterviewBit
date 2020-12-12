#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public:
    int removeDuplicatesFromSortedArray(vector<int>& A)
    {
        int k, i,curr, count;
        k = 1;
        count = 1;
        curr = A[0];
        for(i = 1; i < A.size(); i++)
        {
            if(A[i] != curr)
            {
                A[k] = A[i];
                curr = A[i];
                count = 1;
                k++;
            }
            else
                count++;
            if(count == 2)
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
    vector<int> A{1,1,1,1,1,2};
    Solution* s = new Solution();
    int size = s->removeDuplicatesFromSortedArray(A);
    for(int i = 0; i < A.size(); i++)
        cout << A[i] << "\n";
    cout << "Size: " << size;
}