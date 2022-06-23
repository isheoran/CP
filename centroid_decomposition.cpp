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

class Centroid_Decomposition {
    vector<int>sub_nodes;
    vector<bool>vis;
public:
    vector<vector<int>>centroid_tree,adj;
    int centroid_tree_root = -1;

    Centroid_Decomposition(){}

    Centroid_Decomposition(int n) {
        adj.resize(n+1);
        centroid_tree.resize(n+1);
        sub_nodes.resize(n+1);
        vis.resize(n+1);
    }

    void add_edge(int a,int b) {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    void dfs(int s,int p) {
        sub_nodes[s] = 1;

        for(auto u:adj[s]) {
            if(u == p or vis[u]) continue;
            dfs(u,s);
            sub_nodes[s] += sub_nodes[u];
        }
    }

    int find_centroid(int s,int p,int n) {
        int node = -1;
        for(auto u:adj[s]) {
            if(u != p and !vis[u] and sub_nodes[u] > n/2) {
                node = u;
            }
        }

        if(node == -1) return s;
        return find_centroid(node,s,n);
    }

    void build_centroid_tree(int root,int par) {
        dfs(root,-1);
        root = find_centroid(root,-1,sub_nodes[root]);
        vis[root] = true;
        
        if(par > 0) {
            centroid_tree[par].push_back(root);
            centroid_tree[root].push_back(par);
        }
        else centroid_tree_root = root;

        for(auto u:adj[root]) {
            if(vis[u]) continue;
            build_centroid_tree(u,root);
        }
    }
};

void solve() {
    int n,m;
    cin>>n>>m;

    Centroid_Decomposition CD(n);
    vector<int>level(n+1,0),parent(n+1,-1),ans(n+1,inf);
    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        CD.add_edge(u,v);
    }

    CD.build_centroid_tree(1,-1);

    vector<vector<int>>par(n+1,vector<int>(20,-1));
    function<void(int,int,int)>dfs = [&](int s,int p,int d) {
        par[s][0] = p;
        level[s] = d;
        for(auto u:CD.adj[s]) {
            if(u != p) dfs(u,s,d+1);
        }
    };

    dfs(1,-1,0);

    for(int j=1;j<20;j++) {
        for(int i=1;i<=n;i++) {
            if(par[i][j-1] != -1) {
                par[i][j] = par[par[i][j-1]][j-1];
            }
        }
    }

    auto find_distance = [&](int a,int b) {
        if(level[a] > level[b]) swap(a,b);

        int dist = level[b] - level[a];

        for(int i=0;i<20;i++) {
            if(dist&(1<<i)) {
                b = par[b][i];
            }
        }

        if(a == b) return dist;

        for(int i=19;i>=0;i--) {
            if(par[a][i] != par[b][i]) {
                a = par[a][i];
                b = par[b][i];
                dist += 2*(int)(1<<i);
            }
        }

        dist += 2;

        return dist;
    };

    function<void(int,int)>assign_centroid_tree_parent = [&](int s,int p) {
        parent[s] = p;
        for(auto u:CD.centroid_tree[s]) {
            if(u != p) assign_centroid_tree_parent(u,s);
        }
    };

    assign_centroid_tree_parent(CD.centroid_tree_root,-1);

    function<void(int,int)>update = [&](int s,int v) {
        if(s == -1) return;
        amin(ans[s],find_distance(s,v));
        update(parent[s],v);
    };

    function<int(int,int)>query = [&](int s,int v) {
        if(s == -1) return inf;
        return min(ans[s]+find_distance(s,v),query(parent[s],v));
    };

    update(1,1);

    while(m--) {
        int t,v;
        cin>>t>>v;
        if(t == 1) {
            update(v,v);
        }
        else {
            cout<<query(v,v)<<enl;
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