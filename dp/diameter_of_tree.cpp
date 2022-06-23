#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define m  (ll)(1e9+7)
#define input(v) for (auto &i : v) cin >> i;
#define print(v) for (auto &j : v) cout << j << " "; cout << "\n";
vector<int>f;
vector<vector<int>>adj;
int diameter = 0;

void dfs(int s,int e)
{
    vector<int>fvalues;
    for(auto u : adj[s])
    {
        if(u==e) continue;
        dfs(u,s);
        fvalues.push_back(f[u]);
    }
    if(fvalues.size()==1)
    {
        f[s]=max(f[s],fvalues.front()+1);
        diameter=max(diameter,f[s]);
    }
    if(fvalues.size()>=2){
    int gtr = 0, smlr = 0;
    for(auto u : fvalues)
    {
        if(u>gtr)
        {
            smlr=gtr;
            gtr=u;
        }
        else if(u>smlr)
        {
            smlr=u;
        }
    }
    f[s]=1+gtr;
    diameter=max(diameter,2+gtr+smlr);
    }
}

void solve()
{
    int n;
    cin>>n;
    f.resize(n+1);
    adj.resize(n+1);
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0);
    cout<<3*diameter<<"\n";
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