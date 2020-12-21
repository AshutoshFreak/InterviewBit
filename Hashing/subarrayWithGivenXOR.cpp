#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution
{
    public:
    int totalSubarraysWithGivenXOR(vector<int>& A, int B, int begin, int end)
    {
        int count = 0;
        if(begin == end)
        {
            if(A[begin] == B)
                return 1;
            else
                return 0;
        }
        unordered_map<int,int> table;
        int i, mid, x;
        x = 0;
        mid = (begin+end)/2;
        for(i = mid; i >= begin; i--)
        {
            x = x^A[i];
            if(table.find(x^B) != table.end())
                table[x^B]++;
            else
                table.insert({x^B,1});
        }
        x = 0;
        for(i = mid+1; i <= end; i++)
        {
            x = x^A[i];
            if(table.find(x) != table.end())
                count += table[x];
        }
        return count + totalSubarraysWithGivenXOR(A, B, begin, mid) + totalSubarraysWithGivenXOR(A, B, mid+1, end);
    }
    int subarrayWithGivenXOR(vector<int>& A, int B)
    {
        // return totalSubarraysWithGivenXOR(A, B, 0, A.size()-1);
        int i, j, x, count;
        count = 0;
        for(i = 0; i < A.size()-1; i++)
        {
            x = A[i];
            j = i;
            do
            {
                j++;
                if(x == B)
                    count++;
                z
            }while(j < A.size());
        }
    }

};

int main()
{
    vector<int> A = {2, 6, 2};
    int B = 6;
    Solution *s = new Solution();
    cout << s->subarrayWithGivenXOR(A, B);
}