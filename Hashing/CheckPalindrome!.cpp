#include<iostream>
#include<unordered_map>

using namespace std;

class Solution
{
    public:
    bool checkPalindrome(string A)
    {
        int count_odd = 0;
        unordered_map<char, int> table;
        for(int i = 0; i < A.size(); i++)
        {
            if(table.find(A[i]) == table.end())
                table.insert({A[i], 1});
            else
                table[A[i]]++;
        }
        for(auto x: table)
        {
            if(x.second%2 != 0)
                count_odd++;
        }
        if(count_odd > 1)
            return false;
        else
            return true;
    }
};

int main()
{
    string A = "abbaeefffeee";
    Solution* s = new Solution();
    cout << s->checkPalindrome(A);
}