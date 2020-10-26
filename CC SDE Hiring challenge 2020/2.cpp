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

int helper(int arr[], int N, int K) 
{ 
    sort(arr, arr + N); 
  
    int res = INT_MAX; 

    for (int i = 0; i <= (N - K); i++) 
    { 
        int curSeqDiff = arr[i + K - 1] - arr[i]; 
        res = min(res, curSeqDiff); 
    } 
  
    return res; 
}

void solve(){
    //code goes here
    int n,k;
    cin>>n>>k;
    int arr[n];
    loop(i,0,n) cin>>arr[i];
    cout<<helper(arr,n,k)<<endl;
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