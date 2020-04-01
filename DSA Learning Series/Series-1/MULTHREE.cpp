#include<bits/stdc++.h>
using namespace std;
#define MOD 10000000000007

long long fast_power(long long base, long long power) {
    long long result = 1;
    while(power > 0) {

        if(power % 2 == 1) { // Can also use (power & 1) to make code even faster
            result = (result*base) % MOD;
        }
        base = (base * base) % MOD;
        power = power / 2; // Can also use power >>= 1; to make code even faster
    }
    return result;
}

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
        long long ans=d0 * fast_power(10,--k)+ d1 * fast_power(10,--k);
        while (k)
        {
            num=sum%10;
            sum+=num;
            ans+=num*pow(10,--k);
        }
        if(ans%3==0) cout<<"YES";
        else cout<<"NO";
    }
}