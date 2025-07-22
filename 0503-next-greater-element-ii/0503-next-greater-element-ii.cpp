class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,-1);
        stack<int> st;         
        int i=2*n-1;

        // use i%n to find hypothetical index
        while(i>=0)
        {
            // remove all smaller elements
            while(!st.empty() && st.top()<=nums[i%n])
                st.pop();

            if(!st.empty() && i<n)
                ans[i]=st.top();

            st.push(nums[i%n]);
            i--;
        }

        return ans;
    }
};