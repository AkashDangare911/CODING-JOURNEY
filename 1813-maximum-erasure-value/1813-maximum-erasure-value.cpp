class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n=nums.size();
        int i=0,j=0, ans=0, sum=0;

        while(j<n)
        {
            int cur=nums[j];
            mp[cur]++;
            sum+=cur;

            while(i<j && mp[cur]>1)
            {
                sum-=nums[i];
                mp[nums[i]]--;
                i++;
            }
            j++;
            ans=max(ans,sum);
        }

        return ans;
    }
};