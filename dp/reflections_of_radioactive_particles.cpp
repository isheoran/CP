#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod  (int)(1e9+7)
#define input(v) for (auto &i : v) cin >> i;
#define print(v) for (auto &j : v) cout << j << " "; cout << "\n";
int dp[1005][1005][2],n,k;

int f(int i,int j,int dir)
{
    if(j<1) return 0;
    if(i>n|| i<=0) return 1;
    if(dp[i][j][dir]!=-1) return dp[i][j][dir];
    if(dir) return dp[i][j][dir] = (f(i+1,j,dir) + f(i-1,j-1,0))%mod;
    else return dp[i][j][dir] = (f(i-1,j,dir)+f(i+1,j-1,1))%mod;
}    

void solve()
{
    cin>>n>>k;
    memset(dp,-1,sizeof(dp));
    cout<<f(1,k,1)<<"\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int testcases=1;
    cin>>testcases;
    while(testcases--) solve();
    return 0;
}