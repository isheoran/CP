#include <bits/stdc++.h>
using namespace std;
int n,m,k,dp[501][501][21],h[501][501],v[501][501];

int func(int i,int j,int now)
{
    if(dp[i][j][now]) return dp[i][j][now];
    if(now<=0) return 0;
    int tmp = INT_MAX;
    if(i+1<=n) tmp=min(tmp,func(i+1,j,now-1)+v[i][j]);
    if(i-1>=1) tmp=min(tmp,func(i-1,j,now-1)+v[i-1][j]);
    if(j-1>=1) tmp=min(tmp,h[i][j-1]+func(i,j-1,now-1));
    if(j+1<=m) tmp=min(tmp,func(i,j+1,now-1)+h[i][j]);
    return dp[i][j][now] = tmp;
}

void solve()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    for(int j=1;j<m;j++)
    cin>>h[i][j];
    for(int i=1;i<n;i++)
    for(int j=1;j<=m;j++)
    cin>>v[i][j];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(k%2) cout<<"-1 ";
            else cout<<func(i,j,k/2)*2<<" ";
        }cout<<"\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int testcases=1;
    //cin>>testcases;
    while(testcases--) solve();
    return 0;
}