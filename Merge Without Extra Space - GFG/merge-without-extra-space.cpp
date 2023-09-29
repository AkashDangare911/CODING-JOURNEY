//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
        
        /*
        1. first array should contain all smaller element , while second must have all larger ones
        2. hence, count all larger elements and swap all wrongly placed elements in array2
        */
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            int count=0;
            int i=n-1,j=m-1;
            
            while(count<m && i>=0 && j>=0)
            {
                if(arr1[i] > arr2[j])
                {
                    i--;
                }
                else
                    j--;
                    
                count++;
            }
            
            i++;
            j=0;
            while(i<n && j<m)
            {
                swap(arr1[i++],arr2[j++]);
            }
            
            sort(arr1,arr1+n);
            sort(arr2,arr2+m);
        } 
};


//{ Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 

// } Driver Code Ends