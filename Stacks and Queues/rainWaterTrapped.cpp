// Incomplete
#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;
 
class Solution
{
    int rainWaterTrapped(vector<int> A)
    {
        stack<int> s;
        int trapped, max_trapped;
        trapped = 0;
        max_trapped = 0;
        s.push(A[0]);
        for(int i = 0; i < A.size(); i++)
        {
            if(A[i] > A.top())
            {
                
            }
        }
    }
};