#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod  (ll)(1e9+7)
int n0,n1,dp[5000][5000];
vector<int>v1,v0;

int f(int i,int j)
{
    if(i==n1) return 0;
    if(j==n0) return mod;
    if(dp[i][j]!=-1) return dp[i][j];
    return dp[i][j] = min(f(i+1,j+1)+abs(v1[i]-v0[j]),f(i,j+1));
}

int main()
{
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if(x) v1.push_back(i);
        else v0.push_back(i);
    }
    n0=(ll)v0.size(),n1=(ll)v1.size();
    cout<<f(0,0)<<"\n";
    return 0;
}