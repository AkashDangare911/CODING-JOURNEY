//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    void changeGrid(int i,int j,int n,int m, vector<vector<int>> &grid)
    {
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==0)
            return;
            
        grid[i][j]=0;
        
        changeGrid(i,j+1,n,m,grid);
        changeGrid(i,j-1,n,m,grid);
        changeGrid(i+1,j,n,m,grid);
        changeGrid(i-1,j,n,m,grid);
    }
    
    
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n=grid.size();
        int m = grid[0].size();
        int ans=0;
        
        
        // change first row
        for(int i=0;i<m;i++)
        {
            if(grid[0][i]==1)
                changeGrid(0,i,n,m,grid);
        }
        
        // change first col
        for(int i=0;i<n;i++)
        {
            if(grid[i][0]==1)
                changeGrid(i,0,n,m,grid);
        }
        
        // // change last row
        for(int i=0;i<m;i++)
        {
            if(grid[n-1][i]==1)
                changeGrid(n-1,i,n,m,grid);
        }
        
        // // change last col
        for(int i=0;i<n;i++)
        {
            if(grid[i][m-1]==1)
                changeGrid(i,m-1,n,m,grid);
        }
        
        // check remaining area of islands
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                    ans++;
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends