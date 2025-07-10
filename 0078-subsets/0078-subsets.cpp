class Solution {
private:
    void checkSetBitsAndBuildCurrentArray(vector<int> &nums, int n, vector<vector<int>> &ans)
    {
        vector<int> cur;
        int ind=0;

        while(n)
        {
            if(n&1)  
                cur.push_back(nums[ind]);

            ind++;
            n=n>>1;
        }
        ans.push_back(cur);
    }

public:
    // USING BIT MANIPULATION
    // - traverse through all elements from 0 --> 2^n-1
    // - only place those indices in cur, whose bits are set in the current number
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;

        for(int i=0;i<pow(2,nums.size());i++)
            checkSetBitsAndBuildCurrentArray(nums,i,ans);

        return ans;
    }
};