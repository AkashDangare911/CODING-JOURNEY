class Solution {
public:
    bool checkOnesSegment(string s) {
        int n=s.size();
        int i=0;
        bool found=false;

        while(i<n)
        {
            if(found && s[i]=='1')
                return false;

            if(s[i]=='1')
            {
                found=true;
                while(i<n && s[i]=='1')
                    i++;
            }
            i++;
        }
        return true;
    }
};