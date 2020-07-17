#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define rep(i, a, b) for(ll i = a; i < b; ++i)
#define debug(x) cout << #x << '=' << x << '\n'
#define pfll(x) printf("%lld\n", x)
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

// variables
ll n, k;
ll h[200005], c[200005], ngr[200005], ngre[200005], ngl[200005], ngle[200005], prer[200005], prel[200005], segr[800005], segl[800005],
lsegr[800005], lsegl[800005];

void fastscan(ll &number) 
{ 
    bool negative = false; 
    register int c; 
  
    number = 0; 

    c = getchar(); 
    if (c=='-') 
    { 

        negative = true; 
        c = getchar(); 
    } 
    for (; (c>47 && c<58); c=getchar()) 
        number = number *10 + c - 48; 
  
    if (negative) 
        number *= -1; 
} 

void ngrc(){
    stack<pair<ll,ll>> stk;
    stk.push({h[0], 0LL});
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

void update(ll i, ll start, ll end, ll l, ll r, ll x, ll seg[], ll lseg[]) {
    if(lseg[i] != 0) {
        seg[i] += lseg[i];
        if(start != end) {
            lseg[2*i+1] += lseg[i];
            lseg[2*i+2] += lseg[i];
        }
        lseg[i] = 0;
    }

    if(r < start or l > end or start > end) return ;
    if(l <= start and end <= r) {
        seg[i] += x;
        if(start != end) {
            lseg[2 * i + 1] += x;
            lseg[2 * i + 2] += x;
        }
        return;
    }
    ll mid = (start + end) / 2;
    update(2 * i + 1, start, mid, l, r, x, seg, lseg);
    update(2 * i + 2, mid+1, end, l, r, x, seg, lseg);
}

ll query(ll i, ll start, ll end, ll x, ll seg[], ll lseg[]) {
    if(lseg[i] != 0) {
        seg[i] += lseg[i];
        if(start != end) {
            lseg[2*i+1] += lseg[i];
            lseg[2*i+2] += lseg[i];
        }
        lseg[i] = 0;
    }
    if(start == end and start == x) return seg[i];
    ll mid = (start + end)/2;
    if(start <= x and x <= mid) {
        return query(2 * i + 1, start, mid, x, seg, lseg);
    }
    return query(2 * i + 2, mid + 1, end, x, seg, lseg);
}

int main()
{
	FIO;
    fastscan(n);
    fastscan(k);
    rep(i, 0, n) fastscan(h[i]);
    rep(i, 0, n) fastscan(c[i]);
    ngrc();
    nglc();
    ngrec();
    nglec();
    calc();
    
    rep(i, 0, k) {
        ll x, y, z;
        fastscan(x);
        fastscan(y);
        fastscan(z);
        if(x == 1) {
            y--;
            ll diff = z - c[y];
            update(0, 0, n-1, y, (ngre[y] == -1 ? n-1 : ngre[y] - 1), diff, segl, lsegl);
            update(0, 0, n-1,(ngle[y] == -1 ? 0 : ngle[y] + 1), y, diff, segr, lsegr);
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
                    else if(ngl[y] == -1) cout << prel[z] + query(0, 0, n-1, z, segl, lsegl) << '\n';
                    else cout << prel[z] - prel[ngl[y]] + query(0, 0, n-1, z, segl, lsegl) - query(0, 0, n-1, ngl[y], segl, lsegl) << '\n';
                }
                else {
                    if(ngle[y] > z && ngle[y] < y) cout << "-1\n";
                    else if(ngr[y] == -1) cout << prer[z] + query(0, 0, n-1,z, segr, lsegr) << '\n';
                    else cout << prer[z] - prer[ngr[y]] + query(0, 0, n-1,z, segr, lsegr) - query(0, 0, n-1,ngr[y], segr, lsegr) << '\n';
                }
            }
        }
    }
	return 0;
}