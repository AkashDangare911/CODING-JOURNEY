class Solution {
private:
    bool isDigit(int c)
    {
        if(c>=0 && c<=9)
            return true;
        return false;
    }
public:
    string clearDigits(string s) {
        stack<char> st;
        string ans="";

        for(char c: s)
        {
            if(st.empty())
                st.push(c);
            else
            {
                if(isDigit(c-'0'))
                    st.pop();
                else    
                    st.push(c);
            }
        }

        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};