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

struct Combo {
    vector<int>fact,invfact;

    Combo() {}

    Combo(int n) {
        fact.resize(n);
        invfact.resize(n);
        fact[0] = invfact[0] = 1;
        for(int i=1;i<n;i++) {
            fact[i] = fact[i-1]*i%mod;
            invfact[i] = binpow(fact[i],mod-2);
        }
    }

    int binpow(int a,int b) {
        if(b<0) return 0;
        int res = 1;
        while(b>0) {
            if(b & 1) res = res*a%mod;
            a = a*a%mod;
            b>>=1;
        }
        return res;
    }
    
    int binomial(int n,int r) {
        if(n<0 or r<0 or n<r) return 0;
        return fact[n]*invfact[r]%mod*invfact[n-r]%mod;
    }

};

const int root = 15311432;
const int root_1 = 469870224;
const int root_pw = 1 << 23;

int binpow(int a,int b) {
    int res = 1;
    while(b) {
        if(b&1) res = res*a%mod;
        b >>= 1;
        a = a*a%mod;
    }
    return res;
}

void fft(vector<int> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        int wlen = invert ? root_1 : root;
        for (int i = len; i < root_pw; i <<= 1)
            wlen = (int)(1LL * wlen * wlen % mod);

        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; j++) {
                int u = a[i+j], v = (int)(1LL * a[i+j+len/2] * w % mod);
                a[i+j] = u + v < mod ? u + v : u + v - mod;
                a[i+j+len/2] = u - v >= 0 ? u - v : u - v + mod;
                w = (int)(1LL * w * wlen % mod);
            }
        }
    }

    if (invert) {
        int n_1 = binpow(n, mod-2);
        for (int & x : a)
            x = (int)(1LL * x * n_1 % mod);
    }
}

vector<int> multiply(vector<int> const& a, vector<int> const& b) {
    vector<int>fa = a, fb = b;
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] = fa[i]*fb[i]%mod;
    fft(fa, true);

    return fa;
}

vector<int> func(vector<int>a,vector<int>b) {
    int n = sz(a);
    reverse(all(a));
    for(int i=0;i<n;i++) a.push_back(0);
    for(int i=0;i<n;i++) b.push_back(b[i]);
    vector<int>c = multiply(a,b);
    vector<int>res;
    for(int i=n-1;i<2*n-1;i++) res.push_back(c[i]%mod);
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);  
    
    int n,k;
    cin>>n>>k;
    k++;
    vector<int>a(n),p(n),ans(n);
    cin>>a>>p;

    vector<vector<int>>per(n+1);

    Combo ncr(k+1);

    vector<int>ncr_val(k);

    for(int i=0;i<k;i++) {
        ncr_val[i] = ncr.binomial(k-1,i);
    }

    vector<bool>vis(n);
    vector<int>nodes;

    function<void(int)>dfs = [&](int s) {
        if(vis[s]) return;
        vis[s] = true;
        nodes.push_back(s);
        dfs(p[s]-1);
    };
    
    for(int i=0;i<n;i++) {
        if(vis[i]) continue;
        nodes.clear();
        dfs(i);

        if(per[sz(nodes)].empty()) {
            per[sz(nodes)].resize(sz(nodes));
            for(int i=0;i<k;i++) {
                per[sz(nodes)][i%sz(nodes)] = (per[sz(nodes)][i%sz(nodes)]+ncr_val[i])%mod;
            }
        }
        
        vector<int>tmp;
        for(auto u:nodes) tmp.push_back(a[u]);
        vector<int>res = func(per[sz(nodes)],tmp);
        for(int i=0;i<sz(nodes);i++) {
            ans[nodes[i]] = res[i];
        }
    }

    for(int i=0;i<n;i++) {
        cout<<ans[i]<<' ';
    }    

    return 0;
}