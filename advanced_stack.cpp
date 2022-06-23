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

struct Stack {
    deque<int>s,smax,smin;
 
    void Push(int x) {
        s.push_back(x);
        while(!smax.empty() and smax.front()<x) smax.pop_front();
        while(!smax.empty() and smax.back()<x) smax.pop_back();
        smax.push_back(x);
        while(!smin.empty() and smin.front()>x) smin.pop_front();
        while(!smin.empty() and smin.back()>x) smin.pop_back();
        smin.push_back(x);
    }
 
    void Pop() {
        if(smax.front()==s.front()) smax.pop_front();
        if(smin.front()==s.front()) smin.pop_front();
        s.pop_front();
    }
 
    int query_max() {
        return smax.front();
    }

    int query_min() {
        return smin.front();
    }

    void clear() {
        while(!s.empty()) s.pop_front();
        while(!smin.empty()) smin.pop_front();
        while(!smax.empty()) smax.pop_front();
    }

    int size() {
        return (int)s.size();
    }
};

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    cin>>a;

    int ans = 0;

    Stack s;

    for(const auto &u:a) {
        s.Push(u);
        while(s.query_max() - s.query_min() > k) s.Pop();
        ans += sz(s.s);
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