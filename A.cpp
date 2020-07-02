#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        ll ans;
        ans= n&1?((n+1)>>1):(n>>1);
        cout<<ans<<endl;
    }
}