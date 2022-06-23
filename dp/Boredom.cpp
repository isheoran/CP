#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod  (int)(1e9+7)
#define sz(s) (int)s.size()
#define all(v) v.begin(),v.end()
#define input(v) for (auto &i : v) cin >> i;
#define print(v) for (auto &j : v) cout << j << " "; cout << "\n"; 
const int nmm = 1e5+1;
int cnt[nmm],dp[nmm];

int f(int i)
{
    if(i==0) return 0;
    if(i==1) return cnt[1];
    if(dp[i]!=-1) return dp[i];
    return dp[i] = max(f(i-1),f(i-2)+cnt[i]*i);
}

void solve()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        cnt[a]++;
    }
    memset(dp,-1,sizeof(dp));
    cout<<f(nmm-1)<<"\n";
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