class Solution {
public:
    long long minimumSteps(string s) {
        long long ans=0;
        int n = s.size();
        int i=n-1;
        int count=0;
        while(i>=0 && s[i]=='1')
        {
            count++;
            i--;
        }

       while(i>=0)
        {
            if(s[i]=='1')
            {
                ans+=((n-1-i)-count);
                count++;
            }
            i--;
        }

        return ans;
    }
};