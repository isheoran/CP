#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod  (int)(1e9+7)
#define sz(s) (int)s.size()
#define all(v) v.begin(),v.end()
#define input(v) for (auto &i : v) cin >> i;
#define print(v) for (auto &j : v) cout << j << " "; cout << "\n";
const int nmm = 1e5+1; 
vector<int>spf(nmm);

void sieve()
{
    for(int i=0;i<nmm;i++) spf[i]=i;
    for(int i=2;i*i<=nmm;i++)
    {
        if(spf[i]==i)
        {
            for(int j=i*i;j<nmm;j+=i)
            if(spf[j]==j) spf[j]=i;
        }
    }
}

void solve()
{
    int n;
    cin>>n;
    if(n==1)
    {
        cout<<"1\n";
        return;
    }
    sieve();
    vector<int>dp(nmm),d(nmm);
    for(int i=0;i<n;i++)
    {
        int x,tmp;
        cin>>x;
        tmp=x;
        set<int>s;
        while(spf[x]!=1)
        {
            s.insert(spf[x]);
            x/=spf[x];
        }
        for(auto u:s)
        {
            dp[tmp]=max(dp[tmp],d[u]+1);
        }
        for(auto u:s) d[u]=dp[tmp];
    }
    int res=0;
    for(int i=0;i<nmm;i++)
    {
        res=max(res,dp[i]);
    }
    cout<<res<<"\n";
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