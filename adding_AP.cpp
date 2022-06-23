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

const long long mod = 998244353;
const long long inf = 1e18;

class SegTree {
public:
    vector<int>tree;
    vector<pair<int,int>>lazy;

    SegTree(){}

    SegTree(int n) {
        tree.resize(4*n);
        lazy.resize(4*n);
    } 

    int term(int a,int d,int n) {
        return a+(n-1)*d;
    }

    int sum(int a,int d,int n) {
        return (2*a+(n-1)*d)*n/2;
    }

    void update(int l,int r,int a,int d,int st,int en,int node) {
        int mid = (st+en)/2;
        if(st != en) {
            tree[2*node] += sum(lazy[node].first,lazy[node].second,mid-st+1);
            tree[2*node+1] += sum(term(lazy[node].first,lazy[node].second,mid-st+2),lazy[node].second,en-mid);
            lazy[2*node].first += lazy[node].first;
            lazy[2*node+1].first += term(lazy[node].first,lazy[node].second,mid-st+2);
            lazy[2*node].second += lazy[node].second;
            lazy[2*node+1].second += lazy[node].second;
            lazy[node] = {0,0};
        }

        if(st > r or en < l) return;
        if(st >= l and en <= r) {
            tree[node] += sum(term(a,d,st-l+1),d,en-st+1);
            lazy[node] = {term(a,d,st-l+1),d};
            return;
        }

        update(l,r,a,d,st,mid,2*node);
        update(l,r,a,d,mid+1,en,2*node+1);
        tree[node] = (tree[2*node] + tree[2*node+1])%mod;
    }

    int query(int l,int r,int st,int en,int node) {
        int mid = (st+en)/2;
        if(st != en) {
            tree[2*node] += sum(lazy[node].first,lazy[node].second,mid-st+1);
            tree[2*node+1] += sum(term(lazy[node].first,lazy[node].second,mid-st+2),lazy[node].second,en-mid);
            lazy[2*node].first += lazy[node].first;
            lazy[2*node+1].first += term(lazy[node].first,lazy[node].second,mid-st+2);
            lazy[2*node].second += lazy[node].second;
            lazy[2*node+1].second += lazy[node].second;
            lazy[node] = {0,0};
        }

        if(st > r or en < l) return 0;
        if(st >= l and en <= r) return tree[node];
        return query(l,r,st,mid,2*node)+query(l,r,mid+1,en,2*node+1);
    }
};

void solve() {
    int n,q;
    cin>>n>>q;
    vector<int>a(n),pre(n);
    cin>>a;
    pre[0] = a[0];
    for(int i=1;i<n;i++) pre[i] = (pre[i-1] + a[i])%mod;
    for(int i=1;i<n;i++) (pre[i] += pre[i-1])%=mod;
    SegTree tr(n);
    for(int i=0;i<n;i++) {
        tr.update(i,i,pre[i],0,0,n-1,1);
    }
    
    while(q--) {
        int t,x,v;
        cin>>t>>x;
        if(t == 1) {
            cin>>v;
            tr.update(x-1,n-1,v-a[x-1],v-a[x-1],0,n-1,1);
            a[x-1] = v;
        }
        else {
            cout<<(tr.query(0,x-1,0,n-1,1)+mod)%mod<<enl;
        }
    }
} 

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int testcases = 1;
    //cin>>testcases;
    while(testcases--) solve();
    return 0;
}