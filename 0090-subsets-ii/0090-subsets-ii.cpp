class Solution {
public:

    void solve(vector<int> nums,vector<int> &temp,int index,vector<vector<int>> &ans)
    {
        if(index>=nums.size()){
            ans.push_back(temp);
            return;
        }

        //include
        int element = nums[index];
        temp.push_back(element);
        solve(nums,temp,index+1,ans);
        temp.pop_back();

        // if we have already build ans considering the current element in recursion tree
        // then skip the further similar elements from the tree
        while(index+1<nums.size() && nums[index]==nums[index+1])
            index++;

         // exclude
        solve(nums,temp,index+1,ans);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        vector<int> temp;
        int index=0;

        // recursive helper function
        solve(nums,temp,index,ans);

        return ans;
    }
};