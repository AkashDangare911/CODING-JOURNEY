//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    bool checkIsland(vector<vector<int>>& matrix,int i,int j, int n, int m)
    {
        if(i<0 || i>=n || j<0 || j>=m)
            return false;
            
        if(matrix[i][j]==0 || matrix[i][j]==2)
            return true;
            
        matrix[i][j]=2;
        
        bool right = checkIsland(matrix,i,j+1,n,m);
        bool left = checkIsland(matrix,i,j-1,n,m);
        bool up = checkIsland(matrix,i-1,j,n,m);
        bool down = checkIsland(matrix,i+1,j,n,m);
        
        return right && left && up && down;
    }
    
    int closedIslands(vector<vector<int>>& matrix, int n, int m) {
        int ans=0;
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(matrix[i][j]==1)
                {
                    if( checkIsland(matrix,i,j,n,m) )
                    {
                        ans++;
                    }
                }
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends