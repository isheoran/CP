#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod  (int)(1e9+7)
#define sz(s) (int)s.size()
#define all(v) v.begin(),v.end()
#define input(v) for (auto &i : v) cin >> i;
#define print(v) for (auto &j : v) cout << j << " "; cout << "\n"; 

void solve()
{
    string s;
    cin>>s;
    int n = sz(s);
    vector<int>pre(n),suf(n);
    if(s[0]=='a') pre[0]++;
    for(int i=1;i<n;i++)
    {
        if(s[i]=='a') pre[i]=pre[i-1]+1;
        else pre[i]=pre[i-1];
    }
    if(s[n-1]=='b') suf[n-1]++;
    for(int i=n-2;i>=0;i--)
    {
        if(s[i]=='b') suf[i]=suf[i+1]+1;
        else suf[i]=suf[i+1];
    }
    int res=0;
    for(int i=-1;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            res=max(res,(i>=0 and i<n ? pre[i] : 0)+(i+1>=0 and i+1<n ? suf[i+1] : 0)-(j>=0 and j<n ? suf[j] : 0)+pre[n-1]-(j-1>=0 and j-1<n ? pre[j-1] : 0));
        }
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