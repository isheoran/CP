#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod  (ll)(1e9+7)
#define input(v) for (auto &i : v) cin >> i;
#define print(v) for (auto &j : v) cout << j << " "; cout << "\n";
const int nmm = 2e5+1;
ll dp[nmm];

void solve()
{
    int n,m;
    cin>>n>>m;
    ll ans = 0;
    while(n)
    {
        ans = (ans + (m+n%10 < 10 ? 1 : dp[m+n%10-10]))%mod;
        n/=10;
    }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int testcases=1;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<=8;i++) dp[i]=2;
    dp[9]=3;dp[10]=dp[11]=4;
    for(int i=12;i<nmm;i++) dp[i]=(dp[i-10]+dp[i-9])%mod;
    cin>>testcases;
    while(testcases--) solve();
    return 0;
}