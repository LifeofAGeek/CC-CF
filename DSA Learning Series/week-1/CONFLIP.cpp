#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, G, I, N, Q;
    cin>>t;
    while(t--)
    {
        cin>>G;
        while(G--)
        {
            cin>>I;
            cin>>N;
            cin>>Q;
            if(N%2==0)
            {
                cout<<N/2<<endl;
            }
            else
            {
                if(I==1)
                {
                    if(Q==1) cout<<N/2<<endl;
                    else cout<<(N/2)+1<<endl;
                }
                else
                {
                    if(Q==1) cout<<(N/2)+1<<endl;
                    else cout<<(N/2)<<endl;
                }
                
            }
            
        }
    }
}