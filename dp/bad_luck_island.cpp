#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod  (int)(1e9+7)
#define all(v) v.begin(),v.end()
#define input(v) for (auto &i : v) cin >> i;
#define print(v) for (auto &j : v) cout << j << " "; cout << "\n"; 

void solve()
{
    int r,s,p;
    cin>>r>>s>>p;
    double dp[r+1][s+1][p+1];
    for(int i=0;i<=r;i++)for(int j=0;j<=s;j++)for(int k=0;k<=p;k++)dp[i][j][k]=0;
    dp[r][s][p]=1;
    for(int i=r;i>=0;i--)
    {
        for(int j=s;j>=0;j--)
        {
            for(int k=p;k>=0;k--)
            {
                if(i*j+i*k+j*k==0) continue;
                if(i>0) dp[i-1][j][k] += dp[i][j][k]*((double)i*k/(i*k+i*j+j*k)); 
                if(j>0) dp[i][j-1][k] += dp[i][j][k]*((double)i*j/(i*k+i*j+j*k)); 
                if(k>0) dp[i][j][k-1] += dp[i][j][k]*((double)j*k/(i*k+i*j+j*k)); 
            }
        }
    }
    double ans=0;
    for(int i=1;i<=r;i++) ans+=dp[i][0][0]; cout<<fixed<<setprecision(10)<<ans<<" "; ans=0;
    for(int j=1;j<=s;j++) ans+=dp[0][j][0]; cout<<fixed<<setprecision(10)<<ans<<" "; ans=0;
    for(int k=1;k<=p;k++) ans+=dp[0][0][k]; cout<<fixed<<setprecision(10)<<ans<<"\n";
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