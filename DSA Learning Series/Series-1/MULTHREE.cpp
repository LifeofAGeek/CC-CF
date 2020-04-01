#include <bits/stdc++.h> 

using namespace std; 

  
// Function to check the divisibility 

string check(long int k, int d0, int d1) 
{  

  

    // Cycle 

    long int s = (2 * (d0 + d1)) % 10 +  

                 (4 * (d0 + d1)) % 10 +  

                 (8 * (d0 + d1)) % 10 +  

                 (6 * (d0 + d1)) % 10; 

      

    // no of residual terms 

    int a = (k - 3) % 4; 

      

    // sum of residual terms 

    int x; 

      

    switch(a) 

    { 

      

        // if no of residue term = 0 

        case 0: 

      

        x = 0; 

        break; 

      

        // if no of residue term = 1 

        case 1: 

      

        x = (2 * (d0 + d1)) % 10; 

        break;  

  

        // if no of residue term = 2 

        case 2: 

      

        x = (2 * (d0 + d1)) % 10 +  

            (4 * (d0 + d1)) % 10; 

        break; 

      

        // if no of residue term = 3 

        case 3: 

      

        x = (2 * (d0 + d1)) % 10 + 

            (4 * (d0 + d1)) % 10 +  

            (8 * (d0 + d1)) % 10; 

          

        break; 

    } 

      

    // sum of all digits 

    long int sum = d0 + d1 + ((k - 3) / 4) * s + x; 

      

    // divisibility check 

    if(sum % 3 == 0) 

        return "YES"; 

    return "NO"; 
} 

int main()
{
    long int t, k, d0, d1;
    cin>>t;
    while (t--)
    {
        cin>>k>>d0>>d1;
        cout<<check(k,d0,d1)<<endl;
    }
    return 0;
}