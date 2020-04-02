#include <iostream>
using namespace std;

int reverse(int num)
{
    int rev_num = 0; 
    while (num > 0) 
    { 
        rev_num = rev_num*10 + num%10; 
        num = num/10; 
    } 
    return rev_num;
}

int main() {
	long int n, t;
    cin>>t;
	while(t--)
	{
	    cin>>n;
	    cout<<reverse(n)<<endl;
	}
	return 0;
}
