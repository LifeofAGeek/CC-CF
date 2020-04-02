#include<bits/stdc++.h>
using namespace std;

int digitSum(int a,int d0, int d1) 
{ 
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
    return x;
} 

string multipleOfThree(long long int K,  int dig0,  int dig1) 
{ 
      
    // sum of digits 
    long int sum = 0; 
  
    // store the sum of first two digits 
    // modulo 10 in a temporary variable 
    int temp = (dig0 + dig1) % 10; 
  
    sum = dig0 + dig1; 
  
    // if the number N is a two digit number 
    if (K == 2) { 
        if (sum % 3 == 0) 
            return "YES"; 
        else
            return "NO"; 
    } 
  
    // add temp to sum to get the sum 
    // of first three digits which are 
    // not a part of cycle 
    sum += temp; 
  
    // get the number of groups in cycle 
    long numberofGroups = (K - 3) / 4; 
  
    // get the remaining number of digits 
    int remNumberofDigits = (K - 3) % 4; 
  
    // add sum of 20 for each group (2, 4, 8, 6) 
    sum += (numberofGroups * 20); 
  
    // find the remaining sum of remaining digits 
     int x=digitSum(remNumberofDigits,dig0,dig1);
     sum+=x;

    // check if it is divisible by 3 or not 
    if (sum % 3 == 0) 
        return "YES"; 
    else
        return "NO"; 
}
    
int main()
{
    int t,d0,d1;
    long long int k;
    cin>>t;
    while (t--)
    {
        cin>>k;
        cin>>d0;
        cin>>d1;
        cout<<multipleOfThree(k,d0,d1)<<endl;
    }
    
}