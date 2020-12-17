// Incomplete
#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

class Solution
{
    int largestRecangleinHistogram(vector<int> A)
    {
        int curr, ptr1, ptr2, max, area;
        vector<int> heights = A;
        sort(heights.begin(), heights.end());
        ptr1 = 0;
        ptr2 = heights.size()-1;
        area = (ptr2-ptr1+1)*heights[0];
        max = area;
        for(int i = 1; i < heights.size(); i++)
        {
            curr = heights[i];
            while(heights[ptr1]){}
        }
        return max;
    }
};

int main()
{

}