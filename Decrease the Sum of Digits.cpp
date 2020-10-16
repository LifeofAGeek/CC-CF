#include<bits/stdc++.h>
using namespace std;
#define int long long
#define loop(i, start, end) for (int i = start; i < end; i++)
#define rloop(i, start, end) for (int i = start; i >= end; i--)

void solve(){
    //code goes here
    int n,s;
    cin>>n>>s;

    function<int(int)> digitSum=[&](int dig)-> int{
        int sum=0;
        while(dig>0){
            sum+=(dig%10);
            dig/=10;
        }
        return sum;
    };

    if(digitSum(n)<=s){
        cout<<0<<endl;
        return;
    }

    int w=1, ans=0;
    int len=log10(n)+1;
    loop(i,0,len){
        int dig=(n/w)%10;
        int add=w*(10-dig);
        ans+=add;
        n+=add;
        if(digitSum(n)<=s){
            break;
        }
        w*=10;
    }
    cout<<ans<<endl;
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
