#include<bits/stdc++.h>
using namespace std;
#define int long long

int solve() {
	int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &a:arr) cin>>a;
    int mx=-1;
    vector<int> chk(n);
    int ans=0;
    for(int i=0;i<n;i++){
        mx=max(mx,arr[i]);
        chk[i]=mx;
    }
    //for(auto a:chk) cout<<a<<" ";
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1] && chk[i]==arr[i]) ans++;
    }
    if(arr[n-1]>arr[n-2] && arr[n-1]==chk[n-1]) ans++;
    return ans;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int t; 
    cin >> t;
	for(int i=1;i<=t;i++) {
		cout << "Case #" << i << ": " << solve() << '\n';
	}
	return 0;
}