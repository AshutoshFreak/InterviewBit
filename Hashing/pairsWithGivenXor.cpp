#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

class Solution
{
    public:
    int pairsWithGivenXor(vector<int> A, int B)
    {
        vector<int> afterXOR;
        unordered_map<int,bool> table;
        int count = 0;
        for(int i = 0; i < A.size(); i++)
        {
            afterXOR.push_back(A[i]^B);
            table.insert({A[i],true});
        }
        for(int i = 0; i < afterXOR.size(); i++)
        {
            if(table.find(afterXOR[i]) != table.end())
                count++;
        }
        return count/2;
    }
};

int main()
{
    vector<int> A = {5, 4, 10, 15, 7, 6};
    int B = 5;
    Solution *s = new Solution();
    cout << s->pairsWithGivenXor(A, B);
}