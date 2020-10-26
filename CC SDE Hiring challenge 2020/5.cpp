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

int x; 
void dfsUtil(int node, int count, bool visited[], int& maxCount, list<int>* adj) 
{ 
    visited[node] = true; 
    count++; 
    for (auto i = adj[node].begin(); i != adj[node].end(); ++i) { 
        if (!visited[*i]) { 
            if (count >= maxCount) { 
                maxCount = count; 
                x = *i; 
            } 
            dfsUtil(*i, count, visited, maxCount, adj); 
        } 
    } 
} 


void dfs(int node, int n, list<int>* adj, int& maxCount) 
{ 
    bool visited[n + 1]; 
    int count = 0; 
    for (int i = 1; i <= n; ++i) 
        visited[i] = false; 
  
    dfsUtil(node, count + 1, visited, maxCount, adj); 
} 

int diameter(list<int>* adj, int n) 
{ 
    int maxCount = INT_MIN; 
  
    dfs(1, n, adj, maxCount); 

    dfs(x, n, adj, maxCount); 
  
    return maxCount; 
} 

void solve(){
    //code goes here
    int n;
    cin>>n;
    list<int>* adj= new list<int>[n+1];

    loop(i,0,n-1){
    	int u,v;
    	cin>>u>>v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }

    cout<<diameter(adj,n)/2<<endl;
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