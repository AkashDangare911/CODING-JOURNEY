class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int mx=INT_MIN;
        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            int diff = abs(nums[i]-nums[(i+1)%n]);
            mx=max(mx,diff);
        }

        return mx;
    }
};