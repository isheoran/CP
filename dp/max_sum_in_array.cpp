#include<iostream>
#include<vector>
using namespace std;
vector<int>a;
vector<int>dp;
vector<bool>visited;

int f(int i)
{
    if(i<0) return 0;
    if(i==0) return a[0];
    if(visited[i]) return dp[i];
    visited[i]=true;
    return dp[i]=max(a[i]+f(i-2),f(i-1));
}

int main()
{
    int n;
    cin>>n;
    a.resize(n);
    dp.resize(n);
    visited.resize(n);
    for(auto &i:a) cin>>i;
    cout<<f(n-1);
    return 0;
}