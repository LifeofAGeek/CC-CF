#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define rep(i, a, b) for(ll i = a; i < b; ++i)
#define debug(x) cout << #x << '=' << x << '\n'
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

// variables
ll n, k;
vll h(200005), c(200005), ngr(200005), ngre(200005), ngl(200005), ngle(200005), prer(200005), prel(200005);

void ngrc(){
    stack<pair<ll,ll>> stk;
    stk.push({h[0], 0});
    for(ll i = 1; i < n; i++) {
        while(!stk.empty() && h[i] > stk.top().first) {
            ngr[stk.top().second] = i;
            stk.pop(); 
        }
        stk.push({h[i], i});
    }

    while(!stk.empty()) {
        ngr[stk.top().second] = -1;
        stk.pop();
    }
}

void ngrec(){
    stack<pair<ll,ll>> stk;
    stk.push({h[0], 0});
    for(ll i = 1; i < n; i++) {
        while(!stk.empty() && h[i] >= stk.top().first) {
            ngre[stk.top().second] = i;
            stk.pop(); 
        }
        stk.push({h[i], i});
    }

    while(!stk.empty()) {
        ngre[stk.top().second] = -1;
        stk.pop();
    }
}

void nglc(){
    stack<pair<ll,ll>> stk;
    stk.push({h[n-1], n-1});
    for(ll i = n-2; i >= 0; i--) {
        while(!stk.empty() && h[i] > stk.top().first) {
            ngl[stk.top().second] = i;
            stk.pop(); 
        }
        stk.push({h[i], i});
    }

    while(!stk.empty()) {
        ngl[stk.top().second] = -1;
        stk.pop();
    }
}

void nglec(){
    stack<pair<ll,ll>> stk;
    stk.push({h[n-1], n-1});
    for(ll i = n-2; i >= 0; i--) {
        while(!stk.empty() && h[i] >= stk.top().first) {
            ngle[stk.top().second] = i;
            stk.pop(); 
        }
        stk.push({h[i], i});
    }

    while(!stk.empty()) {
        ngle[stk.top().second] = -1;
        stk.pop();
    }
}

void calc() {
    for(ll i = n-1; i >= 0; --i) {
        if(ngr[i] != -1) prer[i] += prer[ngr[i]] + c[i];
        else prer[i] = c[i];
    }
    for(ll i = 0; i < n; ++i) {
        if(ngl[i] != -1) prel[i] += prel[ngl[i]] + c[i];
        else prel[i] = c[i];
    }
}

int main()
{
	FIO;
    cin >> n >> k;
    rep(i, 0, n) cin >> h[i];
    rep(i, 0, n) cin >> c[i];
    ngrc();
    nglc();
    ngrec();
    nglec();
    calc();
    
    rep(i, 0, k) {
        ll x, y, z;
        cin >> x >> y >> z;
        if(x == 1) {
            y--;
            ll diff = z - c[y];
            prer[y] += diff;
            prel[y] += diff;
            for(ll i = y-1; i >= 0 and i > ngle[y]; i--) 
                prer[i] += diff;
            for(ll i = y+1; i < n and i < (ngre[y] == -1 ? n : ngre[y]); i++)
                prel[i] += diff;
            c[y] = z;
            
        }else {
            y--, z--;
            if(y == z) {
                cout << c[y] << '\n';
            }
            else if(h[y] <= h[z]) {
                cout << "-1\n";
            }
            else {
                if(y < z) {
                    if(ngre[y] < z && ngre[y] > y) cout << "-1\n";
                    else if(ngl[y] == -1) cout << prel[z] << '\n';
                    else cout << prel[z] - prel[ngl[y]] << '\n';
                }
                else {
                    if(ngle[y] > z && ngle[y] < y) cout << "-1\n";
                    else if(ngr[y] == -1) cout << prer[z] << '\n';
                    else cout << prer[z] - prer[ngr[y]] << '\n';
                }
            }
        }
    }
	return 0;
}
