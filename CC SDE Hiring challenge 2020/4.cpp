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

const int N = 2e5+1;

int dist[N];
int level[N];
int LCA[N][25];
vector<int> adj1[N];
vector<pair<int, int>> adj[N];

void dfs(int node, int par, int lvl)
{
	level[node] = lvl;
	LCA[node][0] = par;
	for(int child : adj1[node])
	{
		if(child != par)
		{
			dfs(child, node, lvl+1);
		}
	}
}

void init(int n, int r)
{
	dfs(r, -1, 0);

	for(int j = 1; j < 24; j++)
	{
		for(int i = 1; i <= n; i++)
		{
			if(LCA[i][j-1] != -1)
			{
				int par = LCA[i][j-1];
				LCA[i][j] = LCA[par][j-1];
			}
		}
	}
}

int getLCA(int a, int b)
{
	if(level[a] > level[b]) swap(a, b);
	int diff = level[b] - level[a];

	while(diff>0)
	{
		int i = log2(diff);
		diff -= (1 << i);
		b = LCA[b][i];
	}

	if(a == b) return a;

	for(int i = 24 ; i >=0 ; i--)
	{
		if(LCA[a][i] !=-1 && LCA[a][i] != LCA[b][i])
		{
			a = LCA[a][i];
			b = LCA[b][i];
		} 
	}
	return LCA[a][0];
} 

void solve(){
	int n, q, r;
	cin >> n >> q >> r;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j < 24; j++)
		{
			LCA[i][j] = -1;
		}
	}
	for(int i = 1; i <= n; i++)
	{
		adj1[i].clear();
		adj[i].clear();

	}

	for(int i = 0; i < n-1; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj1[u].push_back(v);
		adj1[v].push_back(u);
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});

	}
	init(n, r);
	for(int i = 1; i <= n; i++)
	{
		dist[i] = 1e10;
	}
	dist[r] = 0;
	queue<int> qe;
	qe.push(r);
	while(!qe.empty())
	{
		int top = qe.front();
		qe.pop();
		for(auto it : adj[top])
		{
				if(dist[it.first] == 1e10)
			{
				dist[it.first] = dist[top] + it.second;
				qe.push(it.first);
			}
		}
	}
	
	for(int i = 0; i < q; i++)
	{
		int u, v;
		cin >> u >> v;
		int lca =  getLCA(u, v);
		cout << dist[u] +  dist[v] - 2 * dist[lca] << '\n';

	}
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
	int t;
	cin >> t;
	while(t--)
	{
		solve();	
	}
}
