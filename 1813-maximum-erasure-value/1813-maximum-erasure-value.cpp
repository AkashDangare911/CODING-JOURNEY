class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> mp;
        int i=0,j=0;
        int ans=0,sum=0;

        while(j<nums.size())
        {
            mp[nums[j]]++;
            sum+=nums[j];

            while(i<j && mp[nums[j]]>1)
            {
                sum-=nums[i];
                mp[nums[i]]--;
                i++;
            }

            ans=max(ans,sum);
            j++;
        }

        return ans;
    }
};