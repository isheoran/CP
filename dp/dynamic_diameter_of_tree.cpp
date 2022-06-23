#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<int>>adj;
vector<int>dist;
vector<int>check;
int dia,node;

void dfs(int s,int e)
{
    for(auto u:adj[s])
    {
        if(u==e) continue;
        dist[u]=dist[s]+1;
        if(dist[u]>dia)
        {
            dia=dist[u];
            node=u;
        }
        dfs(u,s);
    }
}

void solve()
{
    int n,leaf1,leaf2;
    cin>>n;
    adj.resize(n+1);
    dist.resize(n+1);
    check.resize(n+1);
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dist[1]=0;
    dia=0;
    node=1;
    dfs(1,0);
    leaf1=node;
    dist[node]=0;
    dia=0;
    dfs(node,0);
    leaf2=node;
    dist[leaf1]=0;
    dfs(leaf1,0);
    for(int i=1;i<=n;i++)
    if(dist[i]==dia) check[i]=1;
    dist[leaf2]=0;
    dfs(leaf2,0);
    for(int i=1;i<=n;i++)
    if(dist[i]==dia) check[i]=1;
    for(int i=1;i<=n;i++){
    if(check[i]) cout<<dia+1<<"\n";
    else cout<<dia<<"\n";}
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