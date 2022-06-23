#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define input(v) for (auto &i : v) cin >> i;
#define print(v) for (auto &j : v) cout << j << " "; cout << "\n";
vector<ll>f(5000,-1);

ll func(string s,ll i)
{
    if(i==-1) return 1;
    else if(i==0)
    {
        if(s[i]>'0' )
        {
            return 1;
        }
    }
    else if(f[i]!=-1) return f[i];
    else{
    if(s[i]>'0' && s.substr(i-1,2)>="10" && s.substr(i-1,2)<="26")
    {
        return f[i]=func(s,i-1)+func(s,i-2);
    }
    else if(s[i]>'0' )
    {
        return f[i]=func(s,i-1);
    }
    else if(s.substr(i-1,2)>="10" && s.substr(i-1,2)<="26"){
        return f[i]=func(s,i-2);
    }
    else return 0;
    }
    return 0;
}

int main()
{
    string s;
    while(cin>>s)
    {
        ll n = s.size();
        if(s[0] == '0') return 0;
        for(int i=0;i<5000;i++) f[i] = -1;
        cout<<func(s,n-1)<<"\n";
    }
    return 0;
}
