class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0, right=nums.size()-1;
        int ans=INT_MAX;

        while(left<=right)
        {
            int mid = (left+right)/2;
            
            // array between left and right pointers is completely sorted and our ans would be nums[left]
            if(nums[left]<=nums[right])
            {
                ans=min(ans,nums[left]);
                break;
            }
            
            // LEFT SORTED PART
            // we consider the leftmost element of sorted part as minimum
            // hence check it only and neglect the rest of the sorted part
            if(nums[left] <= nums[mid])
            {
                ans=min(ans,nums[left]);
                left=mid+1;
            }
            else
            {
                ans=min(ans,nums[mid]);
                right=mid-1;
            }
        }

       return ans;
    }
};