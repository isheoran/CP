#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define m  (ll)(1e9+7)
#define input(v) for (auto &i : v) cin >> i;
#define print(v) for (auto &j : v) cout << j << " "; cout << "\n";
ll dp[2001][2001],s[2001],n;

ll f(int l,int r)
{
    if(l==r) return 0;
    if(l>r) return 0;
    if(l<1 || r<1 || l>n || r>n) return 0;
    if(dp[l][r]!=-1) return dp[l][r];
    return dp[l][r] = s[r] - s[l] + min(f(l,r-1),f(l+1,r));
}

void solve()
{
    for(int i=0;i<2001;i++) for(int j=0;j<2001;j++) dp[i][j] = -1;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i];
    sort(s+1,s+n+1);
    cout<<f(1,n)<<"\n";
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