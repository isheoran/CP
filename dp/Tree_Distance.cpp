#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod  (int)(1e9+7)
#define all(v) v.begin(),v.end()
#define input(v) for (auto &i : v) cin >> i;
#define print(v) for (auto &j : v) cout << j << " "; cout << "\n"; 
vector<vector<int>>adj;
int dp[50001][501];
int ans=0,k;

void dfs(int s,int p)
{
    dp[s][0]=1;
    for(auto u:adj[s])
    {
        if(u==p) continue;
        dfs(u,s);
        for(int i=0;i<k;i++) ans+=dp[u][i]*dp[s][k-i-1];
        for(int i=1;i<=k;i++) dp[s][i]+=dp[u][i-1];
    }
}

void solve()
{
    int n;
    cin>>n>>k;
    adj.resize(n+1);
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0);
    cout<<ans<<"\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int testcases=1;
    //cin>>testcases;
    while(testcases--) solve();
    return 0;
}