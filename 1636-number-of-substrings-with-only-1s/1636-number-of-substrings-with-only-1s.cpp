class Solution {
public:
    int numSub(string s) {
        int cur=1;
        int ans=0;
        int mod=1e9+7;

        for(char c:s)
        {
            if(c=='1')
            {
                ans+=cur;
                ans=ans%mod;
                cur++;
            }
            else
            {
                cur=1;
            }
        }

        return ans;
    }
};