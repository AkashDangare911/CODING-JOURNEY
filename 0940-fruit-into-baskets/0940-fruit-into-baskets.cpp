class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int left=0, right=0;
        int ans=0;
        unordered_map<int,int> mp;

        while(right<n)
        {
            mp[fruits[right]]++;

            // keep the window size same
            if(mp.size()>2)
            {
                int leftEle=fruits[left];
                mp[leftEle]--;
                if(mp[leftEle]==0)
                    mp.erase(leftEle);
                
                left++;
            }

            if(mp.size()<=2)
                ans=max(ans,right-left+1);

            right++;
        }

        return ans;
    }
};