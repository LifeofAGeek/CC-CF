#include<bits/stdc++.h>
using namespace std;

int main()
{
    int s,w1,w2,w3;
    cin>>s>>w1>>w2>>w3;
    int sum1=w1+w2+w3, sum2=w1+w2, sum3=w3+w2;
    if(s>=sum1) cout<<"No. of hits required is:"<<1;
    else if(s>=sum2 || s>=sum3) cout<<"No. of hits required is:"<<2;
    else cout<<"No. of hits required is:"<<3;
}
