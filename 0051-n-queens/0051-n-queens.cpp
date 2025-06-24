class Solution {
private:
    // check the left side of current row,
    // upper & lower diagonal on the left side
    // as we only placed queens on the left side of board
    bool isPossibleToPlaceQueen(vector<string> &board, int i, int j, int n)
    {
        int curI=i, curJ=j;

        // left row
        while(curJ>=0)
        {
            if(board[i][curJ]=='Q') return false;
            curJ--;
        }

        curJ=j;

        // upper diagonal
        while(curI>=0 && curJ>=0)
        {
            if(board[curI][curJ]=='Q')  return false;
            curI--,curJ--;
        }
        curI=i, curJ=j;

        // lower diagonal
        while(curI<n && curJ>=0)
        {
            if(board[curI][curJ]=='Q')  return false;
            curI++, curJ--;
        }

        return true;
    }

    void solve(vector<string> &board, int n, int cInd, vector<vector<string>> &ans)
    {
        // means we have placed all 'n' queens 
        if(cInd>=n)
        {
            ans.push_back(board);
            return;
        }
        
        for(int rInd=0;rInd<n;rInd++)
        {
            if(isPossibleToPlaceQueen(board,rInd,cInd,n))
            {
                board[rInd][cInd]='Q';
                solve(board,n,cInd+1,ans);
                board[rInd][cInd]='.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s(n,'.');
        vector<string> board(n,s);
        
        solve(board,n,0,ans);

        return ans;
    }
};