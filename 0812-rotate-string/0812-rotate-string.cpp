class Solution {
public:
    bool rotateString(string s, string goal) {
        int g=goal.size();

        // base case
        if(g != s.size())
            return false;

        s+=s;
        int n=s.size();

        for(int i=0;i<n;i++)
        {
            if(s[i] == goal[0]){
                if(s.substr(i,g) == goal)
                    return true;
            }
        }

        return false;
    }
};