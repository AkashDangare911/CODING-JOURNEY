class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int left=0, right=0;
        int ans=0; int k=1;

        while(right<n)
        {
            if(nums[right]==0)
                k--;

            while(left<right && k<0)
            {
                if(nums[left]==0)
                    k++;
                left++;
            }

            ans=max(ans,right-left+1);
            right++;
        }

        return ans-1;
    }
};