#include <bits/stdc++.h>
using namespace std;
#define  enl          '\n'
#define  int          long long
#define  sz(s)        (int)s.size()
#define  all(v)       (v).begin(),(v).end()

mt19937 rng (chrono::high_resolution_clock::now().time_since_epoch().count());
template <typename A, typename B> ostream& operator<< (ostream &cout, pair<A, B> const &p) { return cout << "(" << p.first << ", " << p.second << ")"; }
template <typename A, typename B> istream& operator>> (istream& cin, pair<A, B> &p) {cin >> p.first; return cin >> p.second;}
template <typename A> ostream& operator<< (ostream &cout, vector<A> const &v) {cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";}
template <typename A> istream& operator>> (istream& cin, vector<A> &x){for(int i = 0; i < x.size()-1; i++) cin >> x[i]; return cin >> x[x.size()-1];}
template <typename A, typename B> A amax (A &a, B b){ if (b > a) a = b ; return a; }
template <typename A, typename B> A amin (A &a, B b){ if (b < a) a = b ; return a; }

const long long mod = 1e9+7;
const long long inf = 1e18;

class SegTree {
    vector<int>tree,lazy;
public:
    SegTree(){}

    SegTree(int n) {
        tree.resize(4*n);
        lazy.resize(4*n);
    }

    void update(int l,int r,int st,int en,int node) {
        if(st != en) {
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
            tree[2*node] += lazy[node];
            tree[2*node+1] += lazy[node];
            lazy[node] = 0;
        }

        if(st > r or en < l) return;
        if(st >= l and en <= r) {
            tree[node]++;
            lazy[node]++;
            return;
        }
        int mid = (st+en)/2;
        update(l,r,st,mid,2*node);
        update(l,r,mid+1,en,2*node+1);
        tree[node] = min(tree[2*node],tree[2*node+1]);
    }

    int query(int l,int r,int st,int en,int node) {
        if(st != en) {
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
            tree[2*node] += lazy[node];
            tree[2*node+1] += lazy[node];
            lazy[node] = 0;
        }

        if(st > r or en < l) return inf;
        if(st >= l and en <= r) return tree[node];
        int mid = (st+en)/2;
        return min(query(l,r,st,mid,2*node),query(l,r,mid+1,en,2*node+1));
    }
};

void solve() {
    int k1,k2,k3;
    cin>>k1>>k2>>k3;
    vector<int>a(k1),b(k2),c(k3);
    cin>>a>>b>>c;

    int n = k1+k2+k3;
    vector<bool>vis(n);
    vector<int>pre(n);
    for(auto u:a) vis[u-1] = true;
    if(vis[0]) pre[0] = sz(a)-1;
    else pre[0] = sz(a)+1;
    for(int i=1;i<n;i++) {
        if(vis[i]) pre[i] = pre[i-1]-1;
        else pre[i] = pre[i-1]+1;
    }

    for(auto u:c) vis[u-1] = true;

    int ans = pre.back();
    
    SegTree tr(n+1);

    vector<bool>visc(n);
    for(auto u:c) visc[u-1] = true;
    
    for(int i=n-1;i>=0;i--) {
        amin(ans,pre[i]+tr.query(i+1,n,0,n,1));
        if(visc[i]) tr.update(i+1,n,0,n,1);
        if(!vis[i]) tr.update(0,i,0,n,1);
    }

    amin(ans,k1+tr.query(0,n,0,n,1));

    cout<<ans;
} 

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int testcases = 1;
    //cin>>testcases;
    while(testcases--) solve();
    return 0;
}