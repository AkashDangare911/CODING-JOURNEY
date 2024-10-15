class Solution {
public:
    long long minimumSteps(string s) {
        long long ans=0;
        int n = s.size();
        int i=n-1, b_ind=n-1;

        while(i>=0)
        {
            if(s[i]=='1')
            {
                ans+=(b_ind-i);
                b_ind--;
            }
            i--;
        }

        return ans;
    }
};