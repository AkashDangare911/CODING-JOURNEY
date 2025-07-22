class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(2*n,-1);
        stack<int> st;

        for(int i=0;i<n;i++)
            nums.push_back(nums[i]);
        
        n = nums.size();
        int i=n-1;

        // 1,2,3,4,3,1,2,3,4,3
        //    2 3 4-1 4 2 3 4-1-1

        while(i>=0)
        {
            if(st.empty())
            {
                st.push(nums[i]);
            }
            else
            {
                while(!st.empty() && st.top()<=nums[i])
                {
                    st.pop();
                }

                if(!st.empty())
                    ans[i]=st.top();

                st.push(nums[i]);
            }
            i--;
        }

        return {ans.begin(),ans.begin()+n/2};
    }
};