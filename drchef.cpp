#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define rep(i, a, b) for(ll i = a; i < b; ++i)
#define debug(x) cout << #x << '=' << x << '\n'
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main()
{
	FIO;
    ll t, ans, c, pos, y; cin >> t;
    while(t--) {
        ll n, x; cin >> n >> x;
        vll arr(n);
        for(ll& i : arr) cin >> i;

        sort(arr.begin(), arr.end());
        
        if(x >= arr[n-1]) {
            cout << n << '\n';
        }else {
            ll pos = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
            if(pos != 0) y = arr[pos-1];
            ans =  pos;
            c = pos - 1;
            for(ll i = pos; i < n; i++) {
                while(x < arr[i]) {
                    x <<= 1;
                    ans++;
                }
                ans++;
                x = arr[i] * 2;
            }
            if(pos) {
                for(ll i = pos; i < n; i++) {
                    while(y < arr[i]) {
                        y <<= 1;
                        c++;
                    }
                    c++;
                    y = arr[i] * 2;
                }
            }
            if(pos != 0) cout << min(ans, c) << '\n';
            else
            cout << ans << '\n';
        }
    }
	return 0;
}