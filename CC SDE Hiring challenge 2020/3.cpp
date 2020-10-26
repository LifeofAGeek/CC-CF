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
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> source;
    vector<int> g[n];
    loop(i,0,m){
    	int u,v;
    	cin>>u>>v;
    	u--;v--;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }

    loop(i,0,k) {
    	int t;
    	cin>>t;
    	t--;
    	source.push_back(t);
    }

    int Q;
    cin>>Q;

    vector<int> dist(n,-1),vis(n,0);

    function<void()> multi_bfs=[&]()-> void{
    	queue<int> q;
    	loop(i,0,k){
    		q.push(source[i]);
    		vis[source[i]]=1;
    		dist[source[i]]=0;
    	}

    	while(!q.empty()){
    		int curr=q.front();
    		q.pop();

    		for(auto next:g[curr]){
    			if(!vis[next]){
    				vis[next]=1;
    				dist[next]=dist[curr]+1;
    				q.push(next);
    			}
    		}
    	}
    	return;
    };
    multi_bfs();

    while(Q--){
    	int at;
    	cin>>at;
    	at--;
    	cout<<dist[at]<<endl;
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
    int t=1;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}