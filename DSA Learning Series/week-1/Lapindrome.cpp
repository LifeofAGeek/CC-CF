// C++ program Lapindrome
#include <bits/stdc++.h> 
using namespace std; 
const int MAX_CHAR = 26; 
 
string checkLapindrome(string s) 
{ 
	// Counter array inisialized with 0 
	int count1[MAX_CHAR] = {0}; 
	int count2[MAX_CHAR] = {0}; 

	// Length of the string 
	int n = s.length(); 
	if (n == 1) 
		return "YES"; 

	// traverse till the middle element 
	// is reached 
	for (int i=0,j=n-1; i<j; i++,j--) 
	{ 
		// First half 
		count1[s[i]-'a']++; 

		// Second half 
		count2[s[j]-'a']++; 
	} 

	// Checking if values are different 
	// set flag to 1 
	for (int i = 0; i<MAX_CHAR; i++) 
		if (count1[i] != count2[i]) 
			return "NO"; 

	return "YES"; 
} 

int main() 
{ 
	string s; 
    int t;
    cin>>t;
    while (t--)
    {
        cin>>s;
        cout<<checkLapindrome(s)<<endl;
    }
	return 0; 
} 
