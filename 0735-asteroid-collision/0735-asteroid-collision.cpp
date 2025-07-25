class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> st;
        int n=asteroids.size();

        for(int i=n-1;i>=0;i--)
        {
            int cur=asteroids[i];

            // push all negatives
            if(cur<0)
                st.push(cur);
                
            // for positive elements
            else
            {
                while(!st.empty() && st.top()<0 && abs(st.top())<cur)
                    st.pop();

                if(!st.empty())
                {
                    if(st.top()<0)
                    {
                        if(abs(st.top())==cur)
                            st.pop();
                    }
                    else
                        st.push(cur);
                }
                else
                    st.push(cur);
            }
        }

        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};