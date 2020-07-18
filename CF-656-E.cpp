#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define vec(x) vector<x>
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define umpii unordered_map<int,int>
#define matrix(x) vector<vector<x>>
#define all(v) v.begin(),v.end()
#define mem(a,b) memset(a, b, sizeof a)
#define setBits(n) __builtin_popcountll(n)
#define prec(n) fixed<<setprecision(n)
#define ff first
#define ss second
#define print(x) for(auto it:x) cout<<it<<" ";
#define dbg(x) cerr<<#x<<" :: "<<x<<endl;
#define dbg2(x,y) cerr<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
const int INF = 1e9;
const int MOD = 1e9 + 7; 
const double pi = acos(-1);
int power(int a,int b,int m=MOD)
{int ans=1;while(b>0){if(b&1)ans=((ans%m)*(a%m))%m;
a=((a%m)*(a%m))%m;b>>=1;}return ans;}
int dir[]={-1, 0, 1, 0, -1};
int dx[]={1,1,0,-1,-1,-1, 0, 1};
int dy[]={0,1,1, 1, 0,-1,-1,-1};

vi topoSortBFS(matrix(int) adj)
{
    int i,n=adj.size();
    vector<int> inDeg(n,0);
    queue<int> q;
	vi order;
    for(i=0;i<n;i++)
    {
        for(auto it:adj[i])
            inDeg[it]++;
    }
    for(i=0;i<n;i++)
    {
        if(!inDeg[i])
            q.push(i);
    }
    while(!q.empty())
    {
        int u=q.front();q.pop();
        order.pb(u);
        for(auto v:adj[u])
        {
            inDeg[v]--;
            if(inDeg[v]==0)
            q.push(v);
        }
    }
	return order;
}

void solve()
{
	int i,n,m;
    cin>>n>>m;
	matrix(int) adj(n);
	vii edges;
    for(i=0;i<m;i++)
    {
        int t,x,y;
        cin>>t>>x>>y;x--;y--;
		edges.pb({x,y});
		if(t==1)
        adj[x].pb(y);
    }
    vi order=topoSortBFS(adj);
	if(order.size()<n)
	{
		cout<<"NO"<<endl;
		return;
	}
	cout<<"YES"<<endl;
	vi idx(n,-1);
	for(i=0;i<n;i++)
		idx[order[i]]=i;
	for(auto e:edges)
	{
		if(idx[e.ff]>idx[e.ss])
		swap(e.ff,e.ss);
		cout<<e.ff+1<<" "<<e.ss+1<<endl;
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	t=1;
	cin>>t;
	while(t--)
		solve();
}
