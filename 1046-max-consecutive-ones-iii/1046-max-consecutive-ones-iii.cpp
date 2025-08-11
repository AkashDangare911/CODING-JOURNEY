class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans=0;
        int left=0, right=0;
        int n=nums.size();

        while(right<n)
        {
            if(nums[right]==0)
            {
               if(k)
                {
                    k--;
                }
                else
                {
                    while(left<right && nums[left])
                    {
                        left++;
                    }
                    left++;
                }
            }
            ans=max(ans,right-left+1);
            right++;
        }

        return ans;
    }
};