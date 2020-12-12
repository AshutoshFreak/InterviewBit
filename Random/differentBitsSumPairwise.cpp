#include<iostream>
#include<vector>

using namespace std;

//////////////////////////// Approach 1 - O(n^2) //////////////////////////////
// int count_1s(int v)
// {
//     int c;
//     v = v - ((v >> 1) & 0x55555555);                    // reuse input as temporary
//     v = (v & 0x33333333) + ((v >> 2) & 0x33333333);     // temp
//     c = ((v + (v >> 4) & 0xF0F0F0F) * 0x1010101) >> 24; // count
//     return c;
// }

// int solve(vector<int> A)
// {
//     int i, j, sum;
//     for(i = 0; i < A.size(); i++)
//     {
//         for(j = i+1; j < A.size(); j++)
//             sum += count_1s(A[i]^A[j]);
//     }
//     return sum*2;
// }

//////////////////////////// Approach 2 - O(n) //////////////////////////////
int solve(vector<int> A)
{
    int i, j, count;
    long long sum = 0;
    for(i = 0; i < 31; i++)
    {
        count = 0;
        for(j = 0; j < A.size(); j++)
        {
            if (A[j] & 1 << i)
                count++;
        }
        sum += count*(A.size()-count);
    }
    return sum*2 % (1000000007);
}


int main()
{
    vector<int> A{1, 3, 5};
    cout << solve(A);
}