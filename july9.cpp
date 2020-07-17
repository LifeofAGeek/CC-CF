#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define rep(i, a, b) for(ll i = a; i < b; ++i)
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

const ll mod = 998244353LL;

ll arr[26], t, p, n;
string s;
map<string, ll> mp, wt;

ll weight(string a) {
    ll w = 0LL;
    for(char c : a) {
        w += arr[c - 'a'];
    }
    return w;
}

bool possible(string a, string s) {
    for(ll i = 0; i < (ll)s.size(); i++) {
        if(s[i] != a[i % a.size()]) return false;
    }
    return true;
}

ll calc(string a) {
    ll v = 0LL;
    for(ll i = 1; i <= (ll)a.size(); i++) {
        if(possible(a.substr(0, i), a)) {
            v += wt[a.substr(0, i)];
        }
    }
    return v;
}

ll exgcd(ll a, ll b, ll *x, ll *y) 
{ 
    if (a == 0LL) 
    { 
        *x = 0LL, *y = 1LL; 
        return b; 
    } 
    ll x1, y1; 
    ll gcd = exgcd(b%a, a, &x1, &y1); 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
    return gcd; 
}

ll mi(ll a, ll m) {
    ll x, y; 
    ll g = exgcd(a, m, &x, &y); 
    return (x%m + m) % m;
}

int main()
{
	FIO;
    cin >> t;
    for(; t--; ) {
        cin >> s;
        rep(i, 0, 26) cin >> arr[i];
        for(ll i = 0; i <= (ll)s.size(); i++) {
            for(ll j = 1; j <= (ll)s.size() - i; j++) {
                if(mp.find(s.substr(i, j)) == mp.end()) {
                    wt[s.substr(i, j)] = weight(s.substr(i, j));
                }
                mp[s.substr(i, j)]++;
            }
        }

        p = 0LL;
        for(auto i : mp) {
            (p += calc(i.first) * i.second) %= mod;
        }
        n = (ll)s.size();
        cout << (p * mi((n * (n + 1))/2, mod)) % mod << '\n';

        // clear
        mp.clear();
        wt.clear();
        memset(arr, 0, sizeof(arr));
    }
	return 0;
}