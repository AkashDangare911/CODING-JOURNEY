//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    string colName (long long int n)
    {
        string ans="";
        
        while(n>0)
        {
            n=n-1;
            int q=n%26;
            //cout<<q<<endl;
            char c='A'+q;
            
            ans=c+ans;
            n = n/26;
        }
        
       
       // ans = (char)('A'+n-1)+ans;
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}

// } Driver Code Ends