class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans=0, zeros=0;
        int left=0, right=0;
        int n=nums.size();

        while(right<n)
        {
            if(nums[right]==0)
               zeros++;

            // if available k zeros have also consumed, 
            // keep the window size same, until any zeros at left pointer is occured
            if(zeros>k)
            {
                if(nums[left]==0)
                    zeros--;
                left++;
                
            }
            if(zeros<=k)
                ans=max(ans,right-left+1);
            right++;
        }

        return ans;
    }
};