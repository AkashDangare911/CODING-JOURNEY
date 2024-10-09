class Solution {
public:
    int minAddToMakeValid(string s) {
        int open=0,close=0;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==')'&& open==0)ans++;
            else if(s[i]=='(')open++;
            else if(s[i]==')')open--;
        }
        ans+=open;
        return ans;
    }
};
// ))))((((
// (((())))
// (()()()())