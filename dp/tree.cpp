#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
#define all(v) v.begin(),v.end()
#define input(v) for (auto &i : v) cin >> i;
#define print(v) for (auto &j : v) cout << j << " "; cout << "\n"; 
vector<vector<int>>adj,d;
vector<int>st,et;
int tme=0;

void dfs(int s,int depth=0)
{
    st[s]=tme++;
    d[depth].push_back(st[s]);
    for(auto u:adj[s])
    {
        dfs(u,depth+1);
    }
    et[s]=tme;
}

void solve()
{
    int n;
    cin>>n;
    adj.resize(n+1);
    d.resize(n+1);
    et.resize(n+1);
    st.resize(n+1);
    for(int i=2;i<=n;i++)
    {
        int p;
        cin>>p;
        adj[p].push_back(i);
    }
    dfs(1);
    int q;
    cin>>q;
    while(q--)
    {
        int u,di;
        cin>>u>>di;
        int l=st[u],r=et[u];
        int ans=lower_bound(all(d[di]),r)-lower_bound(all(d[di]),l);
        cout<<ans<<"\n";
    }
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