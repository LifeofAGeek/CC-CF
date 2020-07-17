#include <bits/stdc++.h>
#define int long long
using namespace std;
#define debug(x) cout << #x << '=' << x << '\n'
int N,Q;
vector<int> h(200005);
vector<int> taste(200005);
vector<int> RNG(200005), RNGE(200005), LNG(200005), LNGE(200005), PSR(200005), PSL(200005);
int LST[800005], RST[800005], lazyLST[800005], lazyRST[800005];

void print(vector<int> arr)
{
    for (int i=0;i<N;i++)
        cout << arr[i] << " ";
    cout << endl;
}


void rightcalc1(){
    stack<pair<int,int>> s;
    s.push({h[0], 0LL});
    for(int it = 1; it < N; it++) {
        while(!s.empty() && h[it] > s.top().first) {
            RNG[s.top().second] = it;
            s.pop();
        }
        s.push({h[it], it});
    }

    while(!s.empty()) {
        RNG[s.top().second] = -1;
        s.pop();
    }
}

void rightcalc2(){
    stack<pair<int,int>> s;
    s.push({h[0], 0LL});
    for(int it = 1; it < N; it++) {
        while(!s.empty() && h[it] >= s.top().first) {
            RNGE[s.top().second] = it;
            s.pop(); 
        }
        s.push({h[it], it});
    }

    while(!s.empty()) {
        RNGE[s.top().second] = -1;
        s.pop();
    }
}

void leftcalc1(){
    stack<pair<int,int>> s;
    s.push({h[N-1], N-1});
    for(int it = N-2; it >= 0; it--) {
        while(!s.empty() && h[it] > s.top().first) {
            LNG[s.top().second] = it;
            s.pop(); 
        }
        s.push({h[it], it});
    }

    while(!s.empty()) {
        LNG[s.top().second] = -1;
        s.pop();
    }
}

void leftcalc2(){
    stack<pair<int,int>> s;
    s.push({h[N-1], N-1});
    for(int it = N-2; it >= 0; it--) {
        while(!s.empty() && h[it] >= s.top().first) {
            LNGE[s.top().second] = it;
            s.pop(); 
        }
        s.push({h[it], it});
    }

    while(!s.empty()) {
        LNGE[s.top().second] = -1;
        s.pop();
    }
}

void preSum() {
    for(int it = N-1; it >= 0; --it) {
        if(RNG[it] != -1) PSR[it] += PSR[RNG[it]] + taste[it];
        else PSR[it] = taste[it];
    }
    for(int it = 0; it < N; ++it) {
        if(LNG[it] != -1) PSL[it] += PSL[LNG[it]] + taste[it];
        else PSL[it] = taste[it];
    }
}

void helper(int it, int s, int e, int low, int high, int x, int sgtr[], int lzysegtr[]) {
    if(lzysegtr[it] != 0) {
        sgtr[it] += lzysegtr[it];
        if(s!=e) {
            lzysegtr[2*it+1] += lzysegtr[it];
            lzysegtr[2*it+2] += lzysegtr[it];
        }
        lzysegtr[it] = 0;
    }

    if(high < s || low > e || s > e) return ;
    if(low <= s && e <= high) {
        sgtr[it]+=x;
        if(s!=e) {
            lzysegtr[2*it+1]+=x;
            lzysegtr[2*it+2]+=x;
        }
        return;
    }
    int m = (s+e)/2;
    helper(2*it+1,s,m,low,high,x,sgtr,lzysegtr);
    helper(2*it+2,m+1,e,low,high,x,sgtr,lzysegtr);
}

int handler(int it, int s, int e, int x, int sgtr[], int lzysegtr[]) {
    if(lzysegtr[it] != 0) {
        sgtr[it] += lzysegtr[it];
        if(s != e) {
            lzysegtr[2*it+1] += lzysegtr[it];
            lzysegtr[2*it+2] += lzysegtr[it];
        }
        lzysegtr[it] = 0;
    }
    if(s == e && s == x) return sgtr[it];
    int m = (s+e)/2;
    if(s <= x and x <= m) {
        return handler(2*it+1,s,m,x,sgtr,lzysegtr);
    }
    return handler(2*it+2,m+1,e,x,sgtr,lzysegtr);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>N>>Q;
    for(int i=0;i<N;i++){
        cin>>h[i];
    }
	for(int i=0;i<N;i++){
        cin>>taste[i];
    }

    // print(h);
    // print(taste);

    rightcalc1();
    leftcalc1();
    rightcalc2();
    leftcalc2();
    preSum();
    
    while(Q--) {
        int type, b, c;
        cin >> type >> b >> c;
        if(type == 1) {
            b--;
            int dif = c - taste[b];
            helper(0, 0, N-1, b, (RNGE[b] == -1 ? N-1 : RNGE[b] - 1), dif, LST, lazyLST);
            helper(0, 0, N-1,(LNGE[b] == -1 ? 0 : LNGE[b] + 1), b, dif, RST, lazyRST);
            taste[b] = c;
        }
        else {
            b--, c--;
            if(b == c) {
                cout<<taste[b]<<endl;
            }
            else if(h[b] <= h[c]) {
                cout<<-1<<endl;
            }
            else {
                if(b < c) {
                    if(RNGE[b] < c && RNGE[b] > b) cout<<-1<<endl;
                    else if(LNG[b] == -1) cout<<PSL[c]+handler(0, 0, N-1, c, LST, lazyLST)<<endl;
                    else cout<<PSL[c]-PSL[LNG[b]]+handler(0, 0, N-1, c, LST, lazyLST)-handler(0, 0, N-1, LNG[b], LST, lazyLST)<<endl;
                }
                else {
                    if(LNGE[b] > c && LNGE[b] < b) cout<<-1<<endl;
                    else if(RNG[b] == -1) cout<<PSR[c]+handler(0, 0, N-1, c, RST, lazyRST)<<endl;
                    else cout<<PSR[c]-PSR[RNG[b]]+handler(0, 0, N-1, c, RST, lazyRST)-handler(0, 0, N-1, RNG[b], RST, lazyRST)<<endl;
                }
            }
        }
    }
	return 0;
}
