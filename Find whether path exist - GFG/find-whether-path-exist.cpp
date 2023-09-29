//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    private:
    bool findIfExists(int i,int j,int n,int m,vector<vector<int>>& grid,vector<vector<bool>>& visited)
    {
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==0)
            return false;
            
        if(visited[i][j]==true)
            return false;
            
        if(grid[i][j]==2)
            return true;
            
        visited[i][j]=true;
        
        bool l = findIfExists(i,j+1,n,m,grid,visited);
        bool r = findIfExists(i,j-1,n,m,grid,visited);
        bool u = findIfExists(i+1,j,n,m,grid,visited);
        bool d = findIfExists(i-1,j,n,m,grid,visited);
        
        return l || r || u || d;
    }
    
    public:
    bool is_Possible(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                    return findIfExists(i,j,n,m,grid,visited);
            }
        }
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends