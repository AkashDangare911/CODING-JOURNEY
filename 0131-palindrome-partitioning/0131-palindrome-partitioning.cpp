class Solution {
private:

    bool isPal(string &s,int st,int e)
    {
        while(st<e)
        {
            if(s[st++] != s[e--])
                return false;
        }
        return true;
    }

    void solve(string s,int index,vector<string> &temp,vector<vector<string>> &ans,int n)
    {
        if(index==n){
            ans.push_back(temp);
            return;
        }

        // at each index, check if i to index is a palindrome or not
        // if is palindrome, make a cut and check whether rest of the parts also make palindromes
        for(int i=index;i<n;i++)
        {
            if(isPal(s,index,i))
            {
                temp.push_back(s.substr(index,i-index+1));
                solve(s,i+1,temp,ans,n);
                temp.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;

        solve(s,0,temp,ans,s.size());

        return ans;
    }
};