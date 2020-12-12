#include<iostream>
#include<vector>

using namespace std;

int dp[1001];

bool divisorGame(int N)
{
    if(N == 1)
        return 0;
    if(dp[N] != -1)
        return dp[N];
    else
    {
        for(int i = 1; i < N; i++)
        {
            if(N%i == 0)
            {
                if(divisorGame(N-i) == 0)
                    return dp[N] = 1;
                else if(divisorGame(N-N/i == 0))
                    return dp[N/i] = 1;
            }
        }
        return dp[N] = 0;
    }
    ///////////////// Faster solution ///////////////////
    return (N%2 == 0);
}

int main()
{
    cout << divisorGame(157);
}