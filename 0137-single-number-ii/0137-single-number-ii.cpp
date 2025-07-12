class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        long mul=1;

        for(int i=0;i<32;i++)
        {
            // count all bits at i'th position
            // the bits should be in multiple of 3s, 
            // if not it is because the unique no. is contrubuting to it, so add to our ans
            int one=0, zero=0;
            for(int n:nums)
            {
                if(n & (1<<i))
                    one++;
            }

            if(one%3)
                ans+=mul;
            
            mul*=2;
        }

        return ans;
    }
};