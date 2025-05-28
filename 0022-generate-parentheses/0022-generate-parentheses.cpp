class Solution {
    void solve(int open, int closed, string temp, vector<string> &ans)
    {
        // all brackets exhausted, we have generated an ans
        if(!open && !closed){
            ans.push_back(temp);
            return;
        }

        // append open bracket first
        if(open){
            solve(open-1, closed, temp+'(', ans);
        }
        
        // if we have already appended more open brackets that closed brackets,
        // it will help to form we structured parantheses
        if(open < closed){
            solve(open,closed-1,temp+')',ans);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(n,n,"",ans);
        return ans;
    }
};