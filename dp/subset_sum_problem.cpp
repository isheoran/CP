#include<iostream>
using namespace std;
int a[100],n;
int dp[100][100];

bool subset(int i,int sum)
{
    if(sum<0) return 0;
    if(sum==0) return 1;
    if(i<0) return 0;
    if(dp[i][sum]!=-1) return 1;
    return dp[i][sum] = subset(i-1,sum) | subset(i-1,sum-a[i]);
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    memset(dp,-1,sizof(dp));
    int sum;
    cin>>sum;
    cout<<subset(n-1,sum);
    return 0;
}
