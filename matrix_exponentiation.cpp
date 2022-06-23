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

class Matrix {
public:
    vector<vector<int>>v;

    Matrix(){}

    Matrix(int n) {
        v.assign(n,vector<int>(n,0));
    }

    Matrix operator*(const Matrix &o) const {
        Matrix res(sz(v));

        for(int i=0;i<sz(v);i++) {
            for(int j=0;j<sz(v);j++) {
                for(int k=0;k<sz(v);k++) {
                    res.v[i][j] = (res.v[i][j]+v[i][k]*o.v[k][j])%mod;
                }
            }
        }

        return res;
    }
};

int binpow(int a,int b) {
    int res = 1;
    while(b) {
        if(b&1) res = res*a%mod;
        b >>= 1;
        a = a*a%mod;
    }

    return res;
}

int divide(int a,int b) {
    return a*binpow(b,mod-2)%mod;
}

Matrix matrix_pow(Matrix a,int b) {
    Matrix res(sz(a.v));
    for(int i=0;i<sz(a.v);i++) res.v[i][i] = 1;
    while(b) {
        if(b&1) res = res*a;
        b >>= 1;
        a = a*a;
    }
    return res;
}

bool valid(int x) {
    int cnt = 0;
    for(int i=0;i<61;i++) {
        if(x&(1LL<<i)) cnt++;
    }

    if(cnt%3) return false;
    return true;
}

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    cin>>a;

    Matrix p(n);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            p.v[i][j] = valid(a[i]^a[j]);
        }
    }

    p = matrix_pow(p,k-1);

    int ans = 0;

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            ans = (ans+p.v[i][j])%mod;
        }
    }

    cout<<ans<<enl;
} 

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int testcases = 1;
    //cin>>testcases;
    while(testcases--) solve();
    return 0;
}