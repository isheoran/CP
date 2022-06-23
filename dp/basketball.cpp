#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod  (int)(1e9+7)
#define all(v) v.begin(),v.end()
#define input(v) for (auto &i : v) cin >> i;
#define print(v) for (auto &j : v) cout << j << " "; cout << "\n";
int n;vector<int>h1,h2; 
vector<int>dp1,dp2;

int f2(int);

int f1(int i)
{
    if(i<0) return 0;
    if(dp1[i]!=-1) return dp1[i];
    return dp1[i] = max(f2(i-1)+h1[i],f1(i-1));
}


int f2(int i)
{
    if(i<0) return 0;
    if(dp2[i]!=-1) return dp2[i];
    return dp2[i]=max(f2(i-1),f1(i-1)+h2[i]);
}

void solve()
{
    cin>>n;
    dp1.resize(n);
    dp2.resize(n);
    for(int i=0;i<n;i++) dp1[i]=dp2[i]=-1;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        h1.push_back(x);
    }
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        h2.push_back(x);
    }
    cout<<max(f1(n-1),f2(n-1))<<"\n";
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