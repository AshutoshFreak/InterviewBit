#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<string.h>

using namespace std;

class Solution
{
    public:
    int evaluateExpression(vector<string> A)
    {
        int ans = 0;
        int operand1, operand2;
        stack<string> s;
        for(int i = 0; i < A.size(); i++)
        {
            if(A[i] == "+" || A[i] == "-" || A[i] == "*" || A[i] == "/")
            {
                operand2 = stoi(s.top());
                s.pop();
                operand1 = stoi(s.top());
                s.pop();
                switch(A[i][0])
                {
                    case '+': ans = operand1+operand2; break;
                    case '-': ans = operand1-operand2; break;
                    case '*': ans = operand1*operand2; break;
                    case '/': ans = operand1/operand2; break;
                }
                s.push(to_string(ans));
            }
            else
                s.push(A[i]);
        }
        return stoi(s.top());
    }
};


int main()
{
    vector<string> A = {"4"};
    Solution *s = new Solution();
    cout << s->evaluateExpression(A);
}