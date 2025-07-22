class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(), n2=nums2.size();
        unordered_map<int,int> mp;
        vector<int> ans(n1,-1);

        stack<int> st;
        vector<int> nge(n2,-1);

        // store indices of nums2--for later use
        for(int i=0;i<n2;i++)
            mp[nums2[i]]=i;
        
        // find nge for nums2
        for(int i=n2-1;i>=0;i--)
        {
            while(!st.empty() && st.top()<=nums2[i])
                st.pop();
                
            if(!st.empty())
                nge[i]=st.top();;

            st.push(nums2[i]);
        }

        // retrieve indices of elements from n1, and get corresponding nge elemen
        for(int i=0;i<n1;i++)
        {
            int ele = mp[nums1[i]];
            ans[i]=nge[ele];
        }
        
        return ans;
    }
};