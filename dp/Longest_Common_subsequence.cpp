#include<bits/stdc++.h>
using namespace std;

int main()
{
    string a,b;
    cin>>a>>b;
    int n1=a.size(),n2=b.size();
    int dp[n1][n2];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<n2;j++)
        {
            if(a[i]==b[j])
            {
                if(i>0 and j>0) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=1;
            }
            else
            {
                if(i>0 and j>0) dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }

        }
    }
    cout<<dp[n1-1][n2-1]<<"\n";
    return 0;
}