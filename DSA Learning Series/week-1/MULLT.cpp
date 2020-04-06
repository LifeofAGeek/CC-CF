#include<bits/stdc++.h>
#include<string.h>
using namespace std;

int digitSum(string str, int n) 
{ 
    // Compute sum of digits 
    int digitSum = 0; 
    for (int i=0; i<n; i++) 
        digitSum += (str[i]-'0'); 
   
    return digitSum; 
} 

int main()
{
    long int t, k, d0, d1, sum,n;
    string nonRepeating,repeating;
    cin>>t;
    while (t--)
    {
        cin>>k>>d0>>d1;
        n=k;
        static int sum=d0+d1+(d0+d1)%10,num;
        repeating="";
        k=k-3;
        for(int i=1;i<=4;i++)
        {
            if(k>0)
            {
            num=sum%10;
            sum+=num;
            repeating+=to_string(num);
            k--;
            }
            else break;
        }
    }
    sum= d0 + d1 + ((d0+d1)%10) + 20*((n-3)/4) + digitSum(repeating,(n-3)%4);
    if(sum%3==0) cout<<"YES";
    else cout<<"NO";
    return 0;
}
