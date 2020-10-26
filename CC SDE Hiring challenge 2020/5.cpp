#include<bits/stdc++.h>
using namespace std;
#define int long long
#define loop(i, start, end) for (int i = start; i < end; i++)
#define rloop(i, start, end) for (int i = start; i >= end; i--)
#define all(v) (v).begin(),(v).end()
#define arl(v) (v).rbegin(),(v).rend()
#define fsp(a) fixed<<setprecision(a)
#define mem(a,with) memset(a, with, sizeof (a))
#define vmn(a) (*min_element(a.begin(),a.end()))   
#define vmx(a) (*max_element(a.begin(),a.end()))
#define bs(a,key) binary_search(all(a),key)    /// return bool.
#define rotl(a,x) rotate(a.begin(),a.begin()+x,a.end());
#define rotr(a,x) rotl(a,a.size()-x);
#define nl cout<<endl

void solve(){
    //code goes here
    int n;
    cin>>n;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = 0, root = 0;

    function<void(int, int, int)> dfs = [&](int u, int p, int d) -> void {
        if (ans < d) {
            root = u;
            ans = d;
        }
        for (int v : g[u]) {
            if (v == p) {
                continue;
            }
            dfs(v, u, d + 1);
        }
    };

    dfs(0, -1, 0);
    dfs(root, -1, 0);
    cout << ((ans + 1) >> 1) << '\n';
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
ios_base::sync_with_stdio(false);
cout.tie(NULL);
cin.tie(NULL);
    int t=1;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}
