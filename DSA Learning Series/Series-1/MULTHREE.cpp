#include<bits/stdc++.h>
#include<string>
using namespace std;

int main()
{
    int t, k, d0, d1;
    cin>>t;
    while (t--)
    {
        cin>>k;
        cin>>d0;
        cin>>d1;
        int sum=d0+d1,num;
        long ans=d0*pow(10,--k) + d1*pow(10,--k);
        while (k)
        {
            num=sum%10;
            sum+=num;
            ans=ans+num*pow(10,--k);
        }
        cout<<ans<<endl;
        if(ans%3==0) cout<<"YES";
        else cout<<"NO";
    }
}