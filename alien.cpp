#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define rep(i, a, b) for(ll i = a; i < b; ++i)
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll solveHelper(vll arr, ll t) {
    ll cnt = 0;
    for(ll i = 1; i < arr.size(); i++) {
        if(arr[i] > arr[i-1]) {
            t++;
        } 
        if(arr[i] < arr[i-1]){
            t--;
        }
        if(t > 3) {
            t = 0;
            cnt++;
        }
        if(t < 0) {
            t = 3;
            cnt++;
        }
    }
    return cnt;
}

ll solve() {
	ll n; cin >> n;
	vector<ll> arr(n);
	for(ll& i : arr) cin >> i;
	ll ans = INT_MAX;
	for(ll i = 1; i <= 4; i++ ) {
	    ans = min(ans, solveHelper(arr, i-1));
	}
	return ans;
}

int main()
{
	FIO;
	ll t; cin >> t;
	for(ll i = 1; i <= t; i++) {
		cout << "Case #" << i << ": " << solve() << '\n';
	}
	return 0;
}