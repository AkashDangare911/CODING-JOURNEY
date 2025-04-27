class Solution {
public:
    bool rotateString(string s, string goal) {
        int g=goal.size(), n=s.size();

        // base case
        if(g != n)
            return false;

        for(int i=0;i<n;i++)
        {
            if(s.substr(i,g)==goal){
                return true;
            }
            s.push_back(s[i]);
        }

        return false;
    }
};