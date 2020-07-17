#include <bits/stdc++.h>
#define int long long
using namespace std;

int sum(int n){
    int sum;
    for (sum = 0; n > 0; sum += n % 10, n /= 10);
    return sum;
}

void solve()
{
    int n;
    cin >> n;
    int c=0, m=0;
    int chef=0,monty=0;
    while(n--){
        int a,b;
        cin>>a>>b;
        c=sum(a);
        m=sum(b);
        if(m>c) ++monty;
        else if(c>m) ++chef;
        else {
            ++monty; 
            ++chef;
        }
    }
    if(monty>chef){
        cout<<1<<" "<<monty<<endl;
    }
    else if(chef>monty) cout<<0<<" "<<chef<<endl;
    else cout<<2<<" "<<monty<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
