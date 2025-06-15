class Solution {
private:
    void findCombinations(int sum, int cur, int k, int target, vector<int> &temp, vector<vector<int>> &ans)
    {
        if(cur==10)
        {
            if(sum==target && temp.size()==k)
                ans.push_back(temp);
            
            return;
        }

        // do not satisfy required conditions, do not calculate further
        if(sum>target || temp.size()>k)
            return;
        findCombinations(sum,cur+1,k,target,temp,ans);

        sum+=cur;
        temp.push_back(cur);
        findCombinations(sum,cur+1,k,target,temp,ans);
        temp.pop_back();
        sum-=cur;
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
       vector<vector<int>> ans;
       int sum=0;
       int num=1;
       vector<int> temp;

       findCombinations(sum,num,k,n,temp,ans); 

       return ans;
    }
};