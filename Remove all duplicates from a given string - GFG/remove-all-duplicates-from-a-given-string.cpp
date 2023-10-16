//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	string removeDuplicates(string str) {
	    int i=0,j=0;
	    int n=str.size();
	    int arr[256]={0};
	    
	    while(i<n)
	    {
	        char c = str[i];
	        arr[c]++;
	        
	        if(!(arr[c] > 1))
	            str[j++]=str[i];
	        
	        i++;
	    }
	    
	    return str.substr(0,j);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends