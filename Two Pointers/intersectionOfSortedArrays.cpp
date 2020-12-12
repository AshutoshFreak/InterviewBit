#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public:
    vector<int> intersectionOfSortedArrays(vector<int>& A, vector<int>& B)
    {
        int ptr1, ptr2;
        vector<int> C;
        ptr1 = 0;
        ptr2 = 0;
        while(ptr1 < A.size() && ptr2 < B.size())
        {
            if(A[ptr1] == B[ptr2])
            {
                C.push_back(A[ptr1]);
                ptr1++;
                ptr2++;
            }
            else if(A[ptr1] < B[ptr2])
                ptr1++;
            else
                ptr2++;
        }
        return C;
    }
};

int main()
{
    vector<int> A = {1};
    vector<int> B = {1};
    Solution* s = new Solution();
    vector<int> C = s->intersectionOfSortedArrays(A, B);
    for(int i = 0; i < C.size(); i++)
        cout << C[i] << "\n";
}
