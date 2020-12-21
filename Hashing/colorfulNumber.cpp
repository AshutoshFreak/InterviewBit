#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>

using namespace std;

class Solution
{
    public:
    bool colorfulNumber(int A)
    {
        string s = to_string(A);
        unordered_map<int,bool> table;
        int mul = 1;
        int i,j;
        for(i = 0; i < s.size(); i++)
        {
            mul = s[i]-'0';
            j = i;
            do
            {
                j++;
                // cout << mul << "\n";
                if(table.find(mul) != table.end())
                    return false;
                else
                    table.insert({mul,0});
                mul = mul*(s[j]-'0');
            }while(j < s.size());
            // cout << "\n";
        }
        return true;
    }
};

int main()
{
    int A = 3245;
    Solution *s = new Solution();
    cout << s->colorfulNumber(A);
}