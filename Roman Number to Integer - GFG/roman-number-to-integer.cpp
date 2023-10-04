//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        unordered_map<char,int> mp;
        int ans=0;
        int n=str.size();
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        
        ans+=mp[str[n-1]];
        
        for(int i=n-2;i>=0;i--)
        {
            int a=mp[str[i]];   
            int b=mp[str[i+1]];  
            
            if(a < b)
            {
                ans-=a;
            }
            else
            {
                ans+=a;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends