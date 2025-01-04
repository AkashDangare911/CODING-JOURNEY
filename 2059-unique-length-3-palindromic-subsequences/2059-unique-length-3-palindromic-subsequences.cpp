class Solution {
    private:
    int countSubsequences(string s, char c, int l, int r)
    {
        unordered_set<char> st;
        int ans=0;
        
        while(l<r)
        {
            if(!st.count(s[l])){
                ans++;
            }
            st.insert(s[l]);
            l++;
        }
        return ans;
    }
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char,int> first, second;
        int ans=0, n = s.size();

        // find leftmost & rightmost indexes of chars
        for(int i=0;i<n;i++)
        {
            char c=s[i];
            // the char has already occured, so now update it's rightmost index
            if(first.count(c)){
                second[c]=i;
            }
            // first occurence of current char 'c'
            else{
                first[c]=i;
            }
        }

        for(pair<char,int> p: first)
        {
            // char has freq > 1
            if(second.count(p.first)){
                ans+=countSubsequences(s,p.first,p.second+1,second[p.first]);
            }
        }

        return ans;
    }
};