class Solution {
private:
    bool isPalindrome(string &s)
    {
        int i=0, j=s.size()-1;
        while(i<j)
        {
            if(s[i]!=s[j])
                return false;
            i++,j--;
        }
        return true;
    }
public:
    string longestPalindrome(string s) {
        string ans="";
        int n=s.size();

        for(int i=0;i<n;i++)
        {
            string str="";
            for(int j=i;j<n;j++)
            {
                str.push_back(s[j]);
                if(isPalindrome(str) && str.size()>ans.size())
                    ans=str;
            }
        }
        return ans;
    }
};