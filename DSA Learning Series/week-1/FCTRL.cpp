#include<bits/stdc++.h>
using namespace std;

int findTrailingZeros(int n) 
{ 
    // Initialize result 
    int count = 0; 
    while(n>=5)
    {
        n=n/5;
        count+=n;
    }
  
    return count; 
} 

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<findTrailingZeros(n)<<endl;
    }
}