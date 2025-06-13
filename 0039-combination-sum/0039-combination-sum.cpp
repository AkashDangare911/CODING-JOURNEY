class Solution {
private:
    void findCombinations(vector<int> &arr, int i, int sum, int target,vector<int> temp, vector<vector<int>> &ans)
    {
        // check if we have required sum, as we now has traversed whole array
        if(i==arr.size())
        {
            if(sum==target)
                ans.push_back(temp);
            return;
        }

        // always false condition
        if(sum>target)
            return;

        // not-take
        findCombinations(arr,i+1,sum,target,temp,ans);

        // take
        sum+=arr[i];
        temp.push_back(arr[i]);
        findCombinations(arr,i,sum,target,temp,ans);
        temp.pop_back();
        sum-=arr[i];
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int index=0, cur=0;

        findCombinations(candidates,index,cur,target,temp,ans);

        return ans;
    }
};