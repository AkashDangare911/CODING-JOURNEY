class Solution {
public:

    void solve(vector<int> nums,vector<int> &temp,int index,set<vector<int>> &ans)
    {
        if(index>=nums.size()){
            ans.insert(temp);
            return;
        }

        // exclude
        solve(nums,temp,index+1,ans);

        //include
        int element = nums[index];
        temp.push_back(element);
        solve(nums,temp,index+1,ans);
        temp.pop_back();
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> s;
        sort(nums.begin(),nums.end());
        vector<int> temp;
        int index=0;

        // recursive helper function
        solve(nums,temp,index,s);

        vector<vector<int>> ans;
        for(vector<int> v: s)
            ans.push_back(v);

        return ans;
    }
};