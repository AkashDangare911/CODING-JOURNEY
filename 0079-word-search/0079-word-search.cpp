class Solution {
private:
    bool searchWord(vector<vector<char>>& board, string &word, int i, int j, int cur)
    {
        if(cur==word.size())
            return true;

        // index out of matrix 
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size())
            return false;
        
        // di-simillar characters
        if(board[i][j] != word[cur])
            return false;
        
        // mark as visited
        board[i][j]='#';

        bool right = searchWord(board,word,i,j+1,cur+1);
        bool left = searchWord(board,word,i,j-1,cur+1);
        bool up = searchWord(board,word,i-1,j,cur+1);
        bool down = searchWord(board,word,i+1,j,cur+1);

        // backtrack from visited
        board[i][j]=word[cur];

        return right || left || up || down;
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        
        // discard if word length exceeds matrix size
        if(word.size() > m*n)
            return false;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(searchWord(board,word,i,j,0))
                    return true;
            }
        }

        return false;
    }
};