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

template<int MOD = 998'244'353>
struct Mint {
    int val;
    Mint(long long v = 0) { if (v < 0) v = v % MOD + MOD; if (v >= MOD) v %= MOD; val = v; }
    static int mod_inv(int a, int m = MOD) {
        int g = m, r = a, x = 0, y = 1, q;
        while (r != 0) q = g / r, g %= r, swap(g, r), x -= q * y, swap(x, y);
        return x < 0 ? x + m : x;
    } 
    explicit operator int() const { return val; }
    explicit operator bool()const { return val; }
    Mint& operator+=(const Mint &o) { val += o.val; if (val >= MOD) val -= MOD; return *this; }
    Mint& operator-=(const Mint &o) { val -= o.val; if (val < 0) val += MOD; return *this; }
    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
           #if !defined(_WIN32) || defined(_WIN64)
                return x % m;
           #endif
           unsigned x_high = x >> 32, x_low = (unsigned) x; unsigned quot, rem;
           asm("divl %4\n": "=a" (quot), "=d" (rem): "d" (x_high), "a" (x_low), "r" (m));
           return rem;
    }
    Mint& operator*=(const Mint &other) { val = fast_mod((uint64_t) val * other.val); return *this; }
    Mint& operator/=(const Mint &other) { return *this *= other.inv(); }
    friend Mint operator+(const Mint &a, const Mint &b) { return Mint(a) += b; }
    friend Mint operator-(const Mint &a, const Mint &b) { return Mint(a) -= b; }
    friend Mint operator*(const Mint &a, const Mint &b) { return Mint(a) *= b; }
    friend Mint operator/(const Mint &a, const Mint &b) { return Mint(a) /= b; }
    Mint& operator++() { val=val==MOD-1?0:val+1; return *this; }
    Mint& operator--() { val=val==0?MOD-1:val-1; return *this; }
    Mint operator++(int32_t) { Mint before = *this; ++*this; return before; }
    Mint operator--(int32_t) { Mint before = *this; --*this; return before; }
    Mint operator-() const { return val == 0 ? 0 : MOD - val; }
    bool operator==(const Mint &other) const { return val == other.val; }
    bool operator!=(const Mint &other) const { return val != other.val; }
    Mint inv() const { return mod_inv(val); }
    Mint operator[](long long p) {
        assert(p >= 0);
        Mint a = *this, res = 1;
        while (p > 0) { if (p & 1) res *= a; a *= a, p >>= 1; }
        return res;
    }
    friend ostream& operator << (ostream &stream, const Mint &m) { return stream << m.val; }
    friend istream& operator >> (istream &stream, Mint &m) { return stream>>m.val; } 
};
using mint = Mint<>;

struct Combo {
    vector<mint>fact,invfact;

    Combo() {}

    Combo(int n) {
        fact.resize(n);
        invfact.resize(n);
        fact[0] = invfact[0] = 1;
        for(int i=1;i<n;i++) {
            fact[i] = fact[i-1]*i;
            invfact[i] = mint(fact[i]).inv();
        }
    }

    mint binpow(mint a,int b) {
        if(b<0) return 0;
        mint res = 1;
        while(b>0) {
            if(b & 1) res = res*a;
            a = a*a;
            b>>=1;
        }
        return res;
    }
    
    mint binomial(int n,int r) {
        if(n<0 or r<0 or n<r) return 0;
        return fact[n]*invfact[r]*invfact[n-r];
    }

};

const int root = 15311432;
const int root_1 = 469870224;
const int root_pw = 1 << 23;

void fft(vector<mint> & a, bool invert) {
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
        mint wlen = invert ? root_1 : root;
        for (int i = len; i < root_pw; i <<= 1)
            wlen = (int)(1LL * wlen * wlen);

        for (int i = 0; i < n; i += len) {
            mint w = 1;
            for (int j = 0; j < len / 2; j++) {
                mint u = a[i+j], v = (int)(1LL * a[i+j+len/2] * w );
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w = (int)(1LL * w * wlen);
            }
        }
    }

    if (invert) {
        mint n_1 = mint(n).inv();
        for (mint & x : a)
            x = (int)(1LL * x * n_1 );
    }
}

vector<mint> multiply(vector<mint> const& a, vector<mint> const& b) {
    vector<mint>fa = a, fb = b;
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] = fa[i]*fb[i];
    fft(fa, true);

    return fa;
}

vector<mint> func(vector<mint>a,vector<mint>b) {
    int n = sz(a);
    reverse(all(a));
    for(int i=0;i<n;i++) a.push_back(mint(0));
    for(int i=0;i<n;i++) b.push_back(b[i]);
    vector<mint>c = multiply(a,b);
    vector<mint>res;
    for(int i=n-1;i<2*n-1;i++) res.push_back(c[i]);
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);  
    
    int n,k;
    cin>>n>>k;
    k++;
    vector<mint>a(n),ans(n);
    vector<int>p(n);
    cin>>a>>p;

    vector<vector<mint>>per(n+1);

    Combo ncr(k+1);

    vector<mint>ncr_val(k);

    for(int i=0;i<k;i++) {
        ncr_val[i] = ncr.binomial(k-1,i);
    }

    vector<bool>vis(n);
    vector<mint>nodes;

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
                per[sz(nodes)][i%sz(nodes)] = per[sz(nodes)][i%sz(nodes)]+ncr_val[i];
            }
        }
        
        vector<mint>tmp;
        for(auto u:nodes) tmp.push_back(a[u.val]);
        vector<mint>res = func(per[sz(nodes)],tmp);
        for(int i=0;i<sz(nodes);i++) {
            ans[nodes[i].val] = res[i];
        }
    }

    for(int i=0;i<n;i++) {
        cout<<ans[i]<<' ';
    }    

    return 0;
}