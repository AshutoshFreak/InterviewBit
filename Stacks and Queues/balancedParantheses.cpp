#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution
{
    public:
    bool balancedParenthesis(string A)
    {
        stack <char> s;
        for(int i = 0; i < A.size(); i++)
        {
            if(A[i] == '(')
                s.push('(');
            else
            {
                if(s.empty() == true)
                    return 0;
                else
                    s.pop();
            }
        }
        if(s.empty() == true)
            return 1;
        else
            return 0;
    }
};

int main()
{
    string str = "(())(())";
    Solution* s = new Solution();
    cout << s->balancedParenthesis(str);
}