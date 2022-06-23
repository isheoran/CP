#include<bits/stdc++.h>
using namespace std;
const int INF=1e9+5;
int n,c,p,a[8];
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i=1; i<8; i++) a[i]=INF;
    while(n--){
        cin >> c >> s;
        p=0;
        for(auto x: s) p|=(1<<(x-65));
        for(int q=0; q<8; q++) a[p|q] = min(a[p|q],c+a[q]);
    }
    cout << (a[7]<INF ? a[7] : -1);
    return 0;
}