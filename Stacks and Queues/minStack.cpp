#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public:
    vector<int> s, minimum;
    int t;
    Solution()
    {
        s = {};
        t = -1;
        minimum = {};
    }
    int top()
    {
        if(t == -1)
            return -1;
        else
            return s[t];
    }
    void pop()
    {
        if(t != -1)
        {
            t--;
            s.pop_back();
            minimum.pop_back();
        }
    }
    void push(int n)
    {
        s.push_back(n);
        if(t == -1)
            minimum.push_back(n);
        else
            minimum.push_back(min(n, minimum[t]));
        t++;
    }
    int getMin()
    {
        if(t == -1)
            return -1;
        return minimum[t];
    }
};

int main()
{
    Solution* s = new Solution();
    s->push(1);
    cout << s->top() << "\n";
    s->pop();
    s->pop();
    cout << s->top() << "\n";
    s->push(10);
    cout << s->top() << "\n";
    s->push(7);
    cout << s->top() << "\n";
    s->push(6);
    cout << s->top() << "\n";
    s->push(4);
    cout << s->top() << "\n";
    cout << s->getMin() << "\n";
    s->pop();
    cout << s->getMin() << "\n";
}