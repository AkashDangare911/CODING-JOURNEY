class Solution {
    void solve(vector<int> nums, int ind, int cur,int &ans, int OR)
    {
        if(ind>=nums.size())
            return;
        
        int temp = cur|nums[ind];
        // cur = cur|nums[ind];
        if(temp==OR)
            ans++;
        
        solve(nums,ind+1,temp,ans,OR);   //include
        solve(nums,ind+1,cur,ans,OR);
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int OR=0;
        int ans=0;
        for(int i:nums)
            OR= OR|i;

        //arr,ind,curInd,ans,or
        solve(nums,0,0,ans,OR);
        return ans;
    }
};