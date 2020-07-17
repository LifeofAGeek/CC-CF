
#include <bits/stdc++.h>
#define int long long
using namespace std;


void solve()
{
    int n;
    cin>>n;
    int s[n];
    for(auto &a:s) cin>>a;
    int ans=0;
    for(int i=0;i<n-1;i++){
        ans+=(abs(s[i+1]-s[i])>1)?(abs(s[i+1]-s[i])-1):0;
        //cout<<i<<" "<<ans<<" ";
    }
    cout<<ans<<endl;
}

int32_t main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
        solve();
	}
	return 0;
}
