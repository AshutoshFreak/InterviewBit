#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution
{
    public:
    bool redundantBraces(string A)
    {
        stack<char> s;
        for(int i = 0; i < A.size(); i++)
        {
            if(A[i] == '(' || A[i] == '+' || A[i] == '-' || A[i] == '*'  || A[i] == '/' )
                s.push(A[i]);
            else if(A[i] == ')')
            {
                if(s.top() == '(')
                    return true;
                else
                {
                    while(s.top() != '(')
                        s.pop();
                    s.pop();
                }
            }
        }
        return false;
    }
};

int main()
{
    string expr = "((a+b)*((b+c)/(d)))";
    Solution* s = new Solution();
    cout << s->redundantBraces(expr);
}