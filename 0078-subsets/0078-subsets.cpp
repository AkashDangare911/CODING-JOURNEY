class Solution {
private:
    void generateSubsets(int i, int n, vector<int> temp, vector<int>& nums, vector<vector<int>> &ans)
    {
        // we are collecting all the combinatins forming at the end node
        // of recursive tree, hence only add to 'ans', when at last index
        if(i>=n)
        {
            ans.push_back(temp);
            return;
        }

        // not-take
        generateSubsets(i+1,n,temp,nums,ans);
        
        // take
        temp.push_back(nums[i]);
        generateSubsets(i+1,n,temp,nums,ans);
        temp.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        generateSubsets(0,nums.size(),{},nums,ans);

        return ans;
    }
};