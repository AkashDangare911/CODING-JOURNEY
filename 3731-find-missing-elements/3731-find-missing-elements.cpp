class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mn=INT_MAX, mx=INT_MIN;
        vector<int> arr(101), ans;

        for(int i:nums)
        {
            arr[i]=1;
            mn=min(mn,i);
            mx=max(mx,i);
        }

        for(int i=mn;i<=mx;i++)
        {
            if(arr[i]==0)
                ans.push_back(i);
        }

        return ans;
    }
};