class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int small = INT_MAX, smallest = INT_MAX;
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] <= smallest)
            {
                small = smallest;
                smallest = nums[i];
            }
            else if(nums[i]<small)
            {
                small=nums[i];
            }
        }

        return nums[0] + small + smallest;
    }
};