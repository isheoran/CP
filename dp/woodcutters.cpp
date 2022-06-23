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
    int n;
    cin>>n;
    vector<int>h(n),x(n);
    for(int i=0;i<n;i++)
    {
        cin>>x[i]>>h[i];
    }
    int cnt=n>1 ? 2 : 1;
    for(int i=1;i<n-1;i++)
    {
        if(x[i]-x[i-1]>h[i]) cnt++;
        else if(x[i+1]-x[i]>h[i]) 
        {
            cnt++;
            x[i]+=h[i];
        }
    }
    cout<<cnt<<"\n";
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