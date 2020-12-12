#include<iostream>
#include<bitset>
#include<bits/stdc++.h>

using namespace std;

long long unsigned solve(unsigned int A)
{
    string bin = bitset<32>(A).to_string();
    reverse(bin.begin(), bin.end());
    return bitset<32>(bin).to_ullong();
}

int main()
{
    long long unsigned n = 3;
    cout << solve(n);
}