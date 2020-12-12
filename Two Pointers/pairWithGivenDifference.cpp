#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

int pairWithGivenDifference(vector<int> A, int B)
{
    if(B == 0)
        return 0;
    int ptr1, ptr2;
    ptr1 = 0;
    ptr2 = 0;
    B = abs(B);
    sort(A.begin(), A.end());
    while(ptr1 < A.size() && ptr2 < A.size())
    {
        if(abs(A[ptr2] - A[ptr1]) > B)
            ptr1++;
        else if(abs(A[ptr2] - A[ptr1]) < B)
            ptr2++;
        else
            return 1;
    }
    return 0;
}

int main()
{
    vector<int> A{-10, 20};
    int B = 30;
    cout << pairWithGivenDifference(A, B);
}