#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = (int)(1e9+7);
#define sz(s) (int)s.size()
#define all(v) v.begin(),v.end()
#define input(v) for (auto &i : v) cin >> i;
#define print(v) for (auto &j : v) cout << j << " "; cout << "\n";

void solve()
{
    int n;
    cin>>n;
    int res0=0,res1=1;
    for(int i=1;i<=n;i++)
    {
        int tmp=res0;
        res0=(res1*3%mod+res0*2%mod)%mod;
        res1=tmp;
    }
    cout<<res1%mod<<"\n";
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