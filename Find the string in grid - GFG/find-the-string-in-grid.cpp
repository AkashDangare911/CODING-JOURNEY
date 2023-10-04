//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    bool search(vector<vector<char>> grid, string word,int i,int j,int n,int m,int a,int b)
    {
        int ind=0;
        int s = word.size();
        
         while(ind<s)
        {
            if(i<0 || j<0 || i>=n || j>=m || word[ind]!=grid[i][j])
                return false;
            
            i+=a;
            j+=b;
            ind++;
        }
        
        return true;
    }
    
    bool checkWord(vector<vector<char>> &grid, string word,int i,int j,int n,int m)
    {
                    // R L U B-UR UL DR DL
        int arr1[] = {0,0,-1,1,-1,-1,1,1};
        int arr2[] = {1,-1,0,0,1,-1,1,-1};
        
        
        for(int i1=0;i1<8;i1++)
        {
            bool ans = search(grid,word,i,j,n,m,arr1[i1],arr2[i1]);
            if(ans)
                return true;
        }
        
        return false;
    }
    
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word)
	{
	    vector<vector<int>> ans;
	    int n = grid.size();
	    int m = grid[0].size();
	    char start = word[0];
	    
	    
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(grid[i][j]==start)
	            {
	                bool res = checkWord(grid,word,i,j,n,m);
	                if(res)
	                    ans.push_back({i,j});
	            }
	        }
	    }
	    
	    return ans;
	}
};
    
    


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends