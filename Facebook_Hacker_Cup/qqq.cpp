#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod  (int)(1e9+7)
#define inf  (int)(1e18)
#define sz(s) (int)s.size()
#define all(v) (v).begin(),(v).end()
#define fill(dp) memset(dp,-1,sizeof(dp))
#define input(v) for (auto &i : v) cin >> i;
#define print(v) for (auto &j : v) cout << j << " "; cout << "\n"; 

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;               // i i+1 i+2
    while(true) {
        n = sz(s);
        for(int i=0;i<10;i++) {
            string tmp;
            while(!s.empty()) {
                if(s.back()-'0'==(i+1)%10) {
                    s.pop_back();
                    if(s.empty() or s.back()-'0'!=i) {
                        tmp.push_back('0'+(i+1)%10);
                        continue;
                    }
                    s.pop_back();
                    tmp.push_back('0'+((i+2)%10));
                }
                else {
                    tmp.push_back(s.back());
                    s.pop_back();
                }
            }
            reverse(all(tmp));
            s = tmp;
        }
        if(n==sz(s)) break;
    }
    cout<<s<<"\n";

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
/*
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
*/
    int testcases=1;
    cin>>testcases;
    for(int i=1;i<=testcases;i++) {
        cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}